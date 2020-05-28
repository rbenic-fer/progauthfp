#include<stdio.h>
#include<string.h>

int main(){
	freopen("/home/khaled/Downloads/B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n,a,b,k,i,x,y,add,t;
	
	for(scanf("%d",&t),i=1;i<=t;i++){
		scanf("%d%d%d",&a,&b,&k);
		add=0;
		for(x=0;x<a;x++){
			for(y=0;y<b;y++){
				n = x&y;
				if(n<k){
					add++;
				}
			}
		}
		
		printf("Case #%d: %d\n",i,add);
	}
	return 0;
}
