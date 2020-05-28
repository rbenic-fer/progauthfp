#include <cstdio>
#include <cstring>

using namespace std;

int a[102][102], res[102][102];
int win[102], opp[102];
long double wp[102], owp[102], oowp[102];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		printf("Case #%d:\n", i);
		memset(a, 0, sizeof(a));
		memset(win, 0, sizeof(win));
		memset(opp, 0, sizeof(opp));
		memset(wp, 0, sizeof(wp));
		memset(owp, 0, sizeof(owp));
		memset(oowp, 0, sizeof(oowp));
		int k;
		scanf("%d", &k);
		for (int x=1; x<=k; x++)
		{
			for (int y=1; y<=k; y++)
			{
				char c;
				scanf("%1s", &c);
				if (c != '.') opp[x]++;
				if (c != '.') a[x][y] = 1;
				if (c == '1') win[x]++;
				if (c == '1') res[x][y] = 1;
				if (c == '0') res[x][y] = 0;
			}
			wp[x] = (float)win[x]/opp[x];
		}
		for (int x=1; x<=k; x++)
		{
			for (int y=1; y<=k; y++)
			{
				if (a[x][y]) owp[x] += (float)(0.0+win[y]-res[y][x])/(opp[y]-1);
			}
			owp[x] /= opp[x];
		}
		for (int x=1; x<=k; x++)
		{
			for (int y=1; y<=k; y++)
			{
				if (a[x][y]) oowp[x] += owp[y];
			}
			oowp[x] /= opp[x];
			//printf("%llf*.25 + %llf*.5 + %llf*.25 =\n", wp[x], owp[x], oowp[x]);
			printf("%.8llf\n", 0.25*wp[x]+0.5*owp[x]+0.25*oowp[x]);
		}
	}
	return 0;
}
