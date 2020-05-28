#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char mult(char c1,char c2);

int main(void){
  char str[10001],rep[150001],stc,nowi,nowj,nowk;
  int i,j,k,r,ansflg,s;
  unsigned tnum,t,len,L,kend;
  unsigned long long X;
  scanf("%u%*c",&tnum);

  for(t=1;t<=tnum;t++){
    ansflg=0;
    scanf("%u%llu%*c",&L,&X);
    scanf("%10000s",str);
    memset(rep,0,sizeof(rep));
    
    stc=str[0];
    for(i=1;i<L;i++) stc=mult(stc,str[i]);
    switch(stc){
    case '1':
      r=1;
      break;//out
    case '0':
      r=2;
      break;// amari=1 OK, amari=0 NO
    default:
      r=4;
      break;// amari=2 OK, 
    }
    X%=r;
    if(!((r==2 && X==1) || (r==4 && X==2))){
      printf("Case #%u: %s\n",t,"NO"); 
      continue;
    }   
    
    for(i=0;i<X;i++) strcat(rep,str);

    len=strlen(rep);
    for(i=0,nowi='1';i<len-2;i++){
      nowi=mult(nowi,rep[i]);
      if(nowi!='i') continue;
      for(j=i+1,nowj='1';j<len-1;j++){
	nowj=mult(nowj,rep[j]);
	if(nowj!='j') continue;
	for(k=j+1,nowk='1';k<len;k++) nowk=mult(nowk,rep[k]);
	if(nowk!='k') continue;
	ansflg=1;
	break;
      }
      if(ansflg==1) break;
    }
    //printf("i,j=%d,%d\n",i,j);
    printf("Case #%u: %s\n",t,ansflg?"YES":"NO"); 
  }

  return 0;
}

char mult(char c1,char c2){ // upper char and 0 is minus. (0 is minus1)
  char ans[4][5]={"1ijk","i0kJ","jK0i","kjI0"},ret;
  int n1,n2,flg=1;

  //puts("start mult");

  if(c1=='1' || c1=='0') n1=0;
  else switch(tolower(c1)){
    case 'i':
      n1=1;
      break;
    case 'j':
      n1=2;
      break;
    case 'k':
      n1=3;
      break;
    }

  if(c2=='1' || c2=='0') n2=0;
  else switch(tolower(c2)){
    case 'i':
      n2=1;
      break;
    case 'j':
      n2=2;
      break;
    case 'k':
      n2=3;
      break;
    }
  
  if(isupper(c1) || c1=='0') flg*=-1;
  if(isupper(c2) || c2=='0') flg*=-1;
  
  ret=ans[n1][n2];
  if(flg==-1){
    if(ret=='1') ret='0';
    else if(ret=='0') ret='1';
    else if(islower(ret)) ret=toupper(ret);
    else ret=tolower(ret);
  }
  return ret;
}
