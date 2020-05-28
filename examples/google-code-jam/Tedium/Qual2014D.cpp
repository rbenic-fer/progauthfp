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

int N;
double naomi[1111];
double ken[1111];

int dwar () {
	int ni = 0;
	FOR(ki, N) {
		while (ni < N && naomi[ni] < ken[ki])
			++ni;
		if (ni == N)
			return ki;
		++ni;
	}
	return N;
}

int war () {
	int ki = 0;
	FOR(ni, N) {
		while (ki < N && ken[ki] < naomi[ni])
			++ki;
		if (ki == N)
			return N - ni;
		++ki;
	}
	return 0;
}

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%d", &N);
		FOR(i, N)
			scanf("%lf", naomi+i);
		FOR(i, N)
			scanf("%lf", ken+i);
		sort(naomi, naomi+N);
		sort(ken, ken+N);

		printf("Case #%d: %d %d\n", itr+1, dwar(), war());
	}
}
