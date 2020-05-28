#include<stdio.h>

int main(){
	int i,j,k,t;
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	double c,f,x,add=0,sum=0,plus,inc;
	for(scanf("%d",&t),k=1;k<=t;k++){
		scanf("%lf%lf%lf",&c,&f,&x);
		sum = x/2.0;
		add=0;
		plus=0;
		inc=2.0;
		while(1){
			
			add+=c/inc;
			inc+=f;
			plus = add + x/inc;
			if(sum>plus){
				sum = plus;
			}else break;
		}
		
		printf("Case #%d: %.7lf\n",k,sum);
		
	}
	return 0;
}
