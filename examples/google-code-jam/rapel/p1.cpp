#include<bits/stdc++.h>
using namespace std;

bool checks[11];

int main()
{
	int test,temp;
	long long in;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		scanf("%lld",&in); getchar();
		if(in==0)printf("Case #%d: INSOMNIA\n",a);
		else
		{
			int k=10;
			long long m=0;
			memset(checks,false,sizeof(checks));
			while(k!=0)
			{
				m++;
				long long temp=m*in;
				while(temp!=0)
				{
					if(checks[temp%10]==false)
					{
						k--;
						checks[temp%10]=true;
					}
					temp=temp/10;
				}
			}
			printf("Case #%d: %lld\n",a,m*in);
		}
	}
}
