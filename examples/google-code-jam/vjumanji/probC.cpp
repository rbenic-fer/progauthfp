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

char mine[50][50];

void mark(int &i, int &m, int &r, int &c) {
	if (i < abs(c-r)) {
		if (r < c) {
			for (int j=0; j<r && m; j++, m--) mine[j][i] = '*';
		}
		else {
			for (int j=0; j<c && m; j++, m--) mine[i][j] = '*';
		}
	}
	else {
		if (r < c) {
			for (int j=r-1; j>i-(c-r) && m; j--, m--) mine[j][i] = '*';
			for (int j=i; j < c && m; j++, m--) mine[i-(c-r)][j] = '*';
		}
		else
		{
			for (int j=c-1; j>i-(r-c) && m; j--, m--) mine[i][j] = '*';
			for (int j=i; j < r && m; j++, m--) mine[j][i-(r-c)] = '*';
		}
	}
	++i;
}

bool solve(int r, int c, int m)
{
	CL(mine, '.');
	int i = 0, w = r*c-m;
	while (m) mark(i,m,r,c);
	if (mine[r-1][c-1] == '*') return false;
	int n = 0;
	if (r-2>=0 && mine[r-2][c-1]=='*') ++n;
	if (c-2>=0 && mine[r-1][c-2]=='*') ++n;
	if (r-2>=0 && c-2>=0 && mine[r-2][c-2]=='*') ++n;
	if (n && w > 1) return false;
	mine[r-1][c-1] = 'c';
	return true;
}

int main()
{
	int T = rint();
	REP(t,T) {
		int r = rint();
		int c = rint();
		int m = rint();
		printf("Case #%d: ", t+1);
		if (solve(r,c,m))
		{
			REP(i,r) mine[i][c] = 0, printf("\n%s", mine[i]);
		}
		else
		{
			printf("\nImpossible");
		}
		printf("\n");
	}
	return 0;
}
