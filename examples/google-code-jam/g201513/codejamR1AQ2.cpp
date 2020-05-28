#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

const int maxn = 105;

int D,I,M,N;
int a[maxn];
int dp[maxn][256];
int t[256];
const int inf = 2147483647;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d%d%d%d",&D,&I,&M,&N);
		for(int i=1;i<=N;i++) scanf("%d",&a[i]);
		int ans = inf;
		memset(dp,20,sizeof(dp));
		for(int v=0;v<256;v++) dp[0][v] = 0;
		for(int i=1;i<=N;i++)
		{
			for(int v=0;v<256;v++)
			{
				dp[i][v] = dp[i-1][v] + D;

					for(int d=-M;d<=M;d++)
						if(v+d>=0 && v+d<256 && dp[i][v] > dp[i-1][v+d] + abs(v-a[i]))
							dp[i][v] = dp[i-1][v+d] + abs(v-a[i]);
			}
			for(int v=0;v<256;v++)
			{
				for(int u=0;u<256;u++)
				{
					int d = abs(u-v);
					int cost = M==0?inf:((d+M-1)/M)*I;
					cost = min(cost,abs(u-v));
					if(dp[i][v] > dp[i][u] + cost)
						dp[i][v] = dp[i][u] + cost;
				}
			}
		}
		for(int v=0;v<256;v++) if(ans > dp[N][v]) ans = dp[N][v];
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
