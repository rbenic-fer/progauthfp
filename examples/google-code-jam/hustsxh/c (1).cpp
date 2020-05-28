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

typedef long long LL;

using namespace std;

LL getmin(int n, LL p) {
	if (p < (1LL<<(n - 1))) {
		return 0;
	}
	return (getmin(n - 1, p - (1LL<<(n - 1))) + 1) * 2;
}

LL getmax(int n, LL p) {
	if (p == (1LL<<n) - 1) {
		return (1LL << n) - 1;
	}
	if (p >= (1LL <<(n - 1))) {
		return (1LL << n) - 2;
	}
	return (getmax(n - 1, p)) * 2;
}

void solve() {
	int n;
	LL p;
	cin >> n >> p;
	cout << getmin(n, p - 1) << " " << getmax(n, p - 1) << endl;
}

int main() {
	int T;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
