#include <iostream>

#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llong;

#define HIGHESTSETBIT(mask) ( sizeof(long long)*8-1-__builtin_clzll((mask)) )

int N;
llong P;

llong f1() {
   llong nteams = 1LL << N;
   for (llong n = 0; n < nteams; ++n) {
      int nlosses = HIGHESTSETBIT(n + 1);
      llong m = ((1LL << N)-1) & (~((1LL << (N - nlosses))-1));
   // cerr << n << ": " << nlosses << ' ' << m << endl;
      if (m >= P)
         return n-1;
   }
   return nteams-1;
}

llong f2() {
   llong nteams = 1LL << N;
   for (llong n = nteams-1; n > 0; --n) {
      int nwins = HIGHESTSETBIT(nteams - n);
      llong m = (1LL << (N - nwins)) - 1;
   // cerr << n << ": " << nwins << ' ' << m << endl;
      if (m < P)
         return n;
   }
   return 0;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> N >> P;
      llong res1 = f1();
      llong res2 = f2();
      cout << "Case #" << tc << ": " << res1 << ' ' << res2 << endl;
   }

   return 0;
}
