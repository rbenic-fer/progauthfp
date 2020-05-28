#include<stdio.h>

int main(){
	int n,i,add,j,k,sum,x;
	char str[1005];
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	for(scanf("%d",&n),i=0;i<n;i++){
	
		scanf("%d",&x);
		scanf("%s",str);
		
		add=0;
		sum=0;
		
		for(j=0;j<=x;j++){
			
			if(sum<j){
				add+=(j-sum);
				sum=j;
			}
			sum+= (str[j]-'0');
		}
		
		printf("Case #%d: %d\n",i+1,add);
		
	}

	return 0;
}