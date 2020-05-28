#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[100];

int main() {
  int nt0,nt, len, i;

  scanf(" %d", &nt0);
  for(nt=1 ; nt<=nt0 ; nt++) {
    scanf(" %s", s);
    len = strlen(s);

    printf("Case #%d: ", nt);

    if(next_permutation(s,s+len)) puts(s);
    else {
      sort(s,s+len);

      for(i=len+1 ; i>0 ; i--)
	s[i] = s[i-1];
      s[0] = '0';
      len++;

      for(i=0 ; s[i]=='0' ; i++) ;
      swap(s[i], s[0]);

      puts(s);
    }
  }

  return 0;
}
