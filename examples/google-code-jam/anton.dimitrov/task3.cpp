#include <cstdio>
#include <cstring>

using namespace std;

int brt;
int k;
int n;
int mas[104];
int ans[5004];

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("task3.out", "w", stdout);

	scanf("%d", &brt);

	for(int gi = 1; gi <= brt; gi++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &mas[i]);

		memset(ans, 0, sizeof(ans));

		int curp = 0;
		for (int i = 1; i <= k; i++)
		{
			for(int j = 0; j < i; j++)
			{
				while(ans[curp] != 0)
				{
					curp++;
					if (curp == k)
						curp = 0;
				}

				if (j < i-1)
				{
					curp++;
					if (curp == k)
						curp = 0;
				}
			}

			ans[curp] = i;
		}

		printf("Case #%d:", gi);
		for (int i = 0; i < n; i++)
			printf(" %d", ans[mas[i]-1]);
		printf("\n");
	}

	return 0;
}
