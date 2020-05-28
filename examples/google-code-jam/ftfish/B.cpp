#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define all(c) (c).begin(), (c).end() 
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

using namespace std;

const int inf = 1<<29;
int p;
int a[2048];

int f[11][2048][11];
int c[11][2048];

void init() {
    scanf("%d", &p);
    for (int i = 0; i < (1<<p); i++) {
        scanf("%d", &a[i]);
        for (int j = a[i] + 1; j <= p + 1; j++)
            f[0][i][j] = inf;
        for (int j = 0; j <= a[i]; j++)
            f[0][i][j] = 0;
    }
    int len = 1 << (p - 1);
    for (int i = 1; i <= p; i++) {
        for (int j = 0; j < len; j++)
            scanf ("%d", &c[i][j]);
        len /= 2;
    }
}

void Main() {
    int len = 1 << (p - 1);
    for (int i = 1; i <= p; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = p; k >= 0; k--) {
                f[i][j][k] = inf;
                if (k < p)
                    f[i][j][k] = f[i - 1][j * 2][k + 1] + f[i - 1][j * 2 + 1][k + 1];

                if (f[i][j][k] > f[i - 1][j * 2][k] + f[i - 1][j * 2 + 1][k] + c[i][j])
                    f[i][j][k] = f[i - 1][j * 2][k] + f[i - 1][j * 2 + 1][k] + c[i][j];
                if (k < p && f[i][j][k] > f[i][j][k + 1])
                    f[i][j][k] = f[i][j][k + 1];
                if (f[i][j][k] > inf)
                    f[i][j][k] = inf;
            }
        }
        len = len / 2;
    }
}

int main() {
//    freopen("B-small-attempt0.in", "r", stdin);
  //  freopen("B-small-attempt0.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    int Tn;
    scanf("%d", &Tn);
    for (int T = 1; T <= Tn; T++) {
        init();
        Main();
        printf ( "Case #%d: %d\n", T, f[p][0][0]);
    }
}
