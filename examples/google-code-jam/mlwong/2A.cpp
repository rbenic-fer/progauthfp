#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double n;

struct wway {
	int l, s;
	bool operator < (const wway w2) const {
		return s < w2.s;	
	}
} w[1002];

int main() {
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		int X, S, R, t, N;
		scanf("%d %d %d %d %d", &X, &S, &R, &t, &N);
		R -= S;
		for (int j=0; j<N; j++) {
			int Bi, Ei, wi;
			scanf("%d %d %d", &Bi, &Ei, &wi);
			X -= (Ei-Bi);
			w[j].l = Ei-Bi;
			w[j].s = wi+S;
		}
		w[N].l = X;
		w[N].s = S;
		sort(w, w+N+1);
		double cur = t, total = 0.0;
		for (int j=0; j<=N; j++) {
			// run at j;
			if ((double)(w[j].l)/((double)w[j].s+R) <= cur) {
				cur -= (double)(w[j].l)/((double)w[j].s+R);
				total += (double)(w[j].l)/((double)w[j].s+R);
			} else if (cur > 0) {
				total += ((double)w[j].l-(double)(w[j].s+R)*cur)/((double)w[j].s) + cur;
				cur = 0;
			} else {
				total += (double)(w[j].l)/(double)(w[j].s);
			}
		}
		printf("Case #%d: %lf\n", i, total);		
	}
	return 0;	
}
