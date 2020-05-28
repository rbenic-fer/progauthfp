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

#define INRANGE(r, c) ((r) < R && (r) >= 0 && (c) < C && (c) >= 0)

int m[111][111];
const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int R, C;
		scanf("%d%d\n", &R, &C);

		FOR(r, R) {
			FOR(c, C) {
				char inp;
				scanf("%c", &inp);
				if (inp == '.')
					m[r][c] = -1;
				else if (inp == '^')
					m[r][c] = 2;
				else if (inp == '>')
					m[r][c] = 1;
				else if (inp == 'v')
					m[r][c] = 3;
				else if (inp == '<')
					m[r][c] = 0;
				else
					cerr << "FAIL" << endl;
			}
			scanf("\n");
		}

//		FOR(r, R) {
//			FOR(c, C)
//				cout << m[r][c];
//			cout << endl;
//		}

		bool possible = 1;
		int out = 0;
		FOR(r, R) {
			FOR(c, C) {
				if (m[r][c] == -1)
					continue;
				int dir = m[r][c];

				bool works = 0;
				for (int i = 1; INRANGE(r+i*dr[dir], c+i*dc[dir]); ++i)
					if (m[r+i*dr[dir]][c+i*dc[dir]] >= 0) {
						works = 1;
						break;
					}
				if (works)
					continue;

				possible = 0;
				for (dir = 0; dir < 4; ++dir) {
					works = 0;
					for (int i = 1; INRANGE(r+i*dr[dir], c+i*dc[dir]); ++i)
						if (m[r+i*dr[dir]][c+i*dc[dir]] >= 0) {
							works = 1;
							break;
						}
					if (works) {
						possible = 1;
						break;
					}
				}
				if (!possible)
					break;
				++out;
			}
			if (!possible)
				break;
		}

		if (possible)
			printf("Case #%d: %d\n", itr+1, out);
		else
			printf("Case #%d: IMPOSSIBLE\n", itr+1);
		fflush(stdout);
	}

	cerr << "time: " << getTime() - time << endl;
}
