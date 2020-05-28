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
const int N = 39;
int T;
int c,d,v;
int a[N];
bool vis[N]; // 1...v
bool has[N];

int fill(bool vis[],int a[],int sz){
	vis[0]=true;
	rep(i,sz) rof(j,v+1,a[i]){
		if(vis[j-a[i]]) vis[j]=true;
	}
	fer(i,1,v+1) if(!vis[i]) return i;
	return 0;
}
int addfill(bool vis[],int a){
	vis[0]=true;
	rof(j,v+1,a){
		if(vis[j-a]) vis[j]=true;
	}
	fer(i,1,v+1) if(!vis[i]) return i;
	return 0;
}

int search(int x){
	bool tvis[N];
	rep(i,N) tvis[i]=vis[i];
	int ret = INF;
	fer(i,2,x+1) if(!has[i] && vis[x-i]){
		has[i]=true;
		int tmp = addfill(vis,i);
		if(tmp==0) return 1;
		int cost=0;
		cost = search(tmp);
		smin(ret,cost+1);
		rep(j,N) vis[j]=tvis[j];
		has[i]=false;
	}
	return ret;
}


int work(){
	// int ret=0,tflag=0;
	// if(a[0]!=1){
	// 	tflag =1; a[d]=1; d++; sort(a,a+d); has[1]=true;
	// }
	// memset(vis,0,sizeof vis);
	// vis[0]=1;
	// ret = fill(vis,a,d);
	// if(ret==0) return tflag;
	// return tflag+search(ret) ;
	int ret = 0;
	fer(i,1,v+1){
		if(has[i]) continue;
		memset(vis,0,sizeof vis);
		fill(vis,a,d);
		if(!vis[i]){
			a[d]=i; d++; ret++; has[i]=true;
		}
	}
	return ret;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d",&T);
	fer(tt,1,T+1){
		memset(has,0,sizeof has);
		memset(vis,0,sizeof vis);
		memset(a,0,sizeof a);
		scanf("%d%d%d",&c,&d,&v);
		assert(c==1);
		assert(v<=30);
		rep(i,d) scanf("%d",a+i),has[a[i]]=true; sort(a,a+d);
		printf("Case #%d: %d\n",tt,work());
	}
	return 0;
}