#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;


typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

/** Constant List .. **/ //{
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};
const int mod = 1000000007;
const int INF = 0x3f3f3f3f;
//}

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}

////////////////////////////////////////////////////////////////////////////////////////////
/**////////////////////////////////////////////////////////////////////////////////////////////
const int N = 10009;
int T,n,x,l;
char ss[N];
string s="";
int mtex[4][4]={
	1,2,3,4,
	2,-1,4,-3,
	3,-4,-1,2,
	4,3,-2,-1
};
int multi(int a,int b){
	int ret=1;
	if(a<0) ret*=-1,a*=-1;
	if(b<0) ret*=-1,b*=-1;
	return mtex[a-1][b-1]*ret;
}
int f(char c){
	switch(c){
		case 'i':return 2;
		case 'j':return 3;
		case 'k':return 4;
	}
	return 0;
}

int z[N];

int work(){
	s="";
	rep(i,x) s+=ss;
	n=l*x;
	z[n-1]=f(s[n-1]);
	rof(i,n-1,0) z[i]=multi(f(s[i]),z[i+1]);
	bool flagi=false;
	int tmp=1;
	fer(i,0,n){
		// printf("%d %d %d %d\n",i,flagi,tmp,z[i] );
		if(flagi && tmp==4 && z[i]==4) return true;
		tmp = multi(tmp,f(s[i]));
		flagi|=(tmp==2);
	}
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d",&T);
	fer(tt,1,T+1){
		scanf("%d%d\n%s",&l,&x,ss);		
		printf("Case #%d: %s\n",tt,work()?"YES":"NO");
	}
	return 0;
}