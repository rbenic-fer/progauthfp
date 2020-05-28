#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;
typedef long long int LL;
#define MEM(v,i) memset(v,i,sizeof(v))
#define MP make_pair
#define VI vector < LL >
#define PII pair < LL , LL >
#define MAX 1000000000
vector<PII> V[1000005];
map<PII, LL> my;

LL gcd(LL x, LL y){
	if(x==0 || y == 0){
		return 1;
	}
	while(x%y!=0){
		LL temp = y;
		y = x%y;
		x = temp;
	}
//	cout<<y<<endl<<flush;
	return(y);
}

int find_p_q(LL xp, LL xq, int x){
	int i = 0, result = 0;
	bool flag = true;
	LL p = xp, q = xq;
//	cout<<"Start of p = "<<xp<<" and q = "<<xq<<endl<<flush;
	if(xp == 0|| xp == xq){
		return(0);
	}
	for(i = x ; i<=40 && flag == true; i++){
		if(2*p-q>=0){
			result = i;
			LL x1 = gcd(2*p-q,q);
			p = (2*p-q)/x1;
			q = q/x1;
			if(find_p_q(p,q,i+1)!=-1){
				flag = true;
				break;
			}
			else{
				flag = false;
				break;
			}
		}
		LL x1 = gcd(2*p,q);
		p = 2*p/x1;
		q = q/x1;
//		cout<<p<<" "<<q<<endl<<flush;
	}
//	cout<<"End of p = "<<xp<<" and q = "<<xq<<" with result = "<<result<<endl<<flush;

	if(flag == true && i<=40){
		return(result);
	}
	else return(-1);
}	

int main(){
	int test = 0, N = 0;
	int i = 0;
	LL p = 0, q = 0;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%lld/%lld",&p,&q);
//		printf("%lld %lld\n",p,q);
//		cout<<p<<" "<<q<<endl<<flush;
		LL x = gcd(p,q);
		p = p/x;
		q = q/x;
//		printf("%lld %lld\n",p,q);
		int result = 0;
		result = find_p_q(p,q,1);
		if(result != -1){
			printf("Case #%d: %d\n",x_test,result);
		}
		else printf("Case #%d: impossible\n",x_test);
	}
	return(0);
}
