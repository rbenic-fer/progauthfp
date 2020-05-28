#include <bits/stdc++.h>
using namespace std;

vector<long long > bin, ans;

long long compute(long long n)
{
	if (n % 2 == 0)
		return 2;
	long long i = 3;
	while (i*i<n)
	{
		if (n%i == 0)
			return i;
		i += 2;
	}
	return n;
}

int main()
{
	//freopen("C-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	long long t, n, J, num, low, high, cnt;
	scanf("%lld", &t);
	for (long long tt = 1;tt <= t;tt++)
	{
		cnt = 0;
		printf("Case #%lld:\n", tt);
		scanf("%lld%lld", &n, &J);
		low = (1 << (n - 1));
		high = (1 << n);
		for (long long i = low;i < high;i++)
		{
			if (!(i & 1))
				continue;
			long long temp = i;
			bool ok = 1;
			bin.clear();
			while (temp)
			{
				bin.push_back(temp & 1);
				temp >>= 1;
			}
			ans.clear();
			for (long long j = 2;j <= 10;j++)
			{
				long long pw = 1;
				num = 0;
				for (long long k = 0;k < bin.size();k++)
				{
					num += pw*bin[k];
					pw *= j;
				}
				long long temp2 = compute(num);
				if (temp2 == num)
				{
					ok = 0;
					break;
				}
				ans.push_back(temp2);
			}
			if (ok)
			{
				cnt++;
				for (long long it = bin.size() - 1;it >= 0;it--)
					printf("%lld", bin[it]);
				printf(" ");
				for (int it = 0;it < ans.size();it++)
					printf("%lld ", ans[it]);
				puts("");
			}
			if (cnt == J)
				break;
		}
	}
	return 0;
}