#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1005

vector<double> naomi, ken;
int sc[MAX][MAX];

int main() {
   int tests, n, i, j, score, score2;
   int nl, nr, kl, kr;

   scanf("%d", &tests);
   for (int t = 1; t <= tests; t++) {
      scanf("%d", &n);

      naomi.resize(n);
      for (i = 0; i < n; i++)
         scanf("%lf", &naomi[i]);

      ken.resize(n);
      for (i = 0; i < n; i++)
         scanf("%lf", &ken[i]);

      sort(naomi.begin(), naomi.end());
      sort(ken.begin(), ken.end());

      // Fair
      score = 0;
      j = n - 1;
      for (int k = n-1; k >= 0; k--) {
         if (naomi[k] > ken[j])
            score++;
         else
            j--;
      }

      // Deceitful
      for (int i = 0; i < n; i++)
         sc[i][i] = ( naomi[n-1] > ken[i] ) ? 1 : 0;

      for (int j = 1; j < n; j++)
         for (int i = 0; i < n - j; i++)
            if (naomi[n-j-1] < ken[i])
               sc[i][i + j] = sc[i][i+j-1];
            else if (naomi[n-j-1] > ken[i+j])
               sc[i][i + j] = sc[i+1][i+j] + 1;
            else
               sc[i][i + j] = max( 1 + sc[i+1][i+j], sc[i][i+j-1] );

      /*
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++)
            printf("%d ", sc[i][j]);
         printf("\n");
      }
      */
      printf("Case #%d: %d %d\n", t, sc[0][n-1], score);

      /*
      score2 = 0;

      nl = kl = 0;
      nr = kr = n-1;
      while (nl <= nr && kl <= kr) {
         printf("nl = %d, nr = %d, kl = %d, kr = %d\n", nl, nr, kl, kr);
         if (naomi[nr] > ken[kr])
            { score2++; nr--; kr--; }
         else
            { nl++; kr--; }
      }

   */
   }

   return 0;
}
