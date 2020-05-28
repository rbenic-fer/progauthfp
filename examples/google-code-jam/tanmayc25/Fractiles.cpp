#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, k, c, s;
	scanf("%d", &t);
	for (int tt = 1;tt <= t;tt++)
	{
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d: ", tt);
		for (int i = 1;i <= k;i++)
			printf("%d ", i);
		puts("");
	}
	return 0;
}