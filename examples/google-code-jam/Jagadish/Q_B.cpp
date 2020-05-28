#include<stdio.h>
#include<iostream>
#include<string.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MEM(v,z) memset(v,z, sizeof(v));

int main(){
	int test = 0, N = 0, S = 0, p = 0, input[101] = {0};
	int count = 1, max_count = 1;
	int sum[59] = {0};
	int is_repeat[59] = {0};
	int repeat_max[31] = {-1}, non_repeat_max[31] = {-1};
	int to_compare[101] = {0}, to_permut[101]= {0};
	for(int i = 0; i<=10; i++){
		for(int j = i; j<=i+2 && j<=10; j++){
			for(int k = j; k<=i+2 && k<=10; k++){
				sum[count] = i+j+k;
				
				if(k== i+2){
					 is_repeat[count] = 1;
					 repeat_max[sum[count]] = k;
				}
				else non_repeat_max[sum[count]] = k;
/*
printf("#%d sum = %d %d %d %d is_repeat = %d max = %d\n",count,sum[count],i,j,k,is_repeat[count], (is_repeat[count]==1)?repeat_max[sum[count]]:non_repeat_max[sum[count]]);
*/
				count++;
				
			}
		}
	}
	sort(sum, sum +58);
/*
	for(int i = 0; i<59; i++)
	printf("%d\n",sum[i]);
*/	
	for(int i = 0; i<101; i++)
		to_permut[i] = i;
	scanf("%d\n",&test);
//	printf("Test = %d\n",test);
	for(int x = 1; x <= test; x++){
		scanf("%d %d %d",&N, &S, &p);
//		printf("N = %d S = %d p = %d\n",N, S, p);
		for(int i = 0; i<N; i++){
			scanf("%d",&input[i]);
		}
/*
		for(int i = 0; i<N; i++){
			printf("input[%d] = %d\n",i, input[i]);
		}
*/
		max_count = 0;
		count = 0;
		for(int i = 0; i<N; i++){
			if(non_repeat_max[input[i]] >= p){
				max_count++;
			}
		}
		for(int num_repeat = 1; num_repeat <= S; num_repeat++){

			MEM(to_compare,0);
			for(int i = N-num_repeat;(i<N); i++){
				to_compare[i] = 1;
			}
/*
			for(int i = 0; i<N; i++) printf("%d",to_compare[i]);
			printf("\n");
*/
			do{
				count = 0;
				for(int i = 0; i<N; i++){
					if(to_compare[to_permut[i]] == 1){
						switch(input[i]){
							case 0: case 1: case 29: case 30: if(non_repeat_max[input[i]]>= p){
												count ++;
												}
											  break;
							default: if(repeat_max[input[i]]>= p){
									count++;
								 }
								 break;
						}
					}
					else{
						if(non_repeat_max[input[i]]>= p){
							count++;
						}
					}
				}
				if(count> max_count) max_count = count;
			}while(next_permutation(to_permut, to_permut+N));
		}
		printf("Case #%d: %d\n",x,max_count);
	}
			
	return(0);
}
