/*
Problem A. Standing Ovation
*/

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
	int test = 0, N = 0, S[100010];
	int i = 0;
	int count = 0, result = 0;
	string str;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%d ",&N);
		cin>>str;
		MEM(S,0);
		for(i = 0; i<str.length(); i++){
			S[i] = str[i]-'0';
		}
/*
		for(i = 0;i<=N; i++){
			cout<<S[i]<<endl<<flush;
		}
*/
		count = 0;
		count += S[0];
		result = 0;
		for(i = 1; i<=N; i++){
			if(S[i]>0 && i>count){
				result += i-count;
				count += S[i] + result;
			}
			else count += S[i];
		}
		printf("Case #%d: %d\n",x_test,result);
	}
	return(0);
}
