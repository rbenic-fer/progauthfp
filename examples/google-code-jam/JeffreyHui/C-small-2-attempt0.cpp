#include <cstdio>
int cnt[1000001];
int T, N, K;
int main (){
	freopen ("C-small-2-attempt0.in", "r", stdin);
	freopen ("C-small-2-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &N, &K);
		for (int j = 0; j <= N; j++)
			cnt[j] = 0;
		cnt[N] = 1;
		while (cnt[N] == 0 || (N > 0 && K > 1)){
			if (cnt[N] == 0)
				N--;
			else {
				K--;
				cnt[N]--;
				cnt[N - 1 - (N - 1) / 2]++;
				cnt[(N - 1) / 2]++;
			}
		}
		printf("Case #%d: %d %d\n", i, N - 1 - (N - 1) / 2, (N - 1) / 2);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
