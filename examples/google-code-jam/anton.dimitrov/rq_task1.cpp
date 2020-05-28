#include <cstdio>

unsigned int t, n, k;

int main() {

	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%u", &t);
	for (int i = 0; i < t; i++) {
		scanf("%u %u", &n, &k);
		printf("Case #%d: ", i + 1);
		unsigned mask = (1 << n) - 1;
		if ((k & mask) == mask) {
			printf("ON\n");
		}
		else {
			printf("OFF\n");
		}
	}

	return 0;
}
