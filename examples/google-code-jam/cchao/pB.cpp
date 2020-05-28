#include <bits/stdc++.h>
using namespace std;

int f(int cnt[], int mx) {
	while(mx&&!cnt[mx]) mx--;
	if(mx <= 3) return mx;
	int t = cnt[mx];
	int ret = mx;
	for(int i = 1; i <= mx/2; ++i) {
		cnt[i] += t;
		cnt[mx - i] += t;
		cnt[mx] = 0;
		ret = min(ret, f(cnt, mx) + t);
		cnt[i] -= t;
		cnt[mx - i] -= t;
		cnt[mx] = t;
	}
	return ret;
}

int n, a[100010];
int main() {
	int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks) {
		int ans = 0, mx = 0, cnt[1010] = {};
		scanf("%d", &n); for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			mx = max(a[i], mx);
			cnt[a[i]]++;
		}
		ans = mx;
		/*
		for(int i = 0; mx > 1;) {
			int t = cnt[mx];
			cnt[mx/2] += t;
			cnt[mx-mx/2] += t;
			i += t;
			cnt[mx] = 0;
			while(cnt[mx]==0) mx--;
			ans = min(ans, mx + i);
		}*/
		ans = f(cnt, mx);
		printf("Case #%d: %d\n", ks, ans);
	}
	return 0;
}
