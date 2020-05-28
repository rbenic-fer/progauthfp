#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int C, D, N;
char combine[100][5];
char opposite[100][5];
char rune[500];
char cast[500];
int total;
int COUNT[50];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int ntest;
	scanf("%d",&ntest);
	for(int test=1; test<=ntest; test++)
	{
		scanf("%d", &C);
		for(int i=0;i<C;i++)
			scanf("%s",&combine[i]);
		scanf("%d", &D);
		for(int i=0;i<D;i++)
			scanf("%s",&opposite[i]);
		scanf("%d", &N);
		scanf("%s",&rune);

		memset(COUNT, 0, sizeof(COUNT));
		total = 0;
		for(int i=0; i<N; i++)
		{
			cast[total++] = rune[i];
			COUNT[cast[total-1] - 'A']++;
			for(int i=0; i<C; i++)
				if(combine[i][0] == cast[total-1] && combine[i][1] == cast[total-2]
				|| combine[i][1] == cast[total-1] && combine[i][0] == cast[total-2])
				{
					COUNT[cast[total-1] - 'A']--;
					COUNT[cast[total-2] - 'A']--;
					total--;
					cast[total-1] = combine[i][2];
					COUNT[cast[total-1] - 'A']++;
					break;
				}

			for(int i=0; i<D; i++)
			{
				if(COUNT[opposite[i][0]-'A'] && COUNT[opposite[i][1]-'A'])
				{
					memset(COUNT, 0, sizeof(COUNT));
					total = 0;
					break;
				}
			}
		}

		printf("Case #%d: [", test);
		for(int i=0; i<total; i++)
		{
			printf("%c", cast[i]);
			if(i != total-1) printf(", ");
		}
		printf("]\n");
	}

	return 0;
}