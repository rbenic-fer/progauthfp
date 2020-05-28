#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 1000;

int x[maxn],y[maxn];
int n;
long long ans;

int main()
{
	freopen("output.txt","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		ans = 2147483647000000ll;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&x[i]);
		for(int i=0;i<n;i++) scanf("%d",&y[i]);
		sort(y,y+n);
		do
		{
			long long t = 0;
			for(int i=0;i<n;i++) t+= x[i]*y[i];
			if(t<ans) ans=t;
		}
		while(next_permutation(y,y+n));
		printf("Case #%d: %I64d\n",test,ans);
	}
	return 0;
}
