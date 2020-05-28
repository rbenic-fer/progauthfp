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
double rdouble() { double x; if(scanf("%lf",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

double naomi[1000], ken[1000];

int dwar(int n)
{
	int points = 0;
	set<double> na;
	REP(i,n) na.insert(naomi[i]);
	REP(i,n) 
	{
		set<double>::iterator up = na.upper_bound(ken[i]);
		if (up != na.end()) {
			na.erase(up);
			points++;
		}
		else break;
	}
	return points;
}
int war(int n)
{
	int points = 0;
	set<double> k;
	REP(i,n) k.insert(ken[i]);
	REP(i,n) {
		set<double>::iterator up = k.upper_bound(naomi[i]);
		if (up != k.end())
		{
			k.erase(up);
		}
		else {
			points++;
			k.erase(k.begin());
		}
	}
	return points;
}

int main()
{
	int T = rint();
	REP(t,T)
	{
		int n = rint();
		REP(i,n) naomi[i] = rdouble();
		REP(i,n) ken[i] = rdouble();
		sort(naomi, naomi+n);
		sort(ken, ken+n);
		int ws = war(n);
		int score = dwar (n);
		printf("Case #%d: %d %d\n", t+1, score, ws);
	}
	return 0;
}
