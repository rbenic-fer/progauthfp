#include<bits/stdc++.h>
#define MOD 3628800000LL
using namespace std;


long long prime[50000];
int num[66000];
int k=0;
long long ans[15];
char in[35];
int di,mm;


void shieve()
{
	for(int a=2;a<=65537;a++)
	{
		if(num[a]==0)
		{
			prime[k]=a;
			//printf("%d\n",prime[k]); getchar();
			k++;
			long long b=a;
			long long c=b*a;
			while(c<=65537)
			{
				num[c]=a;
				b++;
				c=b*a;
			}
		}
	}
}

long long conv(int base)
{
	long long val=0;
	long long bb=1;
	int dd=di-1;
	while(dd>=0)
	{
		val=(val+(in[dd]-'0')*bb)%MOD;
		bb=(bb*base)%MOD;
		dd--;
	}
	return val;
}

long long cprime(long long temp)
{
	long long divv=0;
	for(int a=0;a<k;a++)
	{
		if(abs(temp)<=prime[a]) break;
		if(temp%prime[a]==0) return prime[a];
	}
	return divv;
}

int main()
{
	shieve();
	int test;
	scanf("%d",&test); getchar();
	for(int a=1;a<=test;a++)
	{
		scanf("%d %d",&di,&mm);getchar();
		int tot=0;
		for(int b=0;b<di;b++)
			in[b]='0';
		in[0]='1';
		in[di-1]='1';
		printf("Case #%d:\n",a);
		while(mm!=0)
		{
			bool prr=true;
			for(int b=di-2;b>0;b--)
			{
				if(in[b]>'1')
				{
					in[b]='0';
					in[b-1]=((in[b-1]-'0')+1)+'0';
				}
			}
			for(int b=2;b<=10;b++)
			{
				long long temp=conv(b);
				ans[b]=cprime(temp);
				//printf("%d %lld %lld\n",b,temp,ans[b]);
				if(ans[b]==0) prr=false;
				if(prr==false) break;
			}
			//printf("%s\n",in);
			//getchar();
			if(prr==true)
			{
				printf("%s",in);
				for(int b=2;b<=10;b++)
					printf(" %lld",ans[b]);
				printf("\n");
				mm--;
			}
			in[di-2]=((in[di-2]-'0')+1)+'0';
		}
	}
}
