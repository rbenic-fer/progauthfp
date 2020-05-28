#include <bits/stdc++.h>
#define MAX 55

using namespace std;

double p[MAX];

void solve(int testcase) {
   int n, k;
   double u;
   scanf("%d%d", &n, &k);
   scanf("%lf", &u);
   for (int i = 0; i < n; i++)
      scanf("%lf", &p[i]);
   if (n != k) return;
   sort(p, p+n);
   p[n] = 1.0;
   for (int i = 0; i <= n; i++) {
      if ( u <= 1e-7 ) break;
      double dx = (p[i+1] - p[i]);
      double DX = dx*(i+1);
      if (DX < u) {
         for (int j = 0; j <= i; j++)
            p[j] = p[i+1];
         u -= DX;
      } else {
         for (int j = 0; j <= i; j++)
            p[j] += u / (i+1);
         break;
      }
   }
   /*
   for (int i = 0; i < n; i++)
      printf("%lf\n", p[i]);
   */
   double s = 1.0;
   for (int i = 0; i < n; i++)
      s *= p[i];
   printf("Case #%d: %.7lf\n", testcase, s);
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++)
      solve(t);
	return 0;
}
