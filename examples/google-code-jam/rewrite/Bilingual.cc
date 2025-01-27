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
typedef pair<bool,bool> pbb;
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
const int N = 30;
int T,n;
map<string,int> m;
char s[20];
vector<vector<string> > v;

int calc(int assume){
	MSI tm = m;
	rep(i,v.size()){
		int tmp;
		if((assume>>i)&1) tmp=2;
		else tmp=1;
		rep(j,v[i].size()){
			tm[v[i][j]]|=tmp;
		}
	}
	int ret = 0;
	for(MSI::iterator ite = tm.begin(); ite!=tm.end(); ite++)
		if(ite->Y == 3) ret++;
	//printf("assume:%d\n",assume );
	
	//for(MSI::iterator ite = tm.begin(); ite!=tm.end(); ite++)cout<<ite->X<<' '<<ite->Y<<endl;

	return ret;
}

int work(){
	int num = v.size();
	int ret = INF;
	rep(i,1<<num){
		smin(ret, calc(i));
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
		m.clear();
		scanf("%d\n",&n);
		char c = ' ';
		while(c!='\n'){
			scanf("%s%c",s,&c);
			string tmp(s);
			m[s]|=2;
		}
		c = ' ';
		while(c!='\n'){
			scanf("%s%c",s,&c);
			string tmp(s);
			m[s]|=1;
		}
		v.clear();
		rep(i,n-2){
			c = ' ';
			VS tv;
			while(c!='\n' && c!=-1){
				scanf("%s%c",s,&c);
				string tmp(s);
				tv.pb(tmp);
			}
			v.pb(tv);
		}
		printf("Case #%d: %d\n",tt,work());
	}
	return 0;
}