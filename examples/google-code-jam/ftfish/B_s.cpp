#include<cstdio>
#include<cstdlib>
int C,m,n,a;
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&C);
	for(int tn=1;tn<=C;tn++)
	{
		scanf("%d%d%d",&n,&m,&a);
		bool f=1;
		printf("Case #%d: ",tn);
		for(int i=0;i<=n&&f;i++)
			for(int j=0;j<=m&&f;j++)
				for(int p=i;p<=n&&f;p++)
					for(int q=0;q<=m&&f;q++)
					{
						if(i==p&&j==q)continue;
						for(int x=p;x<=n&&f;x++)
						{
							if(p==i)
							{
								if(abs((j-q)*(x-p))==a)
								{
									printf("%d %d %d %d %d %d\n",i,j,p,q,x,0);
									f=0;
								}
								continue;
							}
							if(((x-p)*(j-q)-a)%(p-i)==0)
							{
								int t=((x-p)*(j-q)-a)/(p-i);
								if(q+t>=0&&q+t<=m)
									printf("%d %d %d %d %d %d\n",i,j,p,q,x,q+t),f=0;
								else if(q-t>=0&&q-t<=m)
									printf("%d %d %d %d %d %d\n",i,j,p,q,x,q-t),f=0;
							}
						}
					}
		if(f)puts("IMPOSSIBLE");
	}
	return 0;
}
