#include<stdio.h>

int main(void){
  char Board[4][5],emptyline[16];
  int t,now,i,j,k,cases,win,count;

  for(scanf("%d%*c",&t),cases=1;cases<=t;cases++){
    for(i=0;i<4;i++) scanf("%4s%*c",Board[i]);
    win=4;
    count=0;

    //puts("first check");
    for(i=0;i<4;i++){
      for(now=0;now<2;now++){
	count=0;
	for(j=0;j<4;j++){
	  if(Board[i][j]=='T') count++;
	  else if(now==0 && Board[i][j]=='O') count++;
	  else if(now==1 && Board[i][j]=='X') count++;
	}
	if(count==4){
	  win=now;
	  break;
	}
      }
      if(win<2) break;
    }

    //puts("Second check");
    if(win>=2){
      for(i=0;i<4;i++){
	for(now=0;now<2;now++){
	  count=0;
	  for(j=0;j<4;j++){
	    if(Board[j][i]=='T') count++;
	    else if(now==0 && Board[j][i]=='O') count++;
	    else if(now==1 && Board[j][i]=='X') count++;
	  }
	  if(count==4){
	    win=now;
	    break;
	  }
	}
	if(win<2) break;
      }
    }

    //puts("Third check");
    if(win>=2){
      for(now=0;now<2;now++){
	count=0;
	for(i=0;i<4;i++){
	  if(Board[i][i]=='T') count++;
	  else if(now==0 && Board[i][i]=='O') count++;
	  else if(now==1 && Board[i][i]=='X') count++;
	}
	if(count==4){
	  win=now;
	  break;
	}

	count=0;
	for(i=0;i<4;i++){
	  if(Board[i][3-i]=='T') count++;
	  else if(now==0 && Board[i][3-i]=='O') count++;
	  else if(now==1 && Board[i][3-i]=='X') count++;
	}
	if(count==4){
	  win=now;
	  break;
	}
	
	if(win<2) break;
      }
    }

    //puts("Decide Output");
    if(win==4){
      count=0;
      for(i=0;i<4;i++) for(j=0;j<4;j++) count+=(Board[i][j]=='.');
      //for(i=0;i<4;i++) for(j=0;j<4;j++) printf("%c%c",Board[i][j],j==3?'\n':' ');

      //printf("now count=%d\n",count);
      win=(count==0)?2:3;
    }

    //puts("Switch");
    switch(win){
    case 0:
      printf("Case #%d: O won\n",cases);
      break;
    case 1:
      printf("Case #%d: X won\n",cases);
      break;
    case 2:
      printf("Case #%d: Draw\n",cases);
      break;
    case 3:
      printf("Case #%d: Game has not completed\n",cases);
      break;
      /*default:
	printf("Bad case:win=%d\n",win);*/
    }
  }
  return 0;
}
