#include<stdio.h>

int main(void){
  short t,tc;
  int i,j,k;
  long double C,F,X;
  long double nowsum,time,time2;

  scanf("%hd",&t);
  for(tc=0;tc<t;tc++){
    scanf("%Lf%Lf%Lf",&C,&F,&X);
    k=nowsum=0;
    time2=X/2;
    do{
      time=time2;
      nowsum+=1/(2+F*k++);
      time2=nowsum*C+X/(2+F*k);
    }while(time>time2);
    printf("Case #%hd: %.7Lf\n",tc+1,time);    
  }
  return 0;
}
