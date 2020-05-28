#include <cstdio>
#include <cstring>

using namespace std;

int brt;
int n;
long long a,b,c,d;
long long x0,y0;
long long m;
long long types[3][3];
long long ans;
int vals[3][2];

void solve(int lev)
{
	if (lev == 3)
	{
		int sx = 0;
		int sy = 0;
		for(int i = 0; i < 3; i++)
		{
			sx += vals[i][0];
			sy += vals[i][1];
		}

		if (sx % 3 == 0 && sy % 3 == 0)
		{
			long long res = 1;
			
			for (int i = 0; i < 3; i++)
			{
				int br = 0;
				for (int j = 0; j < i; j++)
					if (vals[i][0] == vals[j][0] && vals[i][1] == vals[j][1])
						br++;

				if (br == 0)
					res *= types[vals[i][0]][vals[i][1]];
				else if (br == 1)
				{
					res *= (types[vals[0][0]][vals[0][1]] - 1);
					res /= 2;
				}
				else if (br == 2)
				{
					res *= (types[vals[0][0]][vals[0][1]] - 2);
					res /= 3;
				}
			}

			ans += res;
		}
		return;
	}


	if (lev == 0)
	{
		for(int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				vals[lev][0] = i;
				vals[lev][1] = j;
				solve(lev + 1);
			}
	}
	else
	{
		for(int i = vals[lev-1][0]; i < 3; i++)
		{
			int beg = 0;
			if (i == vals[lev-1][0])
				beg = vals[lev-1][1];
			for (int j = beg; j < 3; j++)
			{
				vals[lev][0] = i;
				vals[lev][1] = j;
				solve(lev + 1);
			}
		}
	}
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("task1.out", "w", stdout);

	scanf("%d", &brt);

	for (int gi=1; gi<=brt; gi++)
	{
		scanf("%d %lld %lld %lld %lld %lld %lld %lld", &n, &a, &b, &c, &d, &x0, &y0, &m);
		
		memset(types, 0, sizeof(types));

		types[x0%3][y0%3]++;

		for(int i = 1; i < n; i++)
		{
			x0 = (x0 * a + b) % m;
			y0 = (y0 * c + d) % m;
			types[x0%3][y0%3]++;
		}

		ans = 0;
		solve(0);

		printf("Case #%d: %lld\n", gi, ans);
	}

	return 0;
}
