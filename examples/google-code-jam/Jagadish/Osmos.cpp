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
	int x = 0, test =  0, A = 0, N = 0;
	int i = 0;
	int array[1000];
	int min = 0, max = N;
	scanf("%d",&test);
	for(x = 1; x<=test; x++){
		scanf("%d %d",&A,&N);
		MEM(array,0);
		for(i = 0; i<N; i++){
			scanf("%d",&array[i]);
		}
		sort(array,array+N);
/*
		for(i = 0; i<N; i++){
			cout<<array[i]<<" "<<flush;
		}
		cout<<endl<<flush;
*/
		min = 0, max = N;
		for(i = 0; i<N; i++){
			if(A>array[i]){
				A+= array[i];
			}
			else{
				if(i+1==N){
					min++;
					break;
				}
				int temp = array[i] +1 - A;
				if(temp<A){
					// increment the min count
					min++;
					A+=A-1;
					A+= array[i];
				}
				else{
					if(A==1){
						min += N-i;
						break;
					}
					else{
						int count = 0;
						while(array[i]>=A){
							A+= A-1;
							count++;
						}
						//cout<<"count = "<<count<<endl<<flush;
						if(count < N-i){
							min += count;
							
						}
						else{
							min += N-i;
							break;
						}
						A+= array[i];
					}
				}
			}
			//cout<<min<<" "<<A<<endl<<flush;
		}
		printf("Case #%d: %d\n",x,min);
	}
	return(0);
}
