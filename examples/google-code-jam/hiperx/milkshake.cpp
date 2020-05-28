#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

using namespace std;

typedef pair< int,int > ii;
#define num first
#define flav second

#define MAXn 10
#define MAXm 100

int n,m;
int milk[MAXn];

ii pref[MAXm][MAXn];
int q[MAXm];

int main(){
  int nt,nt0;
  int i,j,k, ok,blz,deu;

  scanf(" %d", &nt0);
  for(nt=1 ; nt<=nt0 ; nt++){
    scanf(" %d %d", &n, &m);

    for(i=0 ; i<m ; i++){
      scanf(" %d", &q[i]);
      for(j=0 ; j<q[i] ; j++){
	scanf(" %d %d", &pref[i][j].num, &pref[i][j].flav);
	pref[i][j].num--;
      }
    }

    deu=0;
    for(i=0 ; i<=n && !deu ; i++){ /*numero de flavoured milk shakes*/
      for(j=0 ; j<i ; j++) milk[n-j-1]=1;
      for(j=i ; j<n ; j++) milk[n-j-1]=0;

      do{
	ok=1;

	for(j=0 ; j<m ; j++){
	  blz=0;

	  for(k=0 ; k<q[j] ; k++)
	    if(milk[ pref[j][k].num ]==pref[j][k].flav){
	      blz=1;
	      break;
	    }

	  if(!blz){ ok=0; break; }
	}

	if(ok){ deu=1; break; }
      } while(next_permutation(milk,milk+n));
    }

    printf("Case #%d: ", nt);
    if(!deu) puts("IMPOSSIBLE");
    else{
      for(i=0 ; i<n ; i++) printf("%d ", milk[i]);
      putchar('\n');
    }
  }

  return 0;
}
