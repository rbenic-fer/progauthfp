#include<cstdio>
#include<cstring>
using namespace std;
int s[2000];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		int n,x;
		scanf("%d",&n);
		memset(s,0,sizeof(s));
		for (int i=0;i<n;++i)
		{
			scanf("%d",&x);
			++s[x];
		}
		int ans=1000;
		for (int i=1000;i>0;--i)
		{
			int temp=i;
			for (int j=1000;j>i;--j)
				temp+=((j-1)/i)*s[j];
			if (temp<ans) ans=temp;
		}
		printf("Case #%d: %d\n",TT,ans);
	}
}
