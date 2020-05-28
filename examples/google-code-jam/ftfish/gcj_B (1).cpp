#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define debuging

#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif

#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif

#define rep(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,n) rep(i,0,(n))
#define SZ(x) (int)((x).size())
#define CLR(a) memset((a),0,sizeof (a))
#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define contains(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef set<int> sint;
typedef pair<int, int> pint;

const int maxint = -1u >> 2;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int mn = 105;
const int minint = -500;

inline int max_when_surprising(int x) {
	if (x < 2 || x > 28)
		return minint;
	return (x + 4) / 3;
}

inline int max_when_nonsurprising(int x) {
	return (x + 2) / 3;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int n, s, p, a[mn], surp[mn], nonsurp[mn], f[mn][mn] = { };
		scanf("%d%d%d", &n, &s, &p);

		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			surp[i] = max_when_surprising(a[i]);
			nonsurp[i] = max_when_nonsurprising(a[i]);
		}

		for (int i = 1; i <= s; ++i)
			f[0][i] = minint;
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			f[i][0] = f[i - 1][0] + (nonsurp[i] >= p);
			for (int j = 1; j <= s; ++j) {
				f[i][j] = max(f[i - 1][j] + (nonsurp[i] >= p),
						f[i - 1][j - 1] + (surp[i] >= p));
			}
		}

		printf("Case #%d: ", Tc);
		// output statement(s);
		printf("%d\n", f[n][s]);
	}
	return 0;
}
