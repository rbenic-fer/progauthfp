#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
#define fst first
#define snd second
#define tup make_tuple

int n;
double v, e;

void work1()
{
	double r0, c0;
	scanf("%lf%lf", &r0, &c0);
	if(e != c0) printf("IMPOSSIBLE\n");
	else printf("%.8lf\n", v / r0);
}

void work2()
{
	double r0, c0, r1, c1;
	scanf("%lf%lf%lf%lf", &r0, &c0, &r1, &c1);
	if((c0 < e && c1 < e) || (c0 > e && c1 > e)) printf("IMPOSSIBLE\n");
	else if(c0 == e && c1 == e)
	{
		double r = r0 + r1;
		printf("%.8lf\n", v / r);
	}
	else if(c0 == e)
	{
		printf("%.8lf\n", v / r0);
	}
	else if(c1 == e)
	{
		printf("%.8lf\n", v / r1);
	}
	else
	{
		double alpha = (e - c1) / (c0 - c1);
		printf("%.8lf\n", max(v * alpha / r0, v * (1 - alpha) / r1));
	}
}

void work()
{
	scanf("%d%lf%lf", &n, &v, &e);
	if(n == 1) work1();
	else work2();
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
