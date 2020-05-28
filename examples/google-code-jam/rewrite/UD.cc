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
//}

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}

////////////////////////////////////////////////////////////////////////////////
const int N = 1009;
int mxh;
int T,n,a[N],b[N],num[N];
int ans,tmp;

void swap(int &a,int &b){int c=a;a=b;b=c;}

bool ok(int a[]){
	int i=0;
	for(;i<n-1;i++){
		if(a[i]>=a[i+1]) break;
	}
	for(;i<n-1;i++){
		if(a[i]<a[i+1]) return false;
	}
	return true;
}

int cal(int a[],int b[]){
	int i,j,ret=0;
	rep(i,n-1){
		for(j=i;j<n;j++) if(b[j]==a[i]) break;
		for(int k=j;k>i;k--) swap(b[k],b[k-1]),ret++;
	}
	return ret;
}

void work(){
	rep(i,N) num[i]=i;
	ans = 1000000;
	do{
		rep(i,n) b[i]=a[num[i]];
		if(ok(b)){
			tmp=cal(a,b);
		//	printf("tmp:%d\n",tmp );
			smin(ans,tmp);
		}
	}while(next_permutation(num,num+n));
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("bb.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d",&T);
	fer(tt,1,T+1){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		int tmp = -1,mxh=0;
		rep(i,n){
			scanf("%d",a+i);
		}
		work();
		printf("%d\n", ans);
	}
	
}