#include <cstdio>
bool YN;
long long T,P,Q,GCD,p,q,temp,total=0,i;
long long gcd(long long P,long long Q){
	if (Q==0){
		return P;
	} else {
		return gcd(Q,P%Q);
	}
}
int main (){
	freopen("A-large.in","r",stdin);
	freopen("A-large-practice.out","w",stdout);
	scanf("%I64d",&T);
	for (i=1;i<=T;i++){
		scanf("%I64d/%I64d\n",&P,&Q);
		GCD=gcd(P,Q);
		P/=GCD;
		Q/=GCD;
		YN=1;
		temp=Q;
		while (temp!=1){
			if (temp%2==1) YN=0;
			temp/=2;
		}
		if (YN==1){
			total=1;
			p=1;
			q=2;
			while (p*Q>q*P){
				total++;
				q*=2;
			}
			printf("Case #%I64d: %I64d\n",i,total);
		} else {
			printf("Case #%I64d: impossible\n",i);
		}
	}
	return 0;
}
