/*
 *  Google Code Jam 2008
 *  Round 2 - Problem A - Cheating a Boolean Tree
 */


#include <stdio.h>

#define INPUT_FILE	"input.txt"
#define OUTPUT_FILE	"output.txt"

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAXN	10240
#define INF		1000000


int T, V, M, Sol;
bool Gates[MAXN], Ch[MAXN];								// Gates[i] = OR (0), AND (1)
int Values[MAXN];
long A[MAXN], B[MAXN];									// a[i] -> minimum changes for i-th node having 1, b[i] -> idem for having 0



void Solve()
{
	int i, j;


	Sol = 0;

	for (i = (M - 1) / 2 - 1; i >= 0; i--)
	{
		int st = i * 2 + 1;
		int dr = i * 2 + 2;

		int a_and, b_and, a_or, b_or;


		a_and = A[st] + A[dr];
		b_and = MIN(A[st] + B[dr], MIN(B[st] + A[dr], B[st] + B[dr]));

		a_or = MIN(A[st] + B[dr], MIN(B[st] + A[dr], A[st] + A[dr]));
		b_or = B[st] + B[dr];

		if (a_and > INF) a_and = INF;
		if (b_and > INF) b_and = INF;
		if (a_or > INF) a_or = INF;
		if (b_or > INF) b_or = INF;

		if (Ch[i])
		{
			if (Gates[i])
			{
				// if AND, try to change it to OR, see if we optimize some A[i], B[i]
				if (a_and > a_or + 1)
					a_and = a_or + 1;
				if (b_and > b_or + 1)
					b_and = b_or + 1;
			} else
			{
				// if OR, try to change it to AND, see if we optimize some A[i], B[i]
				if (a_or > a_and + 1)
					a_or = a_and + 1;
				if (b_or > b_and + 1)
					b_or = b_and + 1;
			}
		}

		// finally, set the values
		if (Gates[i])
			A[i] = a_and, B[i] = b_and;
		else
			A[i] = a_or, B[i] = b_or;
	}

	if (V == 1)
	{
		if (A[0] >= INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", A[0]);
	}
	else
	if (V == 0)
	{
		if (B[0] >= INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", B[0]);
	}
}


int main()
{
	int i, j, g, c;


	freopen(INPUT_FILE, "rt", stdin);
	freopen(OUTPUT_FILE, "wt", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		scanf("%d %d", &M, &V);

		for (j = 0; j < (M - 1) / 2; j++)
		{
			scanf("%d %d", &g, &c);

			Gates[j] = g;
			Ch[j] = c;
		}

		for (; j < M; j++)
		{
			scanf("%d", &Values[j]);

			A[j] = (Values[j] == 1) ? 0 : INF;
			B[j] = (Values[j] == 0) ? 0 : INF;
		}

		printf("Case #%d: ", i);

		Solve();
	}

	fclose(stdout);
	fclose(stdin);


	return 0;
}
