#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int prime[1009], prim[1000],ct = 0;

void pgen(){
	int i,j;
	
	for(i=2; i<=1000; ++i){
		if(!prime[i]){
			prim[ct++] = i;
			for(j = i*i; j<=1000; j+=i){
				prime[j] = 1;
			}
		}
	}
}

int parent[1009];
set<int> s;
int find_s(int i){
	if(i!=parent[i]) parent[i] = find_s(parent[i]);
	return parent[i];
}

int main(){
	int i,j,n,c,a,b,p,x,res;
	bool flag[1009];
	
	pgen();
	
	freopen("bs.in","r",stdin);
	freopen("bs.out","w",stdout);
	
	scanf("%d",&c);
	for(x = 1; x<=c; ++x){
		scanf("%d%d%d",&a,&b,&p);
		
		res = b-a+1;
		
		memset(flag,0,sizeof(flag));
		for(i=0; i<1009; ++i) parent[i] = i;
		
		for(i=p; i<=b; ++i){
			if(!prime[i]){
				for(j = a; j<=b; ++j){
					//if(j==i || flag[j]) continue;
					if(j%i==0){
						parent[find_s(j)] = i;
					//	flag[j] = true;
						//res--;
					}
				}
			}
		}
		
		s.clear();
		res = 0;
		for(i=a; i<=b; ++i) {
			if(s.find(parent[find_s(i)])==s.end()){
				s.insert(parent[find_s(i)]);
				res++;
			}
		}
		
		
		printf("Case #%d: %d\n",x,res);
	}
	
//	scanf(" ");
	
	return 0;
}
