#include <cstdio>
#include <iostream>

using namespace std;

int a[100][100];

bool check(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool col = false, row = false;
			for (int k = 0; k < n; ++k) {
				if (a[k][j] > a[i][j]) {
					col = true;
				}
			}
			for (int k = 0; k < m; ++k) {
				if (a[i][k] > a[i][j]) {
					row = true;
				}
			}
			if (col && row) {
				return false;
			}
		}
	}
	return true;
}
int solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	if(check(n, m)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

int main() {
	int T;
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
