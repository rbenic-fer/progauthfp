#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

#define MEM(v,i) memset(v,i,sizeof(v))

typedef long long int LL;

int main(){
	int test = 0, x = 0, N = 0, M = 0;
	int i = 0, j = 0;
	bool flag = true;
	scanf("%d",&test);
	int array[110][110];
	for(x = 1; x<=test; x++){
		scanf("%d %d",&N,&M);
		MEM(array,0);
		flag = true;
		for(i = 1; i<=N; i++){
			for(j = 1; j<=M; j++){
				scanf("%d",&array[i][j]);
			}
		}
/*
		for(i = 1; i<=N; i++){
			for(j = 1; j<=M; j++){
				cout<<array[i][j]<<" "<<flush;
			}
			cout<<endl<<flush;
		}
*/
		if(N==1 || M==1){
			printf("Case #%d: YES\n",x);
		}
		else{
			int row_max[110], col_max[110];
			
			for(i = 1; i<=N; i++){
				row_max[i] = array[i][1];
				for(j = 1; j<=M; j++){
					if(row_max[i]<array[i][j]){
						row_max[i] = array[i][j];
					}
				}
			}
			for(i = 1; i<=M; i++){
				col_max[i] = array[1][i];
				for(j = 1; j<=N; j++){
					if(col_max[i]<array[j][i]){
						col_max[i] = array[j][i];
					}
				}
			}
/*
			for(i = 1; i<=N; i++){
				cout<<"i = "<<i<<" row_max = "<<row_max[i]<<endl<<flush;
			}
			for(i = 1; i<=M; i++){
				cout<<"i = "<<i<<" col_max = "<<col_max[i]<<endl<<flush;
			}
*/
			for(i = 1; i<=N && flag; i++){
				for(j = 1; j<=M && flag; j++){
					if(array[i][j] <row_max[i] && array[i][j]<col_max[j]){
						flag = false;
					}
				}
			}
			if(flag)
				printf("Case #%d: YES\n",x);
			else
				printf("Case #%d: NO\n",x);
		}	
		
	}
	return(0);
}
