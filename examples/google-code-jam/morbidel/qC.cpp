/*
 * Google Code Jam 2011
 * Qualifying Round - Problem C - Candy Splitting
 */

#include <stdio.h>

#define MAXN	1024
#define INPUT	"C-large.in"
#define OUTPUT	"C-large.out"

int T, N, Min;
int C[MAXN];


void ReadData()
{
	int i;

	scanf("%d ", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d ", &C[i]);
	}
}

long Solve()
{
	int i, sum_xor, sum;

	sum_xor = sum = 0;
	Min = 1000000;

	/* the smallest pile can contain just one value from the vector. See the minimum */
	for (i = 0; i < N; i++)
	{
		sum_xor ^= C[i];
		sum += C[i];

		if (C[i] < Min)
			Min = C[i];
	}

	/* no solution if the xor of all vector is 0 [why?] */
	if (sum_xor != 0)
	{
		return -1;
	}

	return sum - Min;
}


int main()
{
	int i, sol;

	freopen(INPUT, "rt", stdin);
	scanf("%d\n", &T);

	freopen(OUTPUT, "wt", stdout);
	for (i = 1; i <= T; i++)
	{
		ReadData();
		printf("Case #%d: ", i);
		
		sol = Solve();

		if (sol == -1)
			printf("NO\n");
		else
			printf("%d\n", sol);
	}

	return 0;
}