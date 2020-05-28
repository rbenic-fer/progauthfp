// using dev cpp 4.9.9.2
#include<stdio.h>
#include<string.h>

#define SIZE 500009

const int mod = 1000000007;
int arr[SIZE], sub[SIZE], cum[SIZE],a[1009];

int main(){
	int t,n,m,i,j,x,res,flag;
	long long X,Y,Z;
	
	freopen("csmall.in","r",stdin);
	freopen("csmall.out","w",stdout);
	
	scanf("%d",&t);
	
	for(x = 1; x<=t; ++x){
		scanf("%d%d%I64d%I64d%I64d",&n,&m,&X,&Y,&Z);
		
		for(i=0; i<m; ++i){
			scanf("%d",&a[i]);
		}
		for(i=0; i<n; ++i){
			arr[i] = a[i%m];
			// A[i mod m] = (X * A[i mod m] + Y * (i + 1)) mod Z
			a[i%m] = ((X * a[i%m])%Z + Y *(i+1)) % Z;
//			printf(">>>%d\n",arr[i]);
		}
		
		memset(sub,0,sizeof(sub));
		memset(cum,0,sizeof(cum));
		
		res = 1;
		sub[0] = cum[0] = 1;
		
		for(i=1; i<n; ++i){
			sub[i] = 1;
			flag = 1;
			for(j=i-1; j>=0; --j){
				if(arr[j]<arr[i]){
					sub[i]+= sub[j];
					sub[i] %= mod;
					if(flag) {
						cum[i] = (1+2*cum[j]) % mod;
						flag = 0;
					}		
				}		
			}
			if(flag) cum[i] = 1;
	//		printf("::%d\n",sub[i]);
			res += sub[i];
			res %= mod;
		}
		
		printf("Case #%d: %d\n",x,res);
	}
	
//	scanf(" ");
	
	return 0;
}
