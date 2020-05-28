#include <algorithm>
#include <cstdio>
using namespace std;
struct horse{
	int K;
	int S;
};
double time;
int T, D, N;
horse H[1000];
bool compare(horse h1, horse h2){
	return h1.K < h2.K;
}
int main (){
	freopen ("A-large.in", "r", stdin);
	freopen ("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &D, &N);
		for (int j = 0; j < N; j++)
			scanf("%d %d", &H[j].K, &H[j].S);
		sort(H, H + N, compare);
		time = (D - H[N - 1].K) / (H[N - 1].S + .0);
		for (int j = N - 2; j >= 0; j--)
			time = max(((D - H[j].K) / (H[j].S + .0)), time);
		printf("Case #%d: %.6lf\n", i, D / time);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
