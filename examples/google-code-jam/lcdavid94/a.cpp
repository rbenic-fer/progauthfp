#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		int k,cnt=0,ans=0;
		char s[2000];
		scanf("%d %s",&k,&s);
		for (int i=0;i<=k;++i)
		{
			if (i>cnt+ans) ans=i-cnt;
			cnt+=(int)(s[i])-(int)('0');
		}
		printf("Case #%d: %d\n",TT,ans);
	}
}
