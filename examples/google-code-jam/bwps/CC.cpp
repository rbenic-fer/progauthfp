#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, W, H, B;
int xborder, X0[1100], Y0[1100], X1[1100], Y1[1100];
bool vis[1100];

bool touch1D(int a1, int a2, int b1, int b2) {
  int a = max(a1 - 1, b1 - 1);
  int b = min(a2 + 1, b2 + 1);
  return a < b;
}

bool touch(int b1, int b2) {
  return
    touch1D(X0[b1], X1[b1], X0[b2], X1[b2]) &&
    touch1D(Y0[b1], Y1[b1], Y0[b2], Y1[b2]);
}

bool dfs(int b, int w) {
  if (X1[b] >= W-1 || (X1[b] >= w && Y0[b] <= 0)) return true;
  vis[b] = true;
  FOR(i, 0, B) {
    if (vis[i]) continue;
    if (touch(b, i) && dfs(i, w)) return true;
  }
  return false;
}

bool check(int w) {
  memset(vis, 0, sizeof(vis));
  FOR(i, 0, B) {
    if (X0[i] <= xborder || (X0[i] <= w && Y0[i] <= 0)) {
      if (!vis[i] && dfs(i, w)) return false;
    }
  }
  FOR(i, 0, B) {
    if (!vis[i]) continue;
    X0[i]--;
    Y0[i]--;
    X1[i]++;
    Y1[i]++;
  }
  return true;
}

int main() {
  cin >> T;
  FOR(cs, 1, T+1) {
    cin >> W >> H >> B;
    FOR(i, 0, B) cin >> X0[i] >> Y0[i] >> X1[i] >> Y1[i];
    int res = 0;
    xborder = 0;
    FOR(i, 0, W) {
      if (check(i)) {
        res++;
        xborder++;
      }
      //cout << i << ' ' << X0[0] << ' ' << X1[0] << ' ' << Y0[0] << Y1[0] << endl;
    }
    cout << "Case #" << cs << ": " << res << endl;
  }
	return 0;
}
