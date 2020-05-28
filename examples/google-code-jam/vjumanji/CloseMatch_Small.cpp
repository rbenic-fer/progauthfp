#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define  FOR(i,a,b)		for(int i=(a); i<(b); ++i)
#define  REP(i,a)		FOR(i,0,a)
#define FORN(i,a)		FOR(i,1,(a)+1)
#define FORD(i,a,b)    	for(int i(a-1);i>=b;--i)

typedef long long int iLong;
typedef vector<int> iVec;
typedef pair<int,int> iiPair;

int rint() { int x; scanf("%d", &x); return x;}
long long int rLL() { long long int x; scanf("%lld", &x); return x;}

string C, J;

bool matches (string &a, string &m) {
	int n = m.size();
	REP(i, n) if (m[i] != '?' && m[i] != a[i])
		return false;
	return true;
}

int main() {
		// cout <<	string (10, '2');
	int T = rint();
	FORN(t, T)
	{
		cin >> C >> J;
		int ans = -1, ix, jx;
		string iax, jax;
		int n = C.size();
		int lim = 1; REP(i, n) lim *= 10;
		REP(i, lim) {
			string dc(n, '0');
			int p = i, idx = n-1;
			while(p) {
				dc[idx--] = '0' + p%10;
				p /= 10;
			}
			if (matches(dc, C)) {

				REP(j, lim) {
					string dj(n, '0');
					p = j, idx = n-1;
					while(p) {
						dj[idx--] = '0' + p%10;
						p /= 10;
					}
					if (matches(dj, J)) {

						if (ans == -1 || abs(i-j) < ans) {
							ix = i, jx = j; iax = dc; jax = dj;
							ans = abs(i-j);
						}
						else if (ans == abs(i-j)) {
							if (i < ix || (i == ix && j < jx)) {
								ix = i, jx = j; iax = dc; jax = dj;
								ans = abs(i-j);
							}
						}

					}
				}


			}
		}
		printf("Case #%d: %s %s\n", t, iax.c_str(), jax.c_str());
	}
	return 0;
}