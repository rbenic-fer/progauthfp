#include<stdio.h>
//
int main()
{
	freopen("test/2b.in","r",stdin);
	freopen("test/2b.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ii=0;ii<T;ii++)
	{
		int n,t;
		scanf("%d",&n);
		int min=999999999,r=0,s=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(min>t)
			{
				min=t;
			}
			r^=t;
			s+=t;
		}
		if(r!=0)
		{
			printf("Case #%d: NO\n",ii+1);
		}else
		{
			printf("Case #%d: %d\n",ii+1,s-min);
		}
	}
}
