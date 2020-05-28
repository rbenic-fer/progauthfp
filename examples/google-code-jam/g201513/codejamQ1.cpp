#include<stdio.h>

int ntest;
int n,k;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d%d",&n,&k);
		printf("Case #%d: ",test);
		if((k+1)%(1<<n)==0) puts("ON");
		else puts("OFF");
	}
	return 0;
}
