#include <algorithm>
#include <cstdio>
using namespace std;
double dist[101], time[101];
int T;
int N, Q;
int E[101], S[101];
int D[101][101];
int U, V;
int main (){
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("C-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &N, &Q);
		for (int j = 1; j <= N; j++)
			scanf("%d %d", &E[j], &S[j]);
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				scanf("%d", &D[j][k]);
		for (int j = 0; j < Q; j++){
			scanf("%d %d", &U, &V);
			if (U == 1 && V == N){
				dist[1] = 0;
				time[1] = 0;
				for (int k = 2; k <= N; k++){
					dist[k] = dist[k - 1] + D[k - 1][k];
					time[k] = -1;
				}
				for (int k = 1; k <= N; k++){
					for (int l = k + 1; l <= N; l++){
						if (dist[l] - dist[k] <= E[k]){
							if (time[l] == -1)
								time[l] = time[k] + (dist[l] - dist[k]) / (S[k] + .0);
							else 
								time[l] = min(time[l], time[k] + (dist[l] - dist[k]) / (S[k] + .0));
						}
					}
				}
			}
		}
		printf("Case #%d: %.9lf\n", i, time[N]);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
