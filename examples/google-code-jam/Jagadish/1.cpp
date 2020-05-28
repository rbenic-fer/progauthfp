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

typedef long long int LL;

#define MEM(v,i) memset(v,i,sizeof(v))

double pi = 3.141592653589795;

int main(){
	int test = 0;
	int N = 0, K = 0, i = 0, j  = 0, flag = true, pos = 0;
	string s;
	LL r[10010],h[10010], T1[10010], T2[10010];
	scanf("%d",&test);
	for(int xtest = 1; xtest<=test; xtest++){
		printf("Case #%d: ",xtest);
		MEM(r,0);
		MEM(h,0);
		MEM(T1,0);
		MEM(T2,0);
		scanf("%d %d",&N,&K);
		for(i = 1; i<=N; i++){
			scanf("%lld %lld",&r[i],&h[i]);
		}
		for(i = 1; i<N; i++){
			pos = i;
			LL r1 = r[i], h1= h[i];
			for(j = i+1; j<=N; j++){
				if(r[pos]<r[j] || (r[pos]==r[j] && h[pos]<h[j])){
					pos = j;
				}
			}
			if(pos!=i){
				r[i] = r[pos];
				h[i] = h[pos];
				r[pos] = r1;
				h[pos] = h1;
			}
		}
		for(i=1; i<=N; i++){
			for(j = 1;j<=K; j++){
				if(T1[j-1]==0){
					if(r[i]*(r[i]+2*h[i])>T1[j]){
						T2[j]=r[i]*(r[i]+2*h[i]);
					}
					else T2[j] = T1[j];
				}
				else{
					if(T1[j-1]+2*r[i]*h[i]>T1[j]){
						T2[j] = T1[j-1]+2*r[i]*h[i];
					}
					else T2[j] = T1[j];
				}
			}
			for(j = 1; j<=K; j++){
				T1[j] = T2[j];
			}
		}
		double answer = (double)T1[K];
		printf("%.6llf\n",answer*pi);
	}
	return(0);
}
