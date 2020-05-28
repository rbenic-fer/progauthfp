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

LL A, B;
LL pow10[19];

LL palEven (LL x) {
	LL flip = 0, t = x, mult = 1;
	while (t > 0) {
		flip = flip * 10 + t % 10;
		t /= 10;
		mult *= 10;
	}
	return x * mult + flip;
}

LL palOdd (LL x) {
	LL flip = 0, t = x, mult = 1;
	while (t > 0) {
		flip = flip * 10 + t % 10;
		t /= 10;
		mult *= 10;
	}
	mult /= 10;
	flip %= mult;
	return x * mult + flip;
}

bool pal (LL x) {
	LL t = x;
	int len = 0;
	while (t > 0) {
		++len;
		t /= 10;
	}
//	cerr << x << endl;
	FOR(i, len / 2) {
//		cerr << i << " " << (x / pow10[len-1-i]) % 10 << " " << (x / pow10[i]) % 10 << endl;
		if ((x / pow10[len-1-i]) % 10 != (x / pow10[i]) % 10)
			return false;
	}
	return true;
}

int main () {
	pow10[0] = 1;
	FORU(i, 1, 18)
		pow10[i] = pow10[i-1] * 10;

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%lld%lld", &A, &B);

		int out = 0;
		LL x, x2, cur = 1;
		while (1) {
			x = palOdd(cur);
			x2 = x*x;
			if (x2 > B)
				break;
			if (x2 >= A && pal(x2)) {
				++out;
//				printf("%lld %lld %lld\n", x2, x, cur);
			}

			x = palEven(cur);
			x2 = x * x;
			if (x2 >= A && x2 <= B && pal(x2)) {
				++out;
//				printf("%lld %lld %lld\n", x2, x, cur);
			}
			++cur;
		}

		printf("Case #%d: %d\n", itr+1, out);
	}
}
