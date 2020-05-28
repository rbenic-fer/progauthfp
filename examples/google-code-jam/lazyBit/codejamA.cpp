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
		cerr<<v<<" ";	
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

char str[10][10];
bool check(char ch)
{
	int flag=0,j,i;
	for( i=0;i<4;i++)
	{
		flag=0;
		//row check
		for(j=0;j<4;j++)
		{
			if(str[i][j]!=ch &&str[i][j]!='T')
				flag=1;
		}
		if(flag==0)
			return 1;
		flag=0;
		//column check
		for(j=0;j<4;j++)
		{
			if(str[j][i]!=ch &&str[j][i]!='T')
				flag=1;
		}
		if(flag==0)
			return 1;
	}
	flag=0;
	//diagonal check
	for(i=0;i<4;i++)
			if(str[i][i]!=ch &&str[i][i]!='T')
				flag=1;
			
			if (flag==0)
				return true;
			
			flag=0;
			
			for(i=3;i>=0;i--)
			{
				if(str[3-i][i]!=ch&&str[3-i][i]!='T')
					flag=1;
			}
			if(flag==0)
				return 1;

return (0);
}
int main()
{
	input;
	output;
	int n,i,j,k,l=0,m,t,s=0;
	S(n);
	bool ch1,ch2;
	for(i=0;i<n;i++)
	{
		ch1=0;ch2=0;
		l=0;
		for(j=0;j<4;j++)
			scanf("%s",str[j]);
		// for(j=0;j<4;j++)
			// cout<<str[j]<<endl;

		ch1=check('O');
		ch2=check('X');
		for(k=0;k<4;k++)
			for(j=0;j<4;j++)
				if(str[k][j]=='.')
					l=1;
		if(ch1&&!ch2)
		{
			printf("Case #%d: O won\n",i+1);
		}
		else if(!ch1&&ch2)
		{
			printf("Case #%d: X won\n",i+1);	
		}
		else if((ch1&&ch2)||(!ch1&&!ch2&&!l))
		{
			printf("Case #%d: Draw\n",i+1);
		}
		else
		{
			printf("Case #%d: Game has not completed\n",i+1);
		}
	}
	return (0);
}