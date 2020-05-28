#include<stdio.h>
#include<stdlib.h>

int compare(const void* p1,const void* p2);

int main(void){
  short t,tc;
  int i,j,k,ans1,ans2,N;
  double ken[1000],naomi[1000];
  
  scanf("%hd",&t);
  for(tc=0;tc<t;tc++){
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%lf",naomi+i);
    for(i=0;i<N;i++) scanf("%lf",ken+i);
    qsort(naomi,N,sizeof(double),compare);
    qsort(ken,N,sizeof(double),compare);

    
    ans1=ans2=0;
    for(i=0;i<N;i++){
      if(ans1<N && naomi[ans1]>ken[i]){
	ans1++;
      }
    }
    
    /*calc ans2*/
    for(i=k=N-1;i>=0 && k>=0;i--,k--){
      while(k>=0 && ken[k]<naomi[i]) k--;
      if(k<0) break;
    }
    //printf("%d\n",i);
    ans2=i+1;
    printf("Case #%hd: %d %d\n",tc+1,ans1,ans2);
  }
  return 0;
}

int compare(const void* p1,const void* p2){
  double n1,n2;
  n1=*((const double *)p1);
  n2=*((const double *)p2);
  return (n2>n1)?1:-1;
}
