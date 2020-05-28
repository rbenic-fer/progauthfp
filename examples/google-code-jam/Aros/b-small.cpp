#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1000+5;
int T, N;
double V, X, R[MAXN], C[MAXN];
using namespace std;
int main() {
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d%lf%lf", &N, &V, &X);
		for (int i = 1; i <= N; i++) {
			scanf("%lf%lf", &R[i], &C[i]);
		}
		bool imp = false;
		double ans = 1e12;
		if (N == 1) {
			if (C[1] != X)
				imp = true;
			else {
				ans = V/R[1];
			}
		} else if (N == 2) {
			if ((C[1] > X && C[2] > X) || (C[1] < X && C[2] < X)) {
				imp = true;
			} else if (C[1] == X && C[2] == X) {
				ans = min(ans, V/(R[1]+R[2]));
			} else if (C[1] == X) {
				ans = min(ans, V/R[1]);
			} else if (C[2] == X) {
				ans = min(ans, V/R[2]);
			} else {
				double t1 = (V*(C[2]-X))/(R[1]*(C[2]-C[1]));
				double t2 = (V*(X-C[1]))/(R[2]*(C[2]-C[1]));
				ans = min(ans, max(t1, t2));
			}
		}
		printf("Case #%d: ", cas);
		if (imp)
			printf("IMPOSSIBLE\n");
		else
			printf("%.8lf\n", ans);
	}
	return 0;
}