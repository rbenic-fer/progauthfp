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

#define BITCOUNT(mask) ( __builtin_popcountl((mask)) )


int main(int argc, char *argv[]) {
   int TC;
   cin >> TC;

   for (int tc = 1; tc <= TC; ++tc) {
      int N, M;
      cin >> N >> M;
      vector< int > pref_unmalted(M), pref_malted(M);
      REP(m, M) {
         int T;
         cin >> T;
         REP(t, T) {
            int flavor, malted;
            cin >> flavor >> malted;
            if (malted)
               pref_malted[m] |= 1 << (flavor-1);
            else
               pref_unmalted[m] |= 1 << (flavor-1);
         }
      }
      bool found = false;
      int bestmask = -1;
      for (int mask = (1 << N)-1; mask >= 0; --mask) {
         bool ok = true;
         REP(m, M) {
            if ( (mask & pref_malted[m]) == 0 &&
                 (~mask & pref_unmalted[m]) == 0) {
               ok = false;
               break;
           }
         }
         if (ok) {
            found = true;
            if (BITCOUNT(mask) < BITCOUNT(bestmask))
               bestmask = mask;
         }
      }

      cout << "Case #" << tc << ":";
      if (!found) {
         cout << " IMPOSSIBLE" << endl;
         continue;
      }
      REP(i, N)
         cout << ' ' << ((bestmask & (1 << i)) ? 1 : 0);
      cout << endl;
   }

   return 0;
}
