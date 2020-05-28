#include<bits/stdc++.h>
using namespace std;

int dp[2][730][730];

struct Point{
	int l,r,idx;
}p[250];

int n;

bool cmp(Point a,Point b)
{
	return a.l < b.l;
}

bool search(int pe,int c)
{
	for(int a=0;a<n;a++)
	{
		if(p[a].l < c && p[a].r >= c)
		{
			if(pe==p[a].idx) return true;
			return false;
		}
		if(p[a].l >= c) return false;
	}
}

int compute(int pe,int l,int r)
{
	if(l+r==1440) return 0;
//	if(l > 720 || r > 720) {
//		return 1000000;
//	}
	if(search(pe,l+r)==true) return 1000000;
	if(dp[pe][l][r]!=-1) return dp[pe][l][r];
	int &ans = dp[pe][l][r];
	ans = 10000000;
	if(pe==0)
	{
		ans = min(ans,min(compute(pe,l+1,r),compute(1^pe,l+1,r) + 1));
	}
	else
	{
		ans = min(ans,min(compute(pe,l,r+1),compute(1^pe,l,r+1) + 1));
	}
	return ans;
}

bool region(int l,int r)
{
	if(l<720 && r<720) return true;
	if(l>720 && r>720) return true;
	return false;
}

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		memset(dp,-1,sizeof(dp));
		int ac,aj;
		scanf("%d %d",&ac,&aj);
		n = ac + aj;
		for(int a=0;a<ac;a++)
		{
			scanf("%d %d",&p[a].l,&p[a].r);
			p[a].idx = 0;
		}
		for(int a=0;a<aj;a++)
		{
			scanf("%d %d",&p[a + ac].l,&p[a+ac].r);
			p[a + ac].idx = 1;
		}
		sort(p,p+n,cmp);
		int ans = 2;
		if(n==2 && ac==1 &&region(p[0].r,p[1].l)==true) ans = 4;
		else if(n==2 && ac!=1 && p[1].r - p[0].l > 720) ans = 4;
		printf("Case #%d: %d\n",tc,ans);
	}
}
