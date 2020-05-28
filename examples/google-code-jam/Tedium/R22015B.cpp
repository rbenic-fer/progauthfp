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

double rate[111];
double temp[111];

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int N;
		double V, X;
		cin >> N;
		cin >> V;
		cin >> X;

		for (int i = 0; i < N; ++i) {
			cin >> rate[i];
			cin >> temp[i];
		}

		if (N > 1 && temp[0] > temp[1]) {
			double t;
			SWAP(temp[0], temp[1], t);
			SWAP(rate[0], rate[1], t);
		}

//		for (int i = 0; i < N; ++i) {
//			cerr << rate[i] << " " << temp[i] << endl;
//		}

		if (temp[0] > X + EPS || temp[N-1] < X - EPS) {
			printf("Case #%d: IMPOSSIBLE\n", itr+1);
			continue;
		}

		double out = 1e100;
		if (abs(temp[0]-X) > EPS) {
			if (abs(temp[1]-X) < EPS)
				out = V / rate[1];
			else {
				double fillrate = rate[0]+rate[1], filltemp = (rate[0]*temp[0]+rate[1]*temp[1])/(rate[0]+rate[1]);
				if (filltemp > X) {
					double fillto = V * (X - temp[0]) / (filltemp - temp[0]);
					out = min(out, fillto / fillrate + (V - fillto) / rate[0]);
				}
				else {
					double fillto = V * (X - temp[1]) / (filltemp - temp[1]);
					out = min(out, fillto / fillrate + (V - fillto) / rate[1]);
				}
			}
		}
		else {
			if (N == 2 && abs(temp[1]-X) < EPS)
				out = V / (rate[0]+rate[1]);
			else
				out = V / rate[0];
		}

		printf("Case #%d: %.8f\n", itr+1, out);
	}

	cerr << "time: " << getTime() - time << endl;
}
