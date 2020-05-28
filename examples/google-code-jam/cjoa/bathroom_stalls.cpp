#include <iostream>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<llong,llong> PLL;

PLL solve(llong N, llong K) {
   if (K == N)
      return PLL(0, 0);

   map<llong, llong, greater<llong> > freq;
   freq[N] = 1;
   while (true) {
      auto it = freq.begin();
      llong len = it->first, cnt = it->second;

      PLL p( len/2, (len-1)/2 );
      K -= cnt;
      if (K <= 0)
         return p;

      freq.erase(it);
      freq[p.first]  += cnt;
      freq[p.second] += cnt;
   }
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   FOR(tc, 1, TC) {
      llong N, K;
      cin >> N >> K;
      PLL res = solve(N, K);
      cout << "Case #" << tc << ": " << res.first << ' ' << res.second << '\n';
   }

   return 0;
}
