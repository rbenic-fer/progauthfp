#include <cstdio>

int t;
int n;

bool IsPure(int mask, int num) {
	while (true) {
		if ((mask & (1 << num)) > 0) {
			int cnt = 1;
			for (int i = 0; i < num; i++) {
				if ((mask & (1 << i)) > 0) {
					cnt++;
				}
			}
			if (cnt == 1) {
				return true;
			}
			num = cnt - 2;
		}
		else {
			return false;
		}
	}

	return true;
}

int main() {

	
	freopen("C-small-attempt3.in", "r", stdin);
	//freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	scanf("%d", &t);

	for (int gi = 1; gi <= t; gi++) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < (1 << (n - 1)); i++) {
			if (IsPure(i, n - 2)) {
				//printf("->> %d\n", i);
				ans++;
			}
		}
		printf("Case #%d: %d\n", gi, ans % 100003);
	}

	return 0;
}
