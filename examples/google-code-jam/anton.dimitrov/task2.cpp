#include <cstdio>
#include <cstring>

using namespace std;

int brt;
int a,b,p;
int brp;
int primes[1004];
int brcp;
int curp[1004];
int comp[1004];
int tmpbr;
int tmp[1004];
int leftC[1004];

void calcPrimes()
{
	brp = 0;
	for(int i=2;i<1000;i++)
	{
		bool check = true;
		for(int j=2;j*j <= i; j++)
		{
			if (i % j == 0)
			{
				check = false;
				break;
			}
		}

		if (check)
			primes[brp++] = i;
	}
}

int getRoot(int v)
{
	int cur = v;

	tmpbr = 0;
	while(cur != comp[cur])
	{
		tmp[tmpbr++] = cur;
		cur = comp[cur];
	}

	for(int i = 0; i < tmpbr; i++)
		comp[tmp[i]] = cur;

	return cur;
}

void merge(int v1, int v2)
{
	int r1 = getRoot(v1);
	int r2 = getRoot(v2);

	comp[r2] = r1;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("task2.out", "w", stdout);

	scanf("%d", &brt);

	calcPrimes();

	for(int gi = 1; gi <= brt; gi++)
	{
		scanf("%d %d %d", &a, &b, &p);

		for(int i = a; i <= b; i++)
			comp[i] = i;

		for(int i = a; i <= b; i++)
		{
			brcp = 0;
			for (int j = 0; j < brp; j++)
			{
				if (primes[j] >= p && i % primes[j] == 0)
					curp[brcp++] = primes[j];
			}

			for (int j = i+1; j <= b; j++)
			{
				for (int k = 0; k < brcp; k++)
				{
					if (j % curp[k] == 0)
						merge(i, j);
				}
			}
		}

		memset(leftC, 0, sizeof(leftC));

		for (int i = a; i <= b; i++)
		{
			int root = getRoot(i);
			leftC[root] = 1;
		}

		int ans = 0;

		for(int i = a; i <= b; i++)
			if (leftC[i])
				ans++;

		printf("Case #%d: %d\n", gi, ans);
	}

	return 0;
}
