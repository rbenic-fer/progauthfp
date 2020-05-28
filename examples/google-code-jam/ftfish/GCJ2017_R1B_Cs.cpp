#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <omp.h>
using namespace std;

const int mn = 105;

int main() {
	int Tn;
	scanf("%d", &Tn);

	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int n, q, e[mn], s[mn], g[mn][mn];

		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &e[i], &s[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		}

		double dis[mn][mn] = {};
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dis[i][j] = -1;
		for (int i = 0; i < n; ++i) {
			dis[i][i] = 0;
			for (int j = i+1; j < n; ++j) {
				dis[i][j] = dis[i][j-1] + g[j-1][j];
			}
		}

		// q = 1
		scanf("%*d%*d");

		double f[mn][mn] = {};
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				f[i][j] = -1;
		f[0][0] = 0;
		for (int i = 1; i < n; ++i) {
			double m = 1e30;
			for (int j = 0; j < i; ++j) {
				// use horse j (j < i) to city i
				if ((dis[j][i] <= e[j] && f[i-1][j] >= 0 && (f[i][j] < 0 || f[i][j] > f[i-1][j] + dis[i-1][i] / s[j]))) {
					f[i][j] = f[i-1][j] + dis[i-1][i] / s[j];
					if (f[i][j] < m) m = f[i][j];
				}
			}
			f[i][i] = m;
//			int j = i;
//			// use horse k ()
//			for (int k = 0; k <= i-1; ++k)
//				if (f[i][j] < 0 || (dis[k][i] <= e[k] && f[i-1][k] >= 0 && f[i][j] > f[i-1][k] + dis[i-1][i] / s[k])) {
//					f[i][j] = f[i-1][k] + dis[i-1][i] / s[k];
//				}

		}

//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j)
//				printf("%.3f ", f[i][j]);
//			puts("");
//		}

		printf("Case #%d: ", Tc);
		printf("%.10f\n", f[n-1][n-1]);
	}
	return 0;
}
