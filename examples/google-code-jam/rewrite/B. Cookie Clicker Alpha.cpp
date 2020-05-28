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
typedef  long double ld;
typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////
int T;
ld c,f,x;
ld solve(int n){
	ld now = 2;
	ld ret = 0.0;
	rep(i,n){
		ret += c/now;
		now += f;
	}
	return (ret + x/now);
}
ld work(){
	int l=0,r=100000,mid,mmid;
	ld rm,rmm;
	while(l<r-1){
		mid = (l+r)/2;
		mmid = (mid+r)/2;
		rm = solve(mid), rmm = solve(mmid);
		if(rm<rmm) r = mmid;
		else l = mid;
	}
	return min(solve(0),min(solve(l),solve(l+1)));
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>T;
	fer(t,1,T+1){
		cin>>c>>f>>x;
		printf("Case #%d: %.7Lf\n", t, work());
	}
	return 0;
}