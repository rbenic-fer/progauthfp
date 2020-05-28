#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int N, K;
int price[16][25];
bool can[1<<16];

int memo[1<<16];
int go(int mask) {
   int& res = memo[mask];
   if (res < 0) {
      if (can[mask])
         return res = 1;
      res = N;
      if (!can[mask]) {
         for (int m = (m-1) & mask; m > 0; m = (m-1) & mask) {
            res = min(res, go(m)+go(mask & ~m));
         }
      }
   }
   return res;
}

void print_bits(long long m, int nbits = 32) {
   for (int i = 0; i < nbits; ++i)
      putchar((m & (1LL << i)) ? '1' : '0');
}


int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d", &N, &K);
      REP(i, N)
         REP(k, K)
            scanf("%d", &price[i][k]);
      FOR(mask, 0, (1<<N)-1) {
         bool t = true;
         REP(i, N) {
            if (!(mask & (1<<i))) continue;
            FOR(j, i+1, N-1) {
               if (!(mask & (1<<j))) continue;
               if (price[i][0] == price[j][0]) {
                  t = false;
                  break;
               }
               bool d = price[i][0] < price[j][0];
               FOR(k, 1, K-1) {
                  if (price[i][k] == price[j][k]) {
                     t = false;
                     break;
                  }
                  if (d != (price[i][k] < price[j][k])) {
                     t = false;
                     break;
                  }
               }
               if (!t) break;
            }
            if (!t) break;
         }
         can[mask] = t;
//       print_bits(mask);
//       printf(": %d\n", can[mask]);
      }
      memset(memo, -1, sizeof(memo));
      memo[0] = 0;
      int res = go((1 << N)-1);
      printf("Case #%d: %d\n", tc, res);
   }
   return 0;
}
