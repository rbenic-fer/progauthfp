#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,x,r,c,temp;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: ",tt);
		if(r>c)
		{
			temp=r;r=c;c=temp;
		}
		temp=r*c;
		if(x==1)
			printf("GABRIEL\n");
		else if(x==2)
		{
			if((r>1 || c>1) && temp%x==0)
				printf("GABRIEL\n");
			else
				printf("RICHARD\n");
		}
		else if(temp%x!=0|| x>=(2*r+1)|| (x>=c+r-2)&& x>3)
			printf("RICHARD\n");
		else if(x>r && x>c)
			printf("RICHARD\n");
		else 
			printf("GABRIEL\n");
	}
	return 0;
}

		
