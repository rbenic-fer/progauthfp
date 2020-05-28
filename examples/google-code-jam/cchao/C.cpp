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

const int inf = 1e9;

int dis[110][110][110][110];

queue<tuple<int, int, int, int>> q;
int ans;

void solve() {
  int hd, ad, hk, ak, b, d;
  scanf("%d%d%d%d%d%d", &hd, &ad, &hk, &ak, &b, &d);
  memset(dis, -1, sizeof dis);
  dis[hd][ad][hk][ak] = 0;
  q.push({hd, ad, hk, ak});
  ans = inf;
  while (q.size()) {
    int h, a, ht, at;
    tie(h, a, ht, at) = q.front(); q.pop();
    int od = dis[h][a][ht][at];
    { // attack
      int nht = max(0, ht - a);
      if (nht == 0) ans = min(ans, od + 1);
      else if (h > at) {
        int &tmp = dis[h - at][a][nht][at];
        if (tmp == -1) {
          tmp = od + 1;
          q.push({h - at, a, nht, at});
        }
      }
    }
    { // buff
      if (h > at) {
        int na = min(ht, a + b);
        int &tmp = dis[h - at][na][ht][at];
        if (tmp == -1) {
          tmp = od + 1;
          q.push({h - at, na, ht, at});
        }
      }
    }
    { // cure
      if (hd > at) {
        int &tmp = dis[hd - at][a][ht][at];
        if (tmp == -1) {
          tmp = od + 1;
          q.push({hd - at, a, ht, at});
        }
      }
    }
    { // debuff
      int nat = max(0, at - d);
      if (h > nat) {
        int &tmp = dis[h - nat][a][ht][nat];
        if (tmp == -1) {
          tmp = od + 1;
          q.push({h - nat, a, ht, nat});
        }
      }
    }
  }
  if (ans == inf) puts("IMPOSSIBLE");
  else printf("%d\n", ans);
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

