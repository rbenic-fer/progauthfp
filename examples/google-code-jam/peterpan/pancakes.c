#include <stdio.h>
#include <string.h>

#define MAX_S_LENGTH 100

int main()
{
	int T,tcase,flips,S_length,i;
	char S[MAX_S_LENGTH+1],current;


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		flips = 0;
		scanf("%s",S);
		S_length = strlen(S);
		current = '+';
		for(i=S_length-1;i>=0;i--)
			if(S[i]!=current)
			{
				current=S[i];
				flips++;
			}
		printf("Case #%d: %d\n",tcase,flips);
	}

	return 0;
}

