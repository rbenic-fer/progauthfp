#include <iostream>

#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define SZ(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;

int R, C;
char B[104][104];

string dir = "^<>v";
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool go(int r, int c, int k) {
   while (true) {
      r += dr[k];
      c += dc[k];
      if (r < 0 || r >= R || c < 0 || c >= C) return false;
      if (B[r][c] != '.') break;
   }
   return true;
}

int solve() {
   int res = 0;
   for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
      if (B[r][c] != '.') {
         size_t k = dir.find(B[r][c]);
         assert(k != string::npos);

         if (go(r, c, k)) continue;

         bool ok = false;
         REP(kk, 4) {
            if (kk == int(k)) continue;
            if (go(r, c, kk)) {
               ok = true;
               break;
            }
         }
         if (!ok) return -1;
         ++res;
      }
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> R >> C;
      REP(r, R)
         cin >> B[r];

      int res = solve();
      if (res < 0)
         cout << "Case #" << tc << ": IMPOSSIBLE\n";
      else
         cout << "Case #" << tc << ": " << res << "\n";
   }

   return 0;
}
