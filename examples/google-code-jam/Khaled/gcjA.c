#include<stdio.h>

int main(){


	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	
	int a[10],n,x,counter,digit,i,k;
	long long m;
	
	scanf("%d",&n);
	
	for(k=1;k<=n;k++){
	
		for(i=0;i<10;i++) a[i]=0;
		
		scanf("%d",&x);
	
		if(x==0){ printf("Case #%d: INSOMNIA\n",k); continue;}
		
		int add=0;
		counter = 1;
		
		while(1){
			m = counter;
			m*=x;
			
			while(m){
				
				digit = m%10;
				if(!a[digit]){ add++; a[digit]++;}
				
				
				m/=10;
				
			}
			if(add==10) break;
			counter++;
		}
		
		m = counter;
		m*=x;
		printf("Case #%d: %lld\n",k,m);
	}
	
	return 0;
}
