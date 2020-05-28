#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

// -------------------- Khai bao cac container --------------------
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <string> vs;

typedef long long LL; //NOTES:int64
typedef unsigned long long ULL; //NOTES:uint64
typedef unsigned uint;

const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";

// -------------------- Dinh nghia lai cac phep toan --------------------
#define rep(i,n)        for (int i=0;i<n;i++)
#define loop(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rloop(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define Reset(a,b)      memset((a),(b),sizeof(a))

#define endline         putchar('\n')
#define space           putchar(' ')
#define EXIT(x)         {cout << x;return 0;}

#define fi              first
#define se              second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define mp(X,Y)         make_pair(X,Y)
#define foreach(i, c)   for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x)   ((c).find(x) != (c).end())
#define sz(a)           a.size()

#define two(x)          (1 << (x))
#define two64(x)        (((int64)(1)) << (x))
#define S(x)            scanf("%d",&x);
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define deb(i,a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define db(x,y)          printf("%d %d\n",x,y);
#define debug(args...)	{dbg,args; cerr<<endl;}
#define dline			cerr<<endl	
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define maX(a,b)		((a)>(b)?(a):(b))
#define miN(a,b)		((a)<(b)?(a):(b))
#define abS(x)			((x)<0?-(x):(x))
#define mod             1000000007

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		// cerr<<v<<" ";	
		return *this;	
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

int a[110][110],n,m;
bool check(int x,int y)
{
	int i,j,flag=1;
	//check row
	//debugarr(a[x],m);
	// debug(a[x][y]);
	for(j=0;j<m;j++)
		if(a[x][j]>a[x][y])
			{//debug(a[x][j]);
				flag=0;
				break;}
		
		if(flag==1)
			return true;
		
		for(i=0;i<n;i++)
			if(a[i][y]>a[x][y])
				return false;
	return true;
}
int main()
{
	// input;
	// output;
	int i,j,k,l,t,s=0;
	S(t);
	for(int num=0;num<t;num++)
	{
		s=0;
		S(n);S(m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				S(a[i][j]);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(!check(i,j))
						goto ans;

				}
				
			}
			s=1;
			ans:
			if(!s)
			printf("Case #%d: NO\n",num+1);
			else
			printf("Case #%d: YES\n",num+1);
	}
	return (0);
}