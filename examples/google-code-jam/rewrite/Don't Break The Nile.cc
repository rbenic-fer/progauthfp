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
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
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
const int N = 200,M=600;
int T,x,xx,y,yy,w,h,b,ans;
bool mp[N][M];

bool upfs(int x,int y){
	if(y>=h){ mp[x][y]=1; return true; }
	mp[x][y]=1;
	rep(i,4){
		int tx = x+dx[i],ty = y + dy[i];
		if(mp[tx][ty]) continue;
		bool f = upfs(tx,ty);
		if(f) return true;
	}
	return false;
}

int work(){
	ans = 0;
	fer(i,1,w){
		if(mp[i][1]) continue;
		if(upfs(i,1)) ans++;
	//				puts("");rof(i,h+1,1) fer(j,1,w+1) printf("%d%c",mp[j][i],j==w?'\n':' ' );
	}

	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("cc.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d",&T);
	fer(tt,1,T+1){
		printf("Case #%d: ",tt);
		scanf("%d%d%d",&w,&h,&b);
		memset(mp,0,sizeof(mp));
		rep(i,w+2) mp[i][0]=mp[i][h+1]=1;
		rep(i,h+2) mp[0][i]=mp[w+1][i]=1;
		rep(i,b){
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			x++,y++,xx++,yy++;
			fer(i,x,xx+1) fer(j,y,yy+1) mp[i][j]=1;
		}
	//if(tt==20)		{puts("");rof(i,h+1,1) fer(j,1,w+1) printf("%d%c",mp[j][i],j==w?'\n':' ' );}
		printf("%d\n", work());
	}
	return 0;
}