// using dev cpp 4.9.9.2
#include<stdio.h>
#include<algorithm>

using namespace std;

#define SIZE 1009

struct node{
	int index, num, prs;	
};


node arr[SIZE];
int flag[SIZE];

bool comp(const node &a, const node &b){
	return a.num > b.num;
}
int main(){
	int n,p,l,k,i,j,x;
	long long int res;
	bool impos;
	
	freopen("A-large.in","r",stdin);
	freopen("alarge.out","w",stdout);
	
	scanf("%d",&n);
	
	for(x = 1; x<=n; ++x){
		scanf("%d%d%d",&p,&k,&l);
		
		for(i=0; i<l; ++i){
			scanf("%d",&arr[i].num);
			arr[i].index = i;
			arr[i].prs = 0;
		}
		
		sort(arr,arr+l,comp);
		for(i=0; i<k; ++i){
			flag[i] = p;
		}
		
		impos = 0;
		res = 0;
		i = 0;
		while(1){
			impos = 1;
			for(j=0; j<k; ++j){
				if(flag[j]){
					flag[j]--;
					res += (p-flag[j]) * arr[i].num;
					++i;
					impos = 0;
					if(i==l) break;					
				}
			}
			if(i==l) break;
			if(impos) break;
		}
		
		printf("Case #%d: ",x);
		if(impos){
			puts("Impossible");
		}
		else {
			printf("%I64d\n",res);
		}
	}
	
	//scanf(" ");
	
	return 0;
}
