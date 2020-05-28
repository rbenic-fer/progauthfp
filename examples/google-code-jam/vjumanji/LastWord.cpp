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
		string o = "";
		REP(i, s.size()) {
			string o1 = o + s[i];
			string o2 = string(1,s[i])+ o;
			if (o1 > o2) o = o1;
			else o = o2;
		}
		printf("Case #%d: %s\n", t, o.c_str());
	}

	return 0;
}
