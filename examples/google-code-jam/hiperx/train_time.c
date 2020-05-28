#include <stdio.h>
#include <stdlib.h>
#define MAX 200

int t, na,nb;
int tai[MAX],taf[MAX]; /*tempo de A inicial e final, em minutos*/
int tbi[MAX],tbf[MAX]; /*tempo de B inicial e final, em minutos*/

int cmp(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int main(){
  int nt0,nt;
  int i,j, aux1,aux2, na2,nb2;

  scanf(" %d", &nt0);
  for(nt=1 ; nt<=nt0 ; nt++){
    scanf(" %d %d %d", &t, &na, &nb);

    /*le os tempos de A*/
    for(i=0 ; i<na ; i++){
      scanf(" %d:%d", &aux1, &aux2);
      tai[i]=60*aux1+aux2;

      scanf(" %d:%d", &aux1, &aux2);
      taf[i]=60*aux1+aux2;
    }

    /*le os tempos de B*/
    for(i=0 ; i<nb ; i++){
      scanf(" %d:%d", &aux1, &aux2);
      tbi[i]=60*aux1+aux2;

      scanf(" %d:%d", &aux1, &aux2);
      tbf[i]=60*aux1+aux2;
    }

    qsort(tai,na,sizeof(int),cmp);
    qsort(taf,na,sizeof(int),cmp);

    qsort(tbi,nb,sizeof(int),cmp);
    qsort(tbf,nb,sizeof(int),cmp);

    na2=na; nb2=nb;
    for(i=j=0 ; i<na && j<nb ; i++)
      if(tai[i]>=tbf[j]+t){ na2--; j++; }

    for(i=j=0 ; i<nb && j<na ; i++)
      if(tbi[i]>=taf[j]+t){ nb2--; j++; }

    printf("Case #%d: %d %d\n", nt, na2,nb2);
  }

  return 0;
}
