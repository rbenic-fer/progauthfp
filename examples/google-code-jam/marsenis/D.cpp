#include <cstdio>

using namespace std;

int main() {
   int T, k, c, s;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d%d%d", &k, &c, &s);
      printf("Case #%d:", t);
      if (k > s) printf(" IMPOSSIBLE\n");
      else if (k == 1) printf(" 1\n");
      else {
         long v = 0, x = 1;
         for (int i = 0; i< c-1; i++) x *= k;
         for (int i = 0; i < k; i++)
            printf(" %ld", i*x + 1 + i*(x-1)/(k-1));
         printf("\n");
      }
   }
	return 0;
}
