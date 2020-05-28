// directives 
	#include <stdio.h>
	#include <vector>
	#include <map>
	#include <set>
	#include <deque>
	#include <queue>
	#include <algorithm>
	#include <iostream>
	#include <cmath>
	#include <cstring>
	#include <typeinfo>
// 
using namespace std;
// macros 
	#define FOR(i,a,b)      for(int i(a);i<b;++i)
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define REP(i,n)        FOR(i,0,n)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
// 

typedef long long LL;
typedef vector<int> vi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

int initial[4][4], final[4][4];

void solve(int ri, int rj)
{
	int card = 0;
	REP(i,4) {
		REP(j,4) {
			if (initial[ri][i] == final[rj][j]) {
				if (card != 0) {
					printf("Bad magician!\n");
					return;
				} 
				card = initial[ri][i];
			}
		}
	}
	if (card == 0) printf("Volunteer cheated!\n");
	else printf("%d\n", card);
}

int main()
{
	int T = rint();
	REP(t,T)
	{
		int ri = rint();
		REP(i,4) REP(j,4) initial[i][j] = rint();
		int rj = rint();
		REP(i,4) REP(j,4) final[i][j] = rint();
		printf("Case #%d: ", t+1);
		solve(ri-1,rj-1);
	}
	return 0;
}
