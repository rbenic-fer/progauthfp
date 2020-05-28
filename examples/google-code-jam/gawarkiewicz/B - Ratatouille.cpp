#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N, P;
		cin >> N >> P;
		vector<int> R(N);
		for (auto& r : R) cin >> r;
		vector<vector<int>> Q(N, vector<int>(P));
		for (auto& q : Q) for (auto& qq : q) cin >> qq;
		for (auto& q : Q) sort(q.begin(), q.end());
		int ret = 0;
		for (int i = 1; ; i = max(i, Q[0][0] / R[0] * 9 / 10)) {
			bool removed = false;
			bool end = false;
			for (int j=0; j<N; ++j) {
				auto& q = Q[j];
				auto& r = R[j];
				while (!q.empty() && q[0] * 10 / 9 < r * i) {
					q.erase(q.begin()); removed = true;
				}
				if (q.empty()) {
					end = true; break;
				}
			}
			if (end) break;
			bool ok = true;
			for (int j = 0; j < N; ++j) {
				auto& q = Q[j];
				auto& r = R[j];
				if (r * i * 11 / 10 < q[0]) ok = false;
			}
			if (!removed) {
				if (!ok) i = max(i + 1, Q[0][0] / R[0] * 9 / 10);
				else {
					for (int j = 0; j < N; ++j) {
						auto& q = Q[j];
						auto& r = R[j];
						q.erase(q.begin());
						if (q.empty()) {
							end = true; break;
						}
					}
					++ret;
					if (end) break;
				}
			}
		}
		cout << "Case #" << q << ": " << ret << endl;
	}
	return 0;
}