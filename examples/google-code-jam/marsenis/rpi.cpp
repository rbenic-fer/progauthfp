#include <cstdio>
#include <cmath>
#define MAX 105

using namespace std;

int main() {
	int t, n, k, l, i, j, sum, cnt, z, f, m;
	char w[MAX][MAX], tmp;
	double wp[MAX], owp[MAX], oowp[MAX];
	double wp2[MAX][MAX];
	double s;

	scanf("%d", &t);

	for (z=1; z<=t; z++) {
		scanf("%d\n", &n);
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++)
				scanf("%c", &w[i][j]);
			scanf("%c", &tmp);
		}
		for (i=1; i<=n; i++) {
			k = l =0;
			for (j=1; j<=n; j++)
				if ( w[i][j] != '.' ) {
					l++;
					if ( w[i][j] == '1' ) k++;
				}
			wp[i] = k / (double) l;
		}
	
		for (i=1; i<=n; i++) {
			s = 0;
			cnt = 0;
			for (j=1; j<=n; j++) {
				k = l =0;
				if ( w[i][j] != '.' ) {
					for (m=1; m<=n; m++)
						if ( m != i ) {
							if ( w[j][m] != '.') {
								l++;
								if ( w[j][m] == '1' ) k++;
							}
						}
					if (l) { s += k / (double) l; }
				}
				if (l) cnt++;
			}
			owp[i] = s / cnt;
		}
	
		for (i=1; i<=n; i++) {
			cnt =s=0 ;
			for (j=1; j<=n; j++)
				if ( w[i][j] != '.' ) { s += owp[j]; cnt++; }
			oowp[i] = s / cnt;
		}
	
		printf("Case #%d:\n", z);
		for (i=1; i<=n; i++)
			printf("%lf\n", 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);

	}
	return 0;
}
