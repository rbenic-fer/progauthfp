#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,f[20000],x;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		scanf("%d%d",&n,&x);
		for (int i=0;i<n;++i)
			scanf("%d",&f[i]);
		sort(f,f+n);
		int l=0,r=n-1,ans=0;
		while (l<r)
		{
		  if (f[l]+f[r]>x) {++ans;--r;}
		  else {++ans;++l;--r;}
		}
		if (l==r) ++ans;
		printf("Case #%d: %d\n",TT,ans);
	}
}
