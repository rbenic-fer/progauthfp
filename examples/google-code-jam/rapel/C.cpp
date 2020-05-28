#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

bool dp[150][150][150][150];

queue<pair<pair<int,pair<int,int> >,pair<int,int> > > q;

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int hd,ad,hk,ak,b,d;
		memset(dp,false,sizeof(dp));
		scanf("%d %d %d %d %d %d",&hd,&ad,&hk,&ak,&b,&d);
		dp[hd][ad][hk][ak] = true;
		while(!q.empty()) q.pop();
		q.push(mp(mp(1,mp(hd,ad) ), mp(hk,ak)));
		int step = -1;
		while(!q.empty())
		{
			int st = q.front().ff.ff;
			int hn = q.front().ff.ss.ff;
			int an = q.front().ff.ss.ss;
			int he = q.front().ss.ff;
			int ae = q.front().ss.ss;
			//printf("step: %d hnow: %d anow: %d hnemy: %d anemy: %d\n",st,hn,an,he,ae);
			q.pop();
			int nhn,nan,nhe,nae;
			nhe = he - an;
			if(nhe<=0)
			{
				step = st;
				break;
			}
			else
			{
				nhn = hn - ae;
				if(nhn>0)
				{
					if(dp[nhn][an][nhe][ae]==false)
					{
						dp[nhn][an][nhe][ae]=true;
						q.push(mp(mp(st+1,mp(nhn,an) ), mp(nhe,ae)));
					}
				}
			}
			nhe = he;
			nan = an + b;
			nhn = hn - ae;
			if(nhn>0)
			{
				if(dp[nhn][nan][nhe][ae]==false)
				{
					dp[nhn][nan][nhe][ae]=true;
					q.push(mp(mp(st+1,mp(nhn,nan) ), mp(he,ae)));
				}
			}
			nhn = hd - ae;
			if(nhn > 0)
			{
				if(dp[nhn][an][nhe][ae]==false)
				{
					dp[nhn][an][nhe][ae]=true;
					q.push(mp(mp(st+1,mp(nhn,an) ), mp(he,ae)));
				}
			}
			nae = max(0,ae - d);
			nhn = hn - nae;
			if(nhn > 0)
			{
				if(dp[nhn][an][nhe][nae]==false)
				{
					dp[nhn][an][nhe][nae]=true;
					q.push(mp(mp(st+1,mp(nhn,an) ), mp(he,nae)));
				}
			}
		}
		if(step!=-1) printf("Case #%d: %d\n",tc,step);
		else printf("Case #%d: IMPOSSIBLE\n",tc);
	}
}
