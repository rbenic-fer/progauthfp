#include<stdio.h>

int A;
int n,m;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d%d%d",&n,&m,&A);
		bool ok = false;
		fprintf(stderr,"%d\n",test);
		printf("Case #%d: ",test);
		for(int x = 0; x <= n; x++)
			for(int y = 0; y <= m; y++)
			{
				if(x*m<A && n*y<A) continue;
				if(x==0 && y==0) continue;
				if(x==0)
				{
					int d = 0, c = A/y;
					if(c>=0 && c<=n && c * y == A)
					{
						printf("0 0 %d %d %d %d\n",x,y,c,d);
						goto ok;
					}
				}
				else
				{
					for(int c = 0; c<=n ; c++)
					{
						if((A + y * c) % x != 0) continue;
						int d = (A + y * c) / x; 
						if(d>=0 && d<=m) 
						{
							printf("0 0 %d %d %d %d\n",x,y,c,d);
							goto ok;
						}
						d = -d;
						if(d>=0 && d<=m) 
						{
							printf("0 0 %d %d %d %d\n",x,y,c,d);
							goto ok;
						}
					}
				}
			}
		printf("IMPOSSIBLE\n");
ok:;
	}
	return 0;
}
