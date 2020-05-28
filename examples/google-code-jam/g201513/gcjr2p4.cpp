#include<stdio.h>
#include<algorithm>

using namespace std;

int k;
char s[10000];
char t[10000];
int p[10];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d",&k);
		scanf("%s",&s);
		for(int i=0;i<k;i++)p[i]=i;
		int ans = 2147483647;
		do
		{
			int i;
			for(i=0;s[i];i+=k)
			{
				for(int j=0;j<k;j++) t[i+j] = s[i+p[j]];
			}
			int cnt = 1;
			for(i=1;s[i];i++)
			{
				if(t[i]!=t[i-1])
					cnt++;
			}
			if(ans>cnt)ans=cnt;
		}
		while(next_permutation(p,p+k));
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}