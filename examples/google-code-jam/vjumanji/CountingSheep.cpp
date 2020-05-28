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

void checkMask (int &mask, Long n) {
	while (n) {
		int d = n % 10;
		n /= 10;
		mask |= 1<<d;
	}
}

Long getSheep (Long n) {
	if (n == 0) return 0;
	int mask = 0, target = (1<<10)-1;
	Long term = n;
	while(true) {
		checkMask(mask, term);
		if (mask == target) return term;
		term += n;
	}
}

int main() {
	int T = rint();
	FORN(t, T)
	{
		Long n = rint();
		Long ans = getSheep(n);
		if (ans == 0) printf("Case #%d: INSOMNIA\n", t);
		else printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
