#include <stdio.h>
#include <stdlib.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }

void readline()
{
	while(getchar()!='\n')
		;
}

int main()
{
	int i,j,tcase,T,N,M,res;
	int a[101][101],maxRow[101],maxCol[101];

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&N);
		scanf("%d",&M);
		res=1;
		for(i=0;i<N;i++)
		{
			maxRow[i]=0;
			for(j=0;j<M;j++)
			{
				scanf("%d",&(a[i][j]));
				if(maxRow[i]<a[i][j])
					maxRow[i]=a[i][j];
			}
		}
		for(j=0;j<M;j++)
		{
			maxCol[j]=0;
			for(i=0;i<N;i++)
				if(maxCol[j]<a[i][j])
					maxCol[j]=a[i][j];
		}
		for(i=0;i<N && res;i++)
			for(j=0;j<M;j++)
				if(a[i][j]<maxRow[i] && a[i][j]<maxCol[j])
				{
					res=0;
					break;
				}
		
		printf("Case #%d: %s\n",tcase,res?"YES":"NO");
	}

	return 0;
}
