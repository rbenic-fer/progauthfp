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
	int x = 0;
	LL test = 0;
	LL N = 0, output = 0, temp = 0;
	LL i = 0;
	int array[11];
	bool flag = true;

	scanf("%lld",&test);
/*	printf("1000001\n");
	for(N = 0; N<=1000000; N++){
		printf("%lld\n",N);
	}
*/

	for(LL x_test = 1;x_test<=test; x_test++){
		MEM(array,0);
		flag = true;
		scanf("%lld\n",&N);
		if(N==0){
			printf("Case #%lld: INSOMNIA\n",x_test);
			continue;
		}
		flag = false;
		output = 0;
		for(i = 1; flag==false; i++){
			output += N;
			temp = output;
			while(temp!=0){
				array[temp%10] = 1;
				temp = temp/10;
			}
			flag = true;
			for(int x = 0; x<= 9 && flag==true; x++){
				if(array[x]==1){
					flag = true;
				}
				else flag = false;
			}
			if(flag==true){
				printf("Case #%lld: %lld\n",x_test,output);
			}
		}
	}

	return(0);
}
