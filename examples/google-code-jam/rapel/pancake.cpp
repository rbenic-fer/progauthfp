#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int p[10005];

int cek(int a)
{
	int b=0;
	while(b*b<=a)
	{
		b++;
	}
	b--;
	return b;
}

int main()
{
	int test,banyak,x;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int ans=10000,time=0;
		scanf("%d",&banyak);
		int l=0;
		for(int b=0;b<banyak;b++)
		{
			scanf("%d",&p[b]);
		}
		sort(p,p+banyak);
		ans=p[banyak-1];
		if(p[banyak+l-1]>3)
		{
			while(p[banyak+l-1]>3)
			{
				x=p[banyak+l-1];
				p[banyak+l-1]/=2;
				l++;
				p[banyak+l-1]=x-p[banyak+l-2];
				time++;
				sort(p,p+banyak+l);
				ans=min(ans,time+p[banyak+l-1]);
			}
		}
		else ans=p[banyak-1];
		printf("Case #%d: %d\n",a,ans);
	}
}
