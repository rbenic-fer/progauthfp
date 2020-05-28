#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second


void solve() {
  int n, p, a[10] = {};
  scanf("%d%d", &n, &p);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    a[x % p]++;
  }
  int ans = 0;
  if (p == 2) {
    ans = a[1] / 2 + a[1] % 2;
  } else if (p == 3) {
    int v[][3] = {
      {0, 1, 1}, // 1 2
      {0, 3, 0}, // 1 1 1
      {0, 0, 3} // 2 2 2
    };
    REP(i, 3) {
      int t = 100;
      REP(j, 3) if (v[i][j]) t = min(t, a[j] / v[i][j]);
      ans += t;
      REP(j, 3) a[j] -= v[i][j] * t;
    }
    if (a[1] || a[2]) ans += 1;
  } else {
    int v[][4] = {
      {0, 1, 0, 1}, // 1 3
      {0, 0, 2, 0}, // 2 2
      {0, 2, 1, 0}, // 1 1 2
      {0, 0, 1, 2}, // 3 3 2
      {0, 4, 0, 0}, // 1 1 1 1
      {0, 0, 0, 4} // 3 3 3 3
    };
    REP(i, 6) {
      int t = 100;
      REP(j, 4) if (v[i][j]) t = min(t, a[j] / v[i][j]);
      ans += t;
      REP(j, 4) a[j] -= v[i][j] * t;
    }
    if (a[1] || a[2] || a[3]) ans += 1;
  }
  printf("%d\n", a[0] + ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; ++kase) {
    printf("Case #%d: ", kase);
    solve();
  }
  return 0;
}

