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

int mem[111][4];
int R, C;

// 0 = just 2s
// 1 = just 3s
// 2 = 2s + 1s height 3 period 4
// 3 = 2s + 1s height 2 period 6

int dfs (int row, int prev) {
	if (row > R)
		return 0;
	if (row == R)
		return 1;
	if (mem[row][prev] != -1)
		return mem[row][prev];

	if (prev == 1) {
		int out = dfs(row+1, 0);
		if (C % 4 == 0)
			out += dfs(row+3, 2);
		if (C % 6 == 0)
			out += dfs(row+2, 3);
		return mem[row][prev] = out;
	}
	else
		return mem[row][prev] = dfs(row+2, 1);
}

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%d%d", &R, &C);

		FOR(i, 111)
			FOR(j, 4)
				mem[i][j] = -1;
		int out = dfs(1, 0) + dfs(2, 1);
		if (C % 4 == 0)
			out += dfs(3, 2);
		if (C % 6 == 0)
			out += dfs(2, 3);
		printf("Case #%d: %d\n", itr+1, out);
	}

	cerr << "time: " << getTime() - time << endl;
}
