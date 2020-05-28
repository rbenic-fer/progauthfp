#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <omp.h>
using namespace std;

const int mn = 105, mq = 105;

double f[mn][mn][mn];

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
			for (int j = 0; j < n; ++j) {
				dis[i][j] = g[i][j];
				dis[i][i] = 0;
			}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (dis[i][k] >= 0 && dis[k][j] >= 0 && (dis[i][j] < 0 || dis[i][j] > dis[i][k] + dis[k][j]))
						dis[i][j] = dis[i][k] + dis[k][j];
				}
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				printf("%.3f ", dis[i][j]);
//			}
//			puts("");
//		}

		double ans[mq];
		for (int qn = 0; qn < q; ++qn) {
			int start, end;
			scanf("%d%d", &start, &end);
			--start, --end;
			for (int st = 0; st < n; ++st)
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						f[st][i][j] = -1;
			f[0][start][start] = 0;

			double curans = -1;
			for (int st = 1; st < n; ++st) {
				for (int i = 0; i < n; ++i) {
					double m = 1e30;
					for (int j = 0; j < n; ++j) {
						// use horse j (j < i) to city i in step st, via city k
						for (int k = 0; k < n; ++k) {
							if (dis[j][k] >= 0 && dis[k][i] >= 0 && (dis[j][i] <= e[j] && f[st-1][k][j] >= 0 && (f[st][i][j] < 0 || f[st][i][j] > f[st-1][k][j] + dis[k][i] / s[j]))) {
								f[st][i][j] = f[st-1][k][j] + dis[k][i] / s[j];
								if (f[st][i][j] < m) m = f[st][i][j];
							}
						}
					}
					f[st][i][i] = m;
				}
				if (f[st][end][end] >= 0 && (curans < 0 || curans > f[st][end][end]))
					curans = f[st][end][end];
			}
			ans[qn] = curans;
		}

		printf("Case #%d:", Tc);
		for (int qn = 0; qn < q; ++qn)
			printf(" %.10f", ans[qn]);
		puts("");
		fflush(stdout);
	}
	return 0;
}
