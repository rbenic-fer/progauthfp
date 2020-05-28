#include <iostream>

#include <cmath>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define SZ(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

int M, N;
string S[10];

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> M >> N;
      for (int i = 0; i < M; ++i)
         cin >> S[i];

      int mx = (int) pow(N, M);

      int res = 0, cnt = 0;
      for (int mask = 0; mask < mx; ++mask) {
         int cur_mask = mask;
         vector< string > VS[N];
         for (int i = 0; i < M; ++i) {
            int k = cur_mask % N;
            VS[k].push_back( S[i] );
            cur_mask /= N;
         }

         bool ok = true;
         for (int k = 0; k < N; ++k)
            if (VS[k].empty()) {
               ok = false;
               break;
            }
         if (!ok) continue;

         int cur = N;
         for (int k = 0; k < N; ++k) {
            vector<string>& v = VS[k];
         // v.push_back("");
            sort(v.begin(), v.end());
            cur += SZ( v[0] );
            for (int j = 1; j < v.size(); ++j) {
               int n;
               for (n = 0; n < SZ(v[j]) && n < SZ(v[j-1]); ++n)
                  if (v[j][n] != v[j-1][n]) break;
               cur += SZ(v[j]) - n;
            }
         }

      // cerr << mask << ' ' << cur << endl;
         if (res < cur) {
            res = cur;
            cnt = 1;
         }
         else
         if (res == cur)
            ++cnt;
      }
      
      cout << "Case #" << tc << ": " << res << ' ' << cnt << endl;
   }

   return 0;
}
