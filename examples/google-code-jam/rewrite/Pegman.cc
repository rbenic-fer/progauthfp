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
const int N = 109;
int T,n;
char s[N][N];
int r,c;
int row[N],col[N];
inline bool in(int x,int y){
	return x>=0 && x<r && y>=0 && y<c;
}

bool ceshi(int x,int y,int dx,int dy){
	x+=dx,y+=dy;
	while(in(x,y)){
		if(s[x][y]!='.') return true;
		x+=dx; y+=dy;
	}
	return false;
}

int work(){
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	rep(i,r) rep(j,c) if(s[i][j]!='.'){
		row[i]++; col[j]++;
	}
	rep(i,r){
		if(row[i]!=1) continue;
		rep(j,c){
			if(col[j]!=1) continue;
			if(s[i][j]!='.'){
				return -1;
			}
		}
	}

	int ret = 0;
	rep(i,r) rep(j,c) if(s[i][j]!='.'){
		switch(s[i][j]){
			case '^':
			if(!ceshi(i,j,-1,0)) ret++;
			break;

			case '>':
			if(!ceshi(i,j,0,1)) ret++;
			break;

			case '<':
			if(!ceshi(i,j,0,-1)) ret++;
			break;

			case 'v':
			if(!ceshi(i,j,1,0)) ret++;
			break;
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
		scanf("%d%d",&r,&c);
		rep(i,r) scanf("\n%s",s[i]);
		int tmp = work();
		printf("Case #%d: ",tt);
		if(tmp==-1) puts("IMPOSSIBLE");
		else printf("%d\n",tmp );
	}
	return 0;
}