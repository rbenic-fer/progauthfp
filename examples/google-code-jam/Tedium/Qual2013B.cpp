#include <list>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ext/hash_map>
#include <stdint.h>
#include <ctime>
#include <queue>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef unsigned char BYTE;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, s, e) for (int i = (s); i <= (e); ++i)
#define FORD(i, s, e) for (int i = (s); i >= (e); --i)
#define ALL(x) x.begin(),x.end()
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define SIZE(x) ((int)x.size())
#define MP make_pair
#define PB push_back
#define BIT(x, b) (((x) >> (b)) & 1)
#define SWAP(a, b, t) do {t = a; a = b; b = t;} while (0);
#define INF 1000000000
#define EPS 1e-9
#define TIME_LEFT_UNTIL(end) ((curTime=getTime()-startTime) < (end))
#define TIME_LEFT() TIME_LEFT_UNTIL(MAX_TIME)
#define INIT_TIME() startTime = getTime()

inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

#define MAXN 111
#define MAXM 111

int N, M;
int lawn[MAXN][MAXM];

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%d%d", &N, &M);
		FOR(i, N)
			FOR(j, M)
				scanf("%d", &lawn[i][j]);

		string out = "YES";
		FORU(v, 1, 100) {
			FOR(i, N) {
				bool mowable = true, hasv = false;
				FOR(j, M) {
					if (lawn[i][j] > v)
						mowable = false;
					else if (lawn[i][j] == v)
						hasv = true;
				}
				if (mowable && hasv) {
					FOR(j, M)
						lawn[i][j] = 0;
				}
			}
			FOR(j, M) {
				bool mowable = true, hasv = false;
				FOR(i, N) {
					if (lawn[i][j] > v)
						mowable = false;
					else if (lawn[i][j] == v)
						hasv = true;
				}
				if (hasv) {
					if (mowable) {
						FOR(i, N)
							lawn[i][j] = 0;
					}
					else {
						out = "NO";
						break;
					}
				}
			}
		}

		printf("Case #%d: %s\n", itr+1, out.c_str());
	}
}
