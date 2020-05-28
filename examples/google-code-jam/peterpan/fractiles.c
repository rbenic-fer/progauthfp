#include <stdio.h>

#define min(X,Y) ((X)<(Y)?(X):(Y))

int main()
{
	int T,tcase,K,C,S,i,j;
	long long pos;


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d %d %d",&K,&C,&S);
		printf("Case #%d:",tcase);
		if(K > C*S)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for(i=1;i<=K;i+=C)
		{
			pos = 1;
			for(j=i;j<i+C;j++)
				pos = K*(pos-1)+min(j,K);
			printf(" %lld",pos);
		}
		printf("\n");
	}

	return 0;
}

