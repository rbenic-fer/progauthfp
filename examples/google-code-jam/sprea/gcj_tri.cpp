#include<stdio.h>
#include<assert.h>

int main(){
	int i,j,k;
	int x1,y1,x2,y2,x3,y3,t1,t2,t3,temp;
	int n,m,A,c,x,flag;
	int ct;
	
	freopen("bsm.in","r",stdin);
	freopen("bsm.out","w",stdout);
	
	scanf("%d",&c);
	for(x=1; x<=c; ++x){
		scanf("%d%d%d",&n,&m,&A);
		
		flag = 0;
		ct = 0;
		for(x1 = 0; x1<=n; ++x1){
			for(y1 = 0; y1 <=m; ++y1){
				for(x2 = x1+1; x2<=n; ++x2){
					for(y2 = 0; y2<=m; ++y2){
						for(x3 = x2; x3<=n; ++x3){
							t1 = x1*y2 - x2*y1;
							t2 = x3*y2;
							t3 = x3*y1;
							temp = t1 - t2 + t3;
							
							t1 = A - temp;
							ct++;
//							printf(">>%d\n",ct);
							if((x2-x1) && (t1 % (x2-x1) == 0) ){
								//flag = 1;
								y3 = t1 / (x2-x1);
								if(y3 <=m){
									flag = 1;
									goto hell;
								}
								
							}/*
							t1 = -A - temp;
							if(t1 % (x2-x1) == 0){
								flag = 1;
								assert(0);
								goto hell;
							}*/
						}
					}
				}
			}
		}
		
		hell:
			
		printf("Case #%d: ",x);
		if(flag){
			printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);
		}
		else {
			puts("IMPOSSIBLE");
		}
	}
	
//	scanf(" ");
	return 0;
}
