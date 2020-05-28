#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
   int tests, i;
   long double c, f, x, k;

   scanf("%d", &tests);
   for (int t = 1; t <= tests; t++) {
      long double sol = 1000000;

      scanf("%Lf %Lf %Lf", &c, &f, &x);

      for (i = 0, k = 0; k < sol; k += c / (2 + i*f), i++) {
         long double tmp = k + x / (2 + i*f);
         sol = min(sol, tmp);
      }

      //printf("%d\n", i);
      printf("Case #%d: %.7Lf\n", t, sol);

   }
   return 0;
}
