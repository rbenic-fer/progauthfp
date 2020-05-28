#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define all(i) (i).begin(),(i).end()
#define aall(i) (i),((i)+sizeof(i)/sizeof((i)[0]))
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)
#define MOD 1000002013
#define M(x) ((x)%MOD)

map<pii,int> x;
typedef map<pii,int>::iterator iter;

inline ll c2( ll i, ll j )
{
	return M( ( j - i ) * ( j - i - 1 ) / 2 );
}

inline ll c2( const pii & i )
{
	return c2( i.first, i.second );
}

inline ll c2( const iter & i )
{
	return M( i->second * c2( i->first ) );
}

inline bool seq( const pii & i, const pii & j )
{
	return i.first < j.first && i.second < j.second && j.first <= i.second;
}

inline int len( const iter & i, const iter & j )
{
	return j->first.second - i->first.first;
}

void run()
{
	int n, m;
	scanf( "%d%d", &n, &m );
	while( m-- )
	{
		int i, j, c;
		scanf( "%d%d%d", &i, &j, &c );
		x[mp(i,j)] += c;
	}

	ll base = 0;
	foreach(i,x) base = M( base + c2(i) );

	ll ans = 0;
	while( !x.empty() )
	{
		for( iter i = x.begin(); i != x.end(); )
		{
			bool erase = true;
			if( i->second > 0 && i->first.first < i->first.second )
			{
				for( iter j = x.begin(); j != i; j++ ) if( seq( j->first, i->first ) )
					erase = false;
				for( iter j = i; j != x.end(); j++ ) if( seq( i->first, j->first ) )
					erase = false;
			}
			//printf( "%d %d %d %d\n", i->first.first, i->first.second, i->second, erase );
			if( erase )
			{
				ans = M( ans + c2( i ) );
				iter tmp = i;
				i++;
				x.erase(tmp);
			}
			else i++;
		}

		iter best_i = x.end(), best_j = x.end();
		foreach(i,x) for( iter j = i; j != x.end(); j++ )
		if(
			seq( i->first, j->first ) &&
			( best_i == x.end() || len( i, j ) > len( best_i, best_j ) )
		)
			best_i = i, best_j = j;

		if( best_i == x.end() )
		{
			if( x.empty() ) break;
			else continue;
		}

		int cnt = min( best_i->second, best_j->second );
		x[ mp( best_i->first.first, best_j->first.second ) ] += cnt;
		x[ mp( best_j->first.first, best_i->first.second ) ] += cnt;
		
		best_i->second -= cnt, best_j->second -= cnt;
	}

	printf( "%lld\n", ans - base );
}

int main()
{
	int T;
	scanf( "%d", &T );
	rep(t,T)
	{
		printf( "Case #%d: ", t + 1 );
		run();
	}
	return 0;
}
