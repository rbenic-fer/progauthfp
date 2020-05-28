/*
 *  Google Code Jam 2009
 *  Round 2 - Problem A - Crazy Rows
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <time.h>

using namespace std;

#define INPUT_FILE		"input.txt"
#define OUTPUT_FILE		"output.txt"

int N;
char A[64][64], B[64][64];
int Sol, S[1024], Flag[1024];


void back(int sol)
{
	int i, j;


	if (sol == N)
	{
		for (i = 0; i < N; i++)
			strcpy(B[i], A[S[i]]);

		int bsol = 1;
		for (i = 0; i < N; i++)
			for (j = i + 1; j < N; j++)
			if (B[i][j] == '1')
			{
				bsol = 0;
				i = j = 1000;
			};

		if (!bsol)
			return;

		// count inversions
		int sol = 0;
		for (i = 0; i < N; i++)
			for (j = i + 1; j < N; j++)
				if (S[i] > S[j])
					sol++;

		if (sol < Sol)
			Sol = sol;
	}
	else
	for (i = 0; i < N; i++)
		if (!Flag[i])
		{
			Flag[i] = 1;
			S[sol] = i;

			back(sol + 1);

			Flag[i] = 0;
		}
}

int main()
{
	int i, ii, ntests;

	freopen(INPUT_FILE, "rt", stdin);
	freopen(OUTPUT_FILE, "wt", stdout);

	scanf("%d", &ntests);

	for (ii = 1; ii <= ntests; ii++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%s\n", &A[i]);

		Sol = 99999;
		back(0);

		printf("Case #%d: %d\n", ii, Sol);
	}

	fclose(stdout);
	fclose(stdin);
}
