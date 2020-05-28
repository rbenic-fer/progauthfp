#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define  FOR(i,a,b)			for(int i=(a); i<(b); ++i)
#define  REP(i,a)				FOR(i,0,a)
#define FORN(i,a)				FOR(i,1,(a)+1)
#define FORD(i,a,b)			for(int i(a-1);i>=b;--i)
#define  ALL(v)					v.begin(), v.end()

typedef long long int Long;
typedef vector<int> VecI;
typedef pair<int,int> Pair2i;

int rint() { int x; scanf("%d", &x); return x;}
int rLL() { Long x; scanf("%lld", &x); return x;}

const int nmax = 50;
int rc[2*nmax][nmax];
int missing[nmax];
bool removed[2*nmax];
bool consider[2*nmax];

void solve (int r, int N) {
	int a = -1, b = -1;
	REP(i, 2*N-1) if (!removed[i]) {
		if (a == -1) {
			a = i;
		}
		else if (rc[i][r] == rc[a][r]) {
			b = i;
		}
		else if (rc[i][r] < rc[a][r]) {
			a = i; b = -1;
		}
	}
	removed[a] = true;
	REP(i, 2*N-1) consider[i] = false;
	FOR(k, r+1, N) {
		bool found = false;
		REP(i, 2*N-1) if (!removed[i] && !consider[i] && i!=a && i!=b) {
			if (rc[i][r] == rc[a][k]) {
				found = true;
				consider[i] = true;
				break;
			}
		}
		if (!found) {
			missing[r] = rc[a][k];
			break;
		}
	}
	if (b == -1) {
		missing[r] = rc[a][r];
		int k = r;
		REP(i, 2*N-1) if (!removed[i] && !consider[i]) missing[++k] = rc[i][r];
		return;
	}
	else {
		removed[b] = true;
		FOR(k, r+1, N) {
			bool found = false;
			REP(i, 2*N-1) if (!removed[i] && !consider[i] && i!=a && i!=b) {
				if (rc[i][r] == rc[b][k]) {
					found = true;
					consider[i] = true;
					break;
				}
			}
			if (!found) {
				missing[r] = rc[b][k];
				break;
			}
		}
	}
	if (r + 1 < N) solve(r+1, N);
}


int main() {
	int T = rint();
	FORN(t, T) {
		int N = rint();
		REP(i, 2*N-1) REP(j, N) rc[i][j] = rint();
		REP(i, 2*N-1) removed[i] = false;
		solve(0, N);
		sort(missing,missing+N);
		printf("Case #%d: ", t);
		REP(i, N) printf("%d ", missing[i]);
		printf("\n");
	}
	return 0;
}
