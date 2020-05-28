/*
 * Google Code Jam 2011
 * Qualifying Round - Problem D - GoroSort
 */

#include <stdio.h>
#include <vector>

#define INPUT	"D-large.in"
#define OUTPUT	"D-large.out"
#define MAXN	1024

int N, T;
std::vector<int> Perm, Pos;


void ReadData()
{
	int i;

	scanf("%d", &N);

	Perm.resize(N + 1, 0);
	Pos.resize(N + 1, 0);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &Perm[i + 1]);
		Pos[Perm[i + 1]] = i + 1;
	}
}

void Solve()
{
	int i;
	double sol = 0;

	for (i = 1; i <= N; i++)
	{
		/* bring i on the i'th position */
		if (Pos[i] != i)
		{
			/* freeze other N - 2 elements and swap i with Perm[Pos[i]] */
			sol ++;
			/*sol += 2;
			Perm[Pos[i]] = Perm[i];
			Pos[Perm[i]] = Pos[i];
			Pos[i] = i;
			Perm[i] = i;*/
		}
	}

	if (sol == 1)
		sol = 0;
	printf("%.6lf\n", sol);
}


int main()
{
	int i;

	freopen(INPUT, "rt", stdin);
	scanf("%d\n", &T);

	freopen(OUTPUT, "wt", stdout);
	for (i = 1; i <= T; i++)
	{
		ReadData();
		printf("Case #%d: ", i);
		Solve();
	}

	return 0;
}