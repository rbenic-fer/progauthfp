#include <cstdio>
#include <cstring>

using namespace std;

int l, t, n, c;
int a[1002];
int v[1000002];
int min;

void check()
{
	int r = 0;
	for (int i=0; i<n; i++)
	{
		if (v[i] == 0) r += a[i%c]*2;
		else {
			if (t <= r) r += a[i%c];
			else if (t >= r+a[i%c]*2) r += a[i%c]*2;
			else r = t + a[i%c] - (t-r)/2;
		}
	}
	if (r < min) min = r;
}


int main()
{
	int x;
	scanf("%d", &x);
	for (int i=1; i<=x; i++)
	{
		memset(v, 0, sizeof(v));
		min = 2147483647;
		scanf("%d %d %d %d", &l, &t, &n, &c);
		for (int j=0; j<c; j++) scanf("%d", &a[j]);
		if (l == 0) check();
		if (l == 1)
		{
			for (int j=0; j<n; j++)
			{
				v[j] = 1;
				check();
				v[j] = 0;
			}
		}
		if (l == 2)
		{
			for (int j=0; j<n; j++)
			for (int k=j+1; k<n; k++)
			{
				v[j] = v[k] = 1;
				check();
				v[j] = v[k] = 0;
			}
		}
		printf("Case #%d: %d\n", i, min);
		fprintf(stderr, "Case #%d: %d\n", i, min);
	}
	return 0;
}
