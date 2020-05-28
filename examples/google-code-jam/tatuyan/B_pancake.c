#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(X,Y) (((X)<(Y))?(Y):(X))

int comp(const void *p1,const void *p2){
  int n1,n2;
  n1=*(const int *)p1;
  n2=*(const int *)p2;
  return n2-n1;
}

int main(void){
  unsigned t,tnum,D,p[1000],num,ans,tmp;
  int i,j,k;

  scanf("%u",&tnum);
  for(t=1;t<=tnum;t++){
    memset(p,0,sizeof(p));
    scanf("%u",&D);

    for(i=0;i<D;i++) scanf("%u",p+i);
    qsort(p,D,sizeof(unsigned),comp);

    ans=p[0];
    //printf("now ans=%u\n",ans);
    for(num=MAX(p[0]/2,p[1]);num>0;num--){
      tmp=num;

      for(i=0;i<D;i++){
	if(p[i]<=num) break;
	tmp+=p[i]/num-(p[i]%num==0);
      }
      //printf("\tnow tmp=%u\n",tmp);
      if(ans>tmp) ans=tmp;
      //printf("now ans=%u\n",ans);
    }
    printf("Case #%u: %u\n",t,ans);  
  }
  return 0;
}
