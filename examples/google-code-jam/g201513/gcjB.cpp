#include<stdio.h>
#include<string.h>

const int maxn = 100;

int t;
int cnt;
int g[1000][100];
int ans;
int n,m,x,y;

int cntt(int x)
{
	int ret=0;
	while(x)
	{
		if(x%2==1) ret++;
		x/=2;
	}
	return ret;
}

int main()
{
	freopen("B.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		memset(g,-1,sizeof(g));
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&cnt);
			while(cnt--)
			{
				scanf("%d%d",&x,&y); x--;
				if(g[i][x]!=-1)g[i][x]=-2; else g[i][x] = y;
			}
		}
		ans=-1; int opt = 2000;
		for(int i=0;i<(1<<n);i++)
		{
			if(cntt(i)>=opt) continue;
			bool okk = true;
			for(int k=0;k<m;k++)
			{
				bool ok = false;
				for(int j=0;j<n;j++)
					if(g[k][j]>=0 && (g[k][j]==0 && (i&(1<<j))==0 || g[k][j]==1 && (i&(1<<j))!=0 ) ) ok=true;
				if(!ok) okk=false;
			}
			if(okk)
			{
				opt = cntt(i);
				ans = i;
			}
		}
		printf("Case #%d: ",test);
		if(ans==-1) printf("IMPOSSIBLE\n");
		else 
		{
			for(int i=0;i<n;i++)
			{
				if((ans&(1<<i))==0) printf("0");
				else printf("1");
				if(i==n-1)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
