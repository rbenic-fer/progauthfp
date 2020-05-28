#include <algorithm>
#include <cstdio>
using namespace std;
int T;
int N, K;
double U, P[50], Q[50], total, ans;
bool compare(double x, double y){
	return x > y;
}
int main (){
	freopen ("C-small-1-attempt1.in", "r", stdin);
	freopen ("C-small-1-attempt1.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &N, &K);
		scanf("%lf", &U);
		total = 0;
		for (int j = 0; j < N; j++){
			scanf("%lf", &P[j]);
			total += P[j];
		}
		sort(P, P + N, compare);
		if (total + U >= N){
			printf("Case #%d: %.6lf\n", i, 1.0);
		} else {
			total += U;
			for (int j = 0; j < N; j++){
				if (total / (N - j) < P[j]){
					Q[j] = P[j];
					total -= P[j];
				} else {
					for (int k = j; k < N; k++){
						Q[k] = total / (N - j);
					}
					j = N;
				}
			}
			ans = 1;
			for (int j = 0; j < N; j++)
				ans *= Q[j];
			printf("Case #%d: %.6lf\n", i, ans);
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
