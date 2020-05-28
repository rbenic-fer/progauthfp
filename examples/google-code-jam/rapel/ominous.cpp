#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int test,x,r,c;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		bool stats=true;
		scanf("%d %d %d",&x,&r,&c);
		if(x==1) stats=true;
		else if(x==2)
		{
			if((r*c)%2!=0) stats=false;
		}
		else if(x==3)
		{
			if(r<2) stats=false;
			if(c<2) stats=false;
			if((r*c)%3!=0) stats=false;
		}
		else if(x==4)
		{
			if(r<3) stats=false;
			if(c<3) stats=false;
			if((r*c)%4!=0) stats=false;
		}
		else if(x==5)
		{
			if(r<4) stats=false;
			if(c<4) stats=false;
			if((r*c)%5!=0) stats=false;
		}
		else if(x==6)
		{
			if(r<5) stats=false;
			if(c<5) stats=false;
			if((r*c)%6!=0) stats=false;
		}
		else stats=false;
		if(stats) printf("Case #%d: GABRIEL\n",a);
		else printf("Case #%d: RICHARD\n",a);
	}
}
