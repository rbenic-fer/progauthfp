#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int v[202], p[202];
int c, d;

int max(int a, int b)
{
	if (a>b) return a;
	else return b;
}

bool check(long long n)
{
	long long last = p[0]-n-d;
	for (int i=0; i<c; i++)
	{
		if (max(last+d, p[i]-n)+(v[i]-1)*d > n+p[i]) return 0;
		else last = max(last+d, p[i]-n)+(v[i]-1)*d;
	}
	return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d %d", &c, &d);
        d *= 2;
        for (int j=0; j<c; j++)
		{
			scanf("%d %d", &p[j], &v[j]);
			p[j] *= 2;
		}
		long long hi = 1<<30, lo = 0;
		long long m;
		long long out = 1<<30;
		hi *= 1000000;
		out *= 1000000;
		while (hi != lo)
		{
			m = (hi+lo)/2;
			if (check(m))
			{
				//printf("%d\n", m);
				out = m;
				hi = m;
			} else {
				//printf("%d not ok\n", m);
				lo = m+1;
			}
		}
		printf("Case #%d: %lf\n", i, (double)out/2.0);
    }
    return 0;
}
