#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#define maxn 1000
#define MOD 1000002013
typedef long long LL;

using namespace std;

struct Card {
	int begin, end, cnt;
	bool operator < (const Card &a) const {
		return begin < a.begin;
	}
}c[maxn];

int n, m, x[maxn * 2], cnt[maxn * 2];

int calc(int begin, int end, int cnt) {
	LL k = end - begin;
	return (2 * n - k + 1) * k / 2 % MOD * cnt % MOD;
}

void solve() {
	int osum = 0, sum = 0, xn = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> c[i].begin >> c[i].end >> c[i].cnt;
		osum = (osum + calc(c[i].begin, c[i].end, c[i].cnt)) % MOD;
		x[i * 2] = c[i].begin;
		x[i * 2 + 1] = c[i].end;
	}
	//cout << osum << endl;
	sort(x, x + m * 2);
	xn = unique(x, x + m * 2) - x;
	//cout << xn << endl;
	//for (int i = 0; i < n; ++i) cout << x[i] << endl;

	for (int i = 0; i < m; ++i) {
		int begin = 0;
		while(x[begin] < c[i].begin) {
			++ begin;
		}
		while(x[begin] < c[i].end) {
			cnt[begin] += c[i].cnt;
			++ begin;
		}
	}
	int maxx = 0, begin, end, v = false, dat;
	while(true) {
		dat = maxx = 0;
		for (int i = 0; i < xn; ++i) {
			if (cnt[i] > maxx) {
				maxx = cnt[i], begin = i, v = true;
				if (i) {
					dat = cnt[i - 1];
				}
			}
			if (cnt[i] < maxx && v) {
				v = false;
				end = i;
				dat = max(dat, cnt[i]);
			}
		}
		if (maxx == 0) {
			break;
		}
		//cout << begin << end << maxx << dat << endl;
		for (int i = begin; i < end; ++i) {
			cnt[i] = dat;
		}
		sum = (sum + calc(x[begin], x[end], maxx - dat)) % MOD;
	}
	//cout << sum << endl;
	cout << (osum - sum + MOD) % MOD << endl;
}
int main() {
	int T;
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
