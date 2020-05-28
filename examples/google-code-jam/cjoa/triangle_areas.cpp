#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <sys/time.h>
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl

#define sz(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACHD(it,c) for(typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)

#define ALL(c) (c).begin(),(c).end()

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

typedef pair<int,int> II;

typedef long long llong;

// twice SIGNED area of triangle represented by points a, b, c
long long area2( long long ax, long long ay,
                 long long bx, long long by,
                 long long cx, long long cy ) {
   return ax * by - ay * bx +
          ay * cx - ax * cy +
          bx * cy - cx * by;
}

int main(int argc, char *argv[]) {
   int TC;
   cin >> TC;

   for (int tc = 1; tc <= TC; ++tc) {
      int N, M, A;
      cin >> N >> M >> A;
      FOR(x2,0,N) FOR(y2,0,M)
      FOR(x3,0,N) FOR(y3,0,M) {
         if (area2(0,0,x2,y2,x3,y3) == A) {
            cout << "Case #" << tc << ":"
                 << ' ' << 0 << ' ' << 0
                 << ' ' << x2 << ' ' << y2
                 << ' ' << x3 << ' ' << y3
                 << endl;
            goto done;
         }
      }
      cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
done:
      ;
   }

   return 0;
}
