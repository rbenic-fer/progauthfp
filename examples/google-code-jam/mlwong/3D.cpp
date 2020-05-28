#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char c[102], c2[102];

int main() {
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		memset(c, 0, sizeof(c));
		scanf(" %s", c);
		int l = strlen(c);
		int cnt = 0;
		printf("Case #%d: ", i);
		for (int j=0; j<l; j++) if (c[j] == '?') cnt++;
		for (int j=0; j<(1<<cnt); j++) {
			//printf("%d\n", j);
			int j2 = j;
			long long a = 0;
			for (int k=0; k<l; k++) {
				if (c[k] == '?') {
					a = 2*a+j2%2;
					j2 /= 2;
				} else {
					a = 2*a+c[k]-'0';
				}
			}
			j2 = j;
			long long x = (int)(sqrt(a)+0.01);
			if (x*x == a) {
				for (int k=0; k<l; k++) {
					if (c[k] == '?') {
						printf("%d", j2%2);
						j2 /= 2;
					} else {
						printf("%c", c[k]);
					}
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
