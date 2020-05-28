#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int abs(int x)
{
	if(x>0)
		return x;
	return -x;
}

int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}

int main()
{
	int i,T,N,tcase,P[MAXN],sec,bpos,opos,bfree,ofree,trans;
	char R[MAXN];
	
	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%c",R+i);
			scanf("%c",R+i);
			scanf("%d",P+i);
		}
		sec=0;
		bpos=1;
		opos=1;
		bfree=0;
		ofree=0;
		for(i=0;i<N;i++)
		{
			if(R[i]=='B')
			{
				trans=max(0,abs(P[i]-bpos)-bfree);
				if(trans==0 && ofree==-1)
					trans++;
				sec+=trans;
				bpos=P[i];
				bfree=-1;
				ofree+=trans;
			}
			else if(R[i]=='O')
			{
				trans=max(0,abs(P[i]-opos)-ofree);
				if(trans==0 && bfree==-1)
					trans++;
				sec+=trans;
				opos=P[i];
				ofree=-1;
				bfree+=trans;
			}
			else
				fprintf(stderr,"\nWrong reading of input!\n");
		}
		if(N>0)
			sec++;
		printf("Case #%d: %d\n",tcase,sec);
	}

	return 0;
}
