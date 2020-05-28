#include <cstdio>
#define MAX 100
/*should change*/

using namespace std;

int main() {
	int t, z, n, l, h, i, j;
	int H[MAX];

	scanf("%d", &t);
	for (z=1; z<=t; z++) {
		scanf("%d%d%d", &n, &l, &h);
		for (i=1; i<=n; i++) scanf("%d", &H[i]);
		
		for (j=l; j<=h; j++) {
			for (i=1; i<=n; i++) if ( j % H[i] != 0 && H[i] % j != 0 ) break;
			if ( i == n + 1 ) { printf("Case #%d: %d\n", z, j); break; }
		}
		if (j == h+1) printf("Case #%d: NO\n", z);
	}
	return 0;
}

