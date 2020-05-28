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
#include <map>

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

#define MAXWORDS 4444

VS unknown[222];
map<string, int> words;
bool frenchBase[MAXWORDS];
bool englishBase[MAXWORDS];
VI x[222];


void readWords (VS& out) {
	out.clear();

	string t;
	getline(cin,t);

	istringstream iss(t);
	string word;
	while(iss >> word) {
		out.PB(word);
	}
}

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int N;
		scanf("%d\n", &N);

		VS known1, known2;
		readWords(known1);
		readWords(known2);
		FOR(i, N-2)
			readWords(unknown[i]);

		FOR(i, MAXWORDS) {
			frenchBase[i] = 0;
			englishBase[i] = 0;
		}

		words.clear();
		FOR(i, SIZE(known1)) {
			int v = SIZE(words);
			if (words.count(known1[i]) == 0)
				words[known1[i]] = v;
			else
				v = words[known1[i]];
			frenchBase[v] = 1;
		}
		FOR(i, SIZE(known2)) {
			int v = SIZE(words);
			if (words.count(known2[i]) == 0)
				words[known2[i]] = v;
			else
				v = words[known2[i]];
			englishBase[v] = 1;
		}

		FOR(i, N-2) {
			x[i].clear();
			FOR(j, SIZE(unknown[i])) {
				int v = SIZE(words);
				if (words.count(unknown[i][j]) == 0)
					words[unknown[i][j]] = v;
				else
					v = words[unknown[i][j]];
				x[i].PB(v);
			}
		}
//		for (map<string,int>::iterator it = words.begin(); it != words.end(); ++it) {
//			cerr << it->first << " " << it->second << endl;
//		}
//		cerr << endl;

		int W = SIZE(words);

		int out = INF;
		for (int bits = 0; bits == 0 || bits < (1 << (N-2)); ++bits) {
			bool french[W];
			bool english[W];
			FOR(i, W) {
				french[i] = frenchBase[i];
				english[i] = englishBase[i];
			}
			FOR(i, N-2)
				FOR(j, SIZE(x[i])) {
					if (BIT(bits, i))
						english[x[i][j]] = 1;
					else
						french[x[i][j]] = 1;
				}
			int val = 0;
			FOR(i, W)
				val += french[i] * english[i];
			out = min(out, val);
		}

		printf("Case #%d: %d\n", itr+1, out);
	}

	cerr << "time: " << getTime() - time << endl;
}
