/*
 * Google Code Jam 2011
 * Qualifying Round - Problem B - Magicka
 */

#include <stdio.h>
#include <string.h>
#include <string>

#define INPUT	"input.txt"
#define OUTPUT	"output.txt"

int T, N;
char S[128];
char C[256][256];
char D[256][256];


void ReadData()
{
	int i, nr;
	char s[4];

	memset(C, 0, sizeof(C));
	memset(D, 0, sizeof(D));

	/* combinations */
	scanf("%d ", &nr);
	for (i = 0; i < nr; i++)
	{
		scanf("%s", &s);
		C[s[0]][s[1]] = C[s[1]][s[0]] = s[2];
	}

	/* oppositions */
	scanf("%d ", &nr);
	for (i = 0; i < nr; i++)
	{
		scanf("%s", &s);
		D[s[0]][s[1]] = D[s[1]][s[0]] = 1;
	}
	scanf("%d %s\n", &N, &S);
}

int Solve()
{
	int i, j;
	char ch;
	std::string sol = "";
	bool cleared;

	for (i = 0; i < N; i++)
	{
		ch = S[i];

		/* ch is invoked */

		/* first one, just add it */
		if (sol.size() == 0)
		{
			sol.push_back(ch);
			continue;
		}

		/* ch combines with the previous char */
		if (C[ch][sol[sol.size() - 1]] > 0)
		{
			/* last 2 characters combine */
			sol[sol.size() - 1] = C[ch][sol[sol.size() - 1]];
			continue;
		}

		cleared = false;
		/* ch does not combine, maybe it's opposite to some char? */
		for (j = 0; j < sol.size(); j++)
			if (D[ch][sol[j]] > 0)
			{
				sol.clear();
				cleared = true;
				break;
			};
		if (cleared)
			continue;

		/* finally, if none of the above, we just add it */
		sol.push_back(ch);
	}

	printf("[");

	for (i = 0; i < sol.size(); i++)
	{
		if (i == 0) 
			printf("%c", sol[i]);
		else
			printf(", %c", sol[i]);
	}

	printf("]\n");

	return 0;
}


int main()
{
	int i;

	freopen(INPUT, "rt", stdin);
	scanf("%d\n", &T);

	//freopen(OUTPUT, "wt", stdout);
	for (i = 1; i <= T; i++)
	{
		ReadData();
		printf("Case #%d: ", i);

		Solve();
	}

	return 0;
}