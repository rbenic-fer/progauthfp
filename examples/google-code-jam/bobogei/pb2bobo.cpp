#include<stdio.h>
int main()
{
	int T=0;
	int n,s,p;
	scanf("%d",&T);
	for(int jizz=1;jizz<=T;jizz++)
	{
		scanf("%d%d%d",&n,&s,&p);
		int j=0;
		for(int i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			if((k+2)/3>=p)
			{
				j++;
			}else if(k>0&&k%3!=1&&(k+8)/3>p&&s>0)
			{
				j++;
				s--;
			}
		}
		printf("Case #%d: %d\n",jizz,j);
	}
}
