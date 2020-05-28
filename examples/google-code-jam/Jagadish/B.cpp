#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<stack>
 
using namespace std;
 
#define MEM(v,i) memset(v,i,sizeof(v))

int main(){
	int test = 0;
	int N = 0, i = 0, j  = 0, flag = true;
	string s;
	int a[20];
	scanf("%d",&test);
	for(int xtest = 1; xtest<=test; xtest++){
		printf("Case #%d: ",xtest);
		cin>>s;
		N = s.length();
		MEM(a,0);
		for(i = 0; i<N; i++){
			if(s[i]=='0'){
				a[i] = 0;
			}
			else{
				a[i] = s[i]-'0';
			}
		}
		for(i = 0;i<N-1 && a[i]<=a[i+1];i++);
		if(i==N-1){
			cout<<s<<endl<<flush;
			continue;
		}
		if(i<N){
			for(j = i+1;j<N;j++){
				a[j] = 9;
			}
			for(j = i;j>=0; j--){
				a[j]--;
				if(j>0){
					if(a[j-1]<=a[j]){
						break;
					}
					else{
						a[j] = 9;
					}
				}
			}
		}
		if(a[0]>0){
			printf("%d",a[0]);
		}
		for(i = 1;i<N;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return(0);
}