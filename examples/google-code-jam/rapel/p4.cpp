#include<bits/stdc++.h>
using namespace std;

long long ppw(int a,int b)
{
	long long ans=1;
	while(b!=0)
	{
		b--;
		ans*=a;
	}
	return ans;
}

int main()
{
	int test;
	int k,r,c;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		scanf("%d %d %d",&k,&r,&c);
		printf("Case #%d:",a);
		for(int b=1;b<=c;b++)
			printf(" %d",b);
		printf("\n");
	}
}
