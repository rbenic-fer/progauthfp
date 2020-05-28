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

double solve(double c, double f, double x, double r)
{
//	if (x <= r) return 1;
	int i = ceil((x/c) - (2/f) - 1);
	double t = 0;
	REP(j,i) {
		t += c/r;
		r += f;
	}
	t += x/r;
	return t;
}

int main()
{
	int T = rint();
	REP(t,T)
	{
		double c = rdouble();
		double f = rdouble();
		double x = rdouble();
		printf("Case #%d: %.7lf\n", t+1, solve(c,f,x,2));
	}
	return 0;
}
