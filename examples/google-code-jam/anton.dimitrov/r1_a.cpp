#include <cstdio>
#include <algorithm>

int t;

int main() {

	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &t);

	for (int gi = 1; gi <= t; gi++) {
		long long n;
		int pd, pg;
		scanf("%lld %d %d", &n, &pd, &pg);
		printf("Case #%d: ", gi);

		if ((pd < 100 && pg == 100) || (pd > 0 && pg == 0)) {
			printf("Broken\n");
			continue;
		}

		if (pd == 0 && pg == 0) {
			printf("Possible\n");
			continue;
		}

		int div = 100;
		int tmp = pd;
		for (int i = 0; i < 2; i++) {
			if (tmp % 2 == 0) { 
				tmp /= 2; div /= 2; 
			}
			if (tmp % 5 == 0) {
				tmp /= 5; div /= 5;
			}
		}
		int all = 0;
		if (div <= n) {
			all = div;
		}
		else {
			printf("Broken\n");
			continue;
		}
		int x = all * pd / 100;
		int y = all - x;
		int z = (100-pg) * x - pg * y;
		bool found = false;
		int iter = 0;
		while (z + iter * (100 - pg) < 0) iter += pg;
		for (int i = iter; i < iter + pg; i++) {
			if ((z + i * (100 - pg)) % pg == 0) {
				found = true;
				break;
			}
		}
		if (found) {
			printf("Possible\n");
		}
		else {
			printf("Broken\n");
		}
	}

	return 0;
}
