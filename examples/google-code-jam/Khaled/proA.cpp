#include<stdio.h>

#define MAX 4
int a[MAX][MAX],b[MAX][MAX];

int main(){
	int n,t,x,y,i,add,pos,j,k;
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);	
	
	for(scanf("%d",&t),k=1;k<=t;k++){
		
		scanf("%d",&x);
		
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				scanf("%d",&a[i][j]);
			
		
		
		scanf("%d",&y);
		
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				scanf("%d",&b[i][j]);
			
		add=0;
		x--;
		y--;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[x][i] == b[y][j]){
					add++;
					if(add==1){
						pos = a[x][i];
					}
				}
			}
		}
		printf("Case #%d: ",k);
		if(add==1) printf("%d\n",pos);
		if(add==0) printf("Volunteer cheated!\n");
		if(add>1)  printf("Bad magician!\n");
	}
	return 0;
}
