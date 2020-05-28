#include <cstdio>
#define MAX 1005

using namespace std;

void swap(int &a, int &b) { int tmp=a; a = b; b = tmp; }

int main() {
	int t, z, n, i, c, tmp;
	int a[MAX], h[MAX];

	scanf("%d", &t);
	for (z=1; z<=t; z++) {
		scanf("%d", &n);
		for (i=1; i<=n; i++) { scanf("%d", &a[i]); h[a[i]] = i; }

		c = 0;
		for (i=1; i<=n; i++) {
			if (a[i] != i) {
				tmp = a[i];
				swap(a[i], a[h[i]]);
				swap(h[tmp], h[i]);
				c+=2;
			}
		}
		printf("Case #%d: %.6lf\n", z, (double)c);
	}
	return 0;
}
