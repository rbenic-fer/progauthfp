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
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////
int T,a,b,tmp,ans;
set<int> s;
int main()
{
//	freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin>>T;
	fer(t,1,T+1){
		s.clear();
		cin>>a;
		rep(i,a-1) rep(j,4) cin>>tmp;
		rep(i,4) cin>>tmp,s.insert(tmp);
		rep(i,4-a) rep(j,4) cin>>tmp;
		cin>>a;
		rep(i,a-1) rep(j,4) cin>>tmp;
		b=0;
		rep(i,4) {
			cin>>tmp; if(s.find(tmp)!=s.end()) b++,ans=tmp;
		}
		rep(i,4-a) rep(j,4) cin>>tmp;
		printf("Case #%d: ",t);
		if(b==0) puts("Volunteer cheated!");
		else if(b==1) printf("%d\n",ans );
		else puts("Bad magician!");
	}	
	return 0;
}