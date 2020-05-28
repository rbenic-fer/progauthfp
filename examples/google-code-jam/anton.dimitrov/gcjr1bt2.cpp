#include <cstdio>
#include <algorithm>

using namespace std;

int c;
int n;
int k;
int b;
int t;

struct Chick {
	int loc;
	int speed;
};

Chick arr[54];

int main() {

	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &c);

	for (int gi = 1; gi <= c; gi++) {
		scanf("%d %d %d %d", &n, &k, &b, &t);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i].loc);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i].speed);
		}

		int ans = 0;
		int slow_cnt = 0;
		int passed = 0;
		for (int i = n - 1; i >= 0; i--) {
			int tn = (b - arr[i].loc) / arr[i].speed;
			if ((b - arr[i].loc) % arr[i].speed > 0) {
				tn++;
			}

			if (tn > t) {
				slow_cnt++;
			}
			else {
				ans += slow_cnt;
				passed++;
				if (passed == k) {
					break;
				}
			}
		}

		if (passed == k) {
			printf("Case #%d: %d\n", gi, ans);
		}
		else {
			printf("Case #%d: IMPOSSIBLE\n", gi);
		}
	}

	return 0;
}
