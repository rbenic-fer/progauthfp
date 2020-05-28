/*
 *  Google Code Jam 2008
 *  Round 3 - Problem D - Endless Knight
 */


#include <stdio.h>
#include <string.h>

#define INPUT_FILE	"input.txt"
#define OUTPUT_FILE	"output.txt"
#define MAXN		128
#define NUM			10007


int T;
long H, W, R, Sol;
long A[MAXN][MAXN];



bool Inside(int r, int c)
{
	return (r >= 1 && r <= H && c >= 1 && c <= W);
}

void Solve()
{
	int i, j;


	A[1][1] = 1;

	for (i = 1; i <= H; i++)
		for (j = 1; j <= W; j++)
			if (A[i][j] != -1)
			{
				if (Inside(i - 2, j - 1) && A[i - 2][j - 1] != -1)
					A[i][j] += A[i - 2][j - 1] % NUM;

				if (Inside(i - 1, j - 2) && A[i - 1][j - 2] != -1)
					A[i][j] += A[i - 1][j - 2] % NUM;
			};

	Sol = A[H][W] % NUM;
}


int main()
{
	int i, j, l, c;


	freopen(INPUT_FILE, "rt", stdin);
	freopen(OUTPUT_FILE, "wt", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		scanf("%ld %ld %ld\n", &H, &W, &R);

		memset(A, 0, sizeof(A));
		for (j = 0; j < R; j++)
		{
			scanf("%ld %ld\n", &l, &c);
			A[l][c] = -1;
		}

		Solve();

		printf("Case #%d: %ld\n", i, Sol);

	}

	fclose(stdout);
	fclose(stdin);


	return 0;
}
