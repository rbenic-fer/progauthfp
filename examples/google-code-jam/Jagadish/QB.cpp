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
	int test = 0, N = 0;
	int i = 0, len = 0;
	string s;
	char prev = '0';
	scanf("%d",&test);
	
	for(int x_test = 1;x_test<=test; x_test++){
		cin>>s;
		len = 0;
		len = s.length();
		N = 0;
		prev = '+';
		for(i = len-1; i>=0; i--){
			if(s[i]==prev){
				prev = s[i];
			}
			else{
				prev = s[i];
				N++;
			}
		}
		printf("Case #%d: %d\n",x_test,N);
	}
	return(0);
}
