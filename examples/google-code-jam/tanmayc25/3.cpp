#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
void call()
{
	long long minval, maxval;
	return;
}
int mul(int a, int b)
{
	arr[1][1]=1;
	arr[1][2]=2;
	arr[1][3]=3;
	arr[1][4]=4;
	arr[2][1]=2;
	arr[2][2]=-1;
	arr[2][3]=4;
	arr[2][4]=-3;
	arr[3][1]=3;
	arr[3][2]=-4;
	arr[3][3]=-1;
	arr[3][4]=2;
	arr[4][1]=4;
	arr[4][2]=3;
	arr[4][3]=-2;
	arr[4][4]=-1;
	return arr[a][b];
}
int b[1000005],c[1000005];
int main()
{
	string s1,s2;
	int t, d, x, res;
	bool flag;
	call();
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		printf("Case #%d: ",tt);
		flag=false;
		call();
		scanf("%d%d",&d,&x);
		cin >> s2;
		s1="";
		for(int i=0;i<x;i++)
			s1+=s2;
		call();
		d=s1.length();
		for(int i=0;i<d;i++)
		{
			if(i==0)
			{
				if(s1[i]-'0'==1)
					b[i]=1;
				else
					b[i]=s1[i]-'g';
				call();
			}
			else
			{
				if(s1[i]-'0'==1)
					b[i]=b[i-1];

				else
				{
					if(b[i-1]>0)
						b[i]=mul(b[i-1],s1[i]-'g');
					else
						b[i]=(-1)*mul(-1*b[i-1],s1[i]-'g');
				}
				call();
			}
		}
		call();
		for(int i=d-1;i>=0;i--)
		{
			call();
			if(i==d-1)
			{
				if(s1[i]-'0'==1)
					c[i]=1;
				else
					c[i]=s1[i]-'g';
				call();
			}
			else
			{
				if(s1[i]-'0'==1)
					c[i]=c[i+1];
				else
				{
					if(c[i+1]>0)
						c[i]=mul(s1[i]-'g',c[i+1]);
					else
						c[i]=(-1)*mul(s1[i]-'g',-1*c[i+1]);
				}
				call();
			}
		}
		call();
		for(int i=0;i<d;i++)
		{
			if(b[i]==2)
			{
				res=-10;
				call();
				for(int j=i+1;j<d;j++)
				{
					if(res==3)
					{
						if(c[j]==4)
						{
							puts("YES");
							flag=true;
							break;
						}
					}
					call();
					if(res==-10)
					{
						if(s1[j]-'0'==1)
							res=1;
						else
							res=s1[j]-'g';
					}
					else
					{
						if((s1[j]-'0')!=1 && res>0)
							res=mul(res,s1[j]-'g');
						else if((s1[j]-'0')!=1 && res<0)
							res=(-1)*mul(-1*res,s1[j]-'g');
					}
					if(flag)
						break;
				}
			}
			call();
			if(flag)
				break;
		}
		if(!flag)
			puts("NO");
		call();
	}
	return 0;
}

