#include<stdio.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

int main(void){
  short t,s,p,n,num[31];
  short i,j,k,sums;

  scanf("%hd",&t);
  for(i=1;i<=t;i++){
    for(j=0;j<31;j++) num[j]=0;
    scanf("%hd %hd %hd",&n,&s,&p);
    for(j=0;j<n;j++){
      scanf("%hd",&k);
      num[k]++;
    }
    sums=0;
    for(j=30;(j+2)/3>=p && j>=0;j--) sums+=num[j];
    if(j>=3) sums+=MIN(s,num[j]+num[j-1]);
    printf("Case #%hd: %hd\n",i,sums);
  }
  return 0;
}

    
