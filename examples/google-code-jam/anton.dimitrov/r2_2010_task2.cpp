#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int n;
int misses[1030];
int tree[2060];
int price[2060];
int dp[2060][16];

int GetPrice(int node, int taken) {
	if (node >= (1 << n)) {
		if (n - taken > misses[node]) {
			return -1;
		}
		else {
			return 0;
		}
	}

	int pr11 = GetPrice(node * 2, taken);
	int pr12 = GetPrice(node * 2 + 1, taken);

	int pr21 = GetPrice(node * 2, taken + 1);
	int pr22 = GetPrice(node * 2 + 1, taken + 1);

	int pr1 = -1;
	if (pr11 != -1 && pr12 != -1) {
		pr1 = pr11 + pr12;
	}

	int pr2 = -1;
	if (pr21 != -1 && pr22 != -1) {
		pr2 = pr21 + pr22 + price[node];
	}

	if (pr1 == -1 && pr2 == -1) {
		return -1;
	}

	if (pr1 == -1) {
		return pr2;
	}

	if (pr2 == -1) {
		return pr1;
	}

	return min(pr1, pr2);
}

int main() {

	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);

	for (int gi = 1; gi <= t; gi++) {
		scanf("%d", &n);
		for (int i = 0; i < (1 << n); i++) {
			scanf("%d", &misses[(1 << n) + i]);
		}
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < (1 << i); j++) {
				scanf("%d", &price[(1 << i) + j]);
			}
		}

		int ans = GetPrice(1, 0);

		printf("Case #%d: %d\n", gi, ans);
	}

	return 0;
}
