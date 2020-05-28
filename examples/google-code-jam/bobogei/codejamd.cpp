#include<stdio.h>
#include<memory.h>
#include<algorithm>
//
using namespace std;
//
int ip[12345],st[12345],rk[12345];
bool vt[12345];
//
bool spcmp(int i1,int i2)
{
	return ip[i1]<ip[i2];
}
//
int main()
{
	freopen("test/dl.in","r",stdin);
	freopen("test/dl.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ii=0;ii<T;ii++)
	{
		memset(ip,0,sizeof(ip));
		memset(st,0,sizeof(st));
		memset(rk,0,sizeof(rk));
		memset(vt,0,sizeof(vt));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",ip+i);
			st[i]=i;
		}
		sort(st,st+n,spcmp);
		for(int i=0;i<n;i++)
		{
			rk[st[i]]=i;
		}
		int a,ans=0,tt,st;
		for(int i=0;i<n;i++)
		{
			if(!vt[i])
			{
				a=0;
				tt=i;
				while(!vt[tt])
				{
					a++;
					vt[tt]=true;
					tt=rk[tt];
				}
				if(a>1)
				{
					//puts("yii");
					ans+=a;
				}
			}
		}
		double fff=ans;
		printf("Case #%d: %.6f\n",ii+1,fff);
	}
}
