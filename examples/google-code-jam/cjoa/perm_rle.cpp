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

int a[20];

int main(int argc, char *argv[]) {
   int TC;
   cin >> TC;

   for (int tc = 1; tc <= TC; ++tc) {
      int k;
      cin >> k;
      string s;
      cin >> s;
      for (int i = 0; i < k; ++i)
         a[i] = i;
      int bestscore = 10000000;
      do {
         string ns;
         for (int j = 0; j + k <= sz(s); j += k) {
            for (int i = 0; i < k; ++i)
               ns += s[j + a[i]];
         }
         int ngroups = 1;
         for (int j = 1; j < sz(ns); ++j) {
            if (ns[j] == ns[j-1]) continue;
            ++ngroups;
         }
         if (ngroups < bestscore) {
            bestscore = ngroups;
         }
      } while (next_permutation(a, a+k));
      cout << "Case #" << tc << ": " << bestscore << endl;
   }

   return 0;
}
