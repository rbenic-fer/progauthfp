// Author: Makis Arsenis <marsenis@gmail.com>
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i < y; i++)
#define MAX 1005

using namespace std;

int d, n, k[MAX], s[MAX];

/*
bool check(double v) {
   double T = D / v;
   rep(i, 0, n)
      if ( (d-k[i])/s[i] > T )
}
*/

void solve(int testcase) {
   scanf("%d%d", &d, &n);
   double a, b;
   rep(i, 0, n) {
      scanf("%d%d", &k[i], &s[i]);
      //a = min(a, s[i]);
      //b = max(b, (double)d / (d-k[i]) * s[i]);
   }

   /*
   while (fabs(a - b) > 1e-6) { //check
      double c = (a+b)/2.0;
      if (check(c)) a = c;
      else b = c;
   }
   */
   double T = 0;
   rep(i, 0, n) T = max(T, (d-k[i])/(double)s[i]);

   printf("Case #%d: %lf\n", testcase, d/T);
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) solve(t);
	return 0;
}
