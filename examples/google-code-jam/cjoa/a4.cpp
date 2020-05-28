#include <cstdio>

#include <queue>
#include <functional>
#include <vector>

using namespace std;

#define EPS 1e-9

typedef pair<int,int> II;
typedef long long llong;

int X, S, R, t, N;
int B[1004], E[1004], W[1004];

struct Cmp {
   bool operator()(II a, II b) const {
      llong di = a.second, dj = b.second;
      llong wi = a.first, wj = a.second;
      llong n1 = ( (wi+R) - (wi+S) ) * ( wj+S ) * ( wj+R );
      llong n2 = ( (wj+R) - (wj+S) ) * ( wi+S ) * ( wi+R );
      if (n1 != n2) {
         return n1 > n2;
      }
      return a.second > b.second;
   }
};

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d %d %d %d", &X, &S, &R, &t, &N);
      priority_queue<II, vector<II>, Cmp > pq;
      int sum = 0;
      for (int i = 0; i < N; ++i) {
         scanf("%d %d %d", B+i, E+i, W+i);
         int d = E[i]-B[i];
         pq.push( II(W[i], d) );
      //   fprintf(stderr, "%d\n", d);
         sum += d;
      }
   // fprintf(stderr, "sum = %d\n", sum);
      double res = 0.0;
      pq.push(II(0, X-sum));
      while (!pq.empty()) {
         II cur = pq.top();
         pq.pop();
         double tt = double(cur.second) / (cur.first + R);
      // fprintf(stderr, "%d %d %.3lf\n", cur.second, cur.first, tt);
         if (tt >= t - res - EPS) {
            tt = t - res;
            res = t;
            res += double(cur.second - tt * (cur.first + R)) / (cur.first + S);
         //   fprintf(stderr, "res = %.3lf\n", res);
            break;
         }
         res += tt;
      }
      while (!pq.empty()) {
         II cur = pq.top();
         pq.pop();
         double tt = double(cur.second) / (cur.first + S);
         res += tt;
      }
      printf("Case #%d: %.8lf\n", tc, res);
   }
   return 0;
}
