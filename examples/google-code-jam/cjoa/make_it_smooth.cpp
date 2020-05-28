#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

#define INF (1<<30)

int D, I, M, N;
int A[102];

map<int,int> memo[102];
int go(int i, int last) {
   if (i > N)
      return 0;
   if (!memo[i].count(last)) {
      int& res = memo[i][last];
      res = INF;
      int dif = abs(A[i]-last);
      if (dif <= M) {
         res = min(res, go(i+1, A[i]));  // no action
#ifdef TRACE
         if (i == 2)
         printf("no change %d\n", res);
#endif
      }
      // change
      res = min(res, abs(A[i]-last-M) + go(i+1, last+M));
#ifdef TRACE
      if (i == 2)
      printf("after change + %d\n", res);
#endif
      res = min(res, abs(A[i]-last+M) + go(i+1, last-M));
#ifdef TRACE
      if (i == 2)
      printf("after change - %d\n", res);
#endif
      if (i == 1)
         FOR(nv, 0, 255)
            res = min(res, abs(nv-A[i]) + go(i+1, nv));
      
      if (dif > M) {
         if (M > 0) {
            int n = ((dif+M-1)/M-1);
            // insert
            res = min(res, I*n + go(i, last > A[i] ? last - M*n : last + M*n));
#ifdef TRACE
            if (i == 2)
            printf("after insert %d\n", res);
#endif
         }
         // delete
         res = min(res, D + go(i+1, last));
#ifdef TRACE
         if (i == 2)
         printf("after delete %d\n", res);
#endif
      }
      return res;
   }
   else
      return memo[i][last];
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d %d %d", &D, &I, &M, &N);
      for (int i = 1; i <= N; ++i)
         scanf("%d", A+i);
      A[0] = A[1];
      for (int i = 0; i <= 101; ++i)
         memo[i].clear();
      int res = go(1, A[0]);
      printf("Case #%d: %d\n", tc, res);
      fflush(stdout);
   }
   return 0;
}
