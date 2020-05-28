#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
int T, A, B, cnt[MAXN];
char s[10];
bool check(int &x)
{
	sprintf(s, "%d", x);
	int len = strlen(s), n = len/2;
	for (int i = 0; i < n; i++) if (s[i] != s[len-i-1])
		return 0;
	return 1;
}
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	for (int i = 1; i <= 1000; i++)
	{
		cnt[i] = cnt[i-1];
		int r = sqrt(i);
		if (r*r == i && check(i) && check(r))
			cnt[i]++;
	}
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d\n", cas, cnt[B]-cnt[A-1]);
	}
	return 0;
}
