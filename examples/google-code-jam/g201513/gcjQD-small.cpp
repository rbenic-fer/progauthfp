#include<stdio.h>

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int ntest, n, x, ans;
	scanf("%d", &ntest);
	for(int test=1; test<=ntest; test++)
	{
		scanf("%d", &n); ans = 0;
		for(int i=1; i<=n; i++)
			scanf("%d", &x), ans+=(i!=x);
		printf("Case #%d: %d.000000\n", test, ans);
	}
	return 0;
}