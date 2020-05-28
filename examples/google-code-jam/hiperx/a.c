#include <stdio.h>

int n,k;

int main() {
  int ntests, nt;
  int bits;

  scanf(" %d", &ntests);
  for(nt=1 ; nt<=ntests ; nt++) {
    scanf(" %d %d", &n, &k);

    bits = 0;
    while(n--)
      bits |= 1 << n;

    printf("Case #%d: ", nt);
    if((k & bits) == bits) printf("ON\n");
    else printf("OFF\n");
  }

  return 0;
}
