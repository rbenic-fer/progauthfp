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

int main() {
	int T = rint();
	FORN(t, T)
	{
		string s; cin >> s;
		int n = s.size();
		int ans = 0;

		REP(i, n) {
			if (i > 0 && s[i] != s[i-1]) {
				// flip 0..i-1
				s[i-1] = s[i];
				ans++;
			}
		}

		if (s[n-1] == '-') ans++;

		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
