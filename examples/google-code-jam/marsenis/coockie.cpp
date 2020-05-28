#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
   int tests, i;
   double c, f, x, k;

   scanf("%d", &tests);
   for (int t = 1; t <= tests; t++) {
      double sol = 1000000;

      scanf("%lf %lf %lf", &c, &f, &x);

      for (i = 0, k = 0; i < 10000; k += c / (2 + i*f), i++) {
         double tmp = k + x / (2 + i*f);
         if (tmp > x / 2) break;
         sol = min(sol, tmp);
      }

      printf("Case #%d: %.7lf\n", t, sol);

   }
   return 0;
}
