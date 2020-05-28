#include<cstdio>
#include<algorithm>
using namespace std;
struct shit
{
	int a,c;
}f[2000];
int n;
bool operator < (shit a,shit b)
{
	return (a.a<b.a);
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
		{
			scanf("%d",&f[i].a);
			f[i].c=i;
		}
		sort(f,f+n);
		int l=0,r=n-1,ans=0;
		for (int i=0;i<n;++i)
		  if (f[i].c-l<r-f[i].c)
		  	{
		  		ans+=f[i].c-l;
		  		for (int j=0;j<n;++j)
			  		if (l<=f[j].c&&f[j].c<f[i].c) ++f[j].c;
			  	f[i].c=l;
			  	++l;
		  	}
		  else
		  {
		  	ans+=r-f[i].c;
		  	for (int j=0;j<n;++j)
		  		if (f[i].c<f[j].c&&f[j].c<=r) --f[j].c;
		  	f[i].c=r;
		  	--r;
		  }
		printf("Case #%d: %d\n",TT,ans);
	}
}
