#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000+5;
int T, N, b[MAXN], r[MAXN];
double a[MAXN];
bool cmp(const int &x, const int &y) {
	return a[x] < a[y];
}
int main() {
	// freopen("put.in", "r", stdin);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &N);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < N; i++) {
				scanf("%lf", &a[N*j+i]);
				b[N*j+i] = j;
				r[N*j+i] = N*j+i;
			}
		sort(r, r+N*2, cmp);
		// for (int i = 0; i < N*2; i++)
		// 	printf("%d ", !(r[i] < N));
		// printf("\n");
		int cnt[2], ans[2] = {};
		for (int l = 0; l < 2; l++) {
			memset(cnt, 0, sizeof(cnt));
			for (int k = 0; k < N*2; k++) {
				int i = r[k], j = r[k+1];
				cnt[!(i < N)]++;
				if (!(i < N) == l && (k+1 == N*2 || i != j)) {
					int mini = min(cnt[0], cnt[1]);
					ans[l] += mini;
					cnt[1-l] -= mini;
					cnt[l] = 0;
				}
			}
		}
		printf("Case #%d: %d %d\n", cas, ans[0], N-ans[1]);
	}
	return 0;
}