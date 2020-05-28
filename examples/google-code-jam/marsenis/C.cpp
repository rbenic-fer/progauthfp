// Author: Makis Arsenis <marsenis@gmail.com>
#include <bits/stdc++.h>
#define MAX 105
#define rep(i, x, y) for (int i = x; i < y; i++)

using namespace std;

typedef long long ll;

ll e[MAX], s[MAX], n, q, edge[MAX];
double dp[MAX];

void solve(int testcase) {
   scanf("%lld%lld", &n, &q);
   if (q != 1) exit(1);
   rep(i, 1, n+1)
      scanf("%lld%lld", &e[i], &s[i]);
   ll tmp;
   rep(i, 1, n+1)
      rep(j, 1, n+1)
         if (i+1 == j) scanf("%lld", &edge[j]);
         else scanf("%lld", &tmp);
   scanf("%lld%lld", &tmp, &tmp);

   dp[1] = 0;
   for (int i = 2; i <= n; i++) {
      dp[i] = 1e20;
      ll dist = edge[i];
      for (int j = i-1; j >= 1; j--) {
         double t = dist / (double) s[j];
         if ( dist <= e[j] ) dp[i] = min(dp[i], dp[j] + t);
         dist += edge[j];
      }
   }

   printf("Case #%lld: %lf\n", testcase, dp[n]);
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) solve(t);
	return 0;
}
