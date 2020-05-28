#include<stdio.h>

int main(void){
  short LAWN[100][100],check[101],min1,min2,flg,cflg,now,clow[100],ccol[100];
  int i,j,k,n,m,t,cases;

  for(cases=0,scanf("%d",&t);cases<t;cases++){
    scanf("%d%d",&m,&n);
    for(i=0;i<101;i++) check[i]=0;
    for(i=0;i<m;i++){
      for(j=0;j<n;j++){
	scanf("%hd",&LAWN[i][j]);
	check[LAWN[i][j]]=1;
      }
    }
    
    do{
      for(i=0;i<m;i++) clow[i]=ccol[i]=0;

      //for(i=0;i<m;i++) for(j=0;j<n;j++) printf("%d%c",LAWN[i][j],j==n-1?'\n':' ');
      //putchar('\n');

      /*get minimums*/
      min1=min2=101;
      for(i=0;i<101;i++){
	if(check[i]==0) continue;
	if(min1>i){
	  min1=i;
	}else if(min2>i){
	  min2=i;
	  break;
	}
      }
      if(min2==101) break;
      
      cflg=0;
      /*Is there good row?*/
      for(i=0;i<m;i++){
	flg=1;
	for(j=0;j<n;j++){
	  if(LAWN[i][j]!=min1){
	    flg=0;
	    break;
	  }
	}
	if(flg==0) continue;
	cflg=1;
	clow[i]=1;
      }

      /*Is there good column?*/
      for(i=0;i<n;i++){
	flg=1;
	for(j=0;j<m;j++){
	  if(LAWN[j][i]!=min1){
	    flg=0;
	    break;
	  }
	}
	if(flg==0) continue;
	cflg=1;
	ccol[i]=1;
      }

      for(i=0;i<m;i++) for(j=0;j<n;j++) if(clow[i]==1 || ccol[j]==1) LAWN[i][j]=min2;

      /*Checking*/
      check[min1]=0;
    }while(cflg);
    
    now=LAWN[0][0],flg=0;
    for(i=0;i<m;i++){
      for(j=0;j<n;j++){
	if(LAWN[i][j]!=now){
	  flg=1;
	  break;
	}
      }
      if(flg==1) break;
    }
    if(flg==1) printf("Case #%d: NO\n",cases+1);
    else printf("Case #%d: YES\n",cases+1);
  }
  return 0;
}
  
