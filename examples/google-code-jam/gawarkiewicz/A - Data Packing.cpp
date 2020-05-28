#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		multiset<int> m;
		int N, X;
		cin >> N >> X;
		for (int i = 0, t; i < N; ++i) {
			cin >> t;
			m.insert(t);
		}
		int ret = 0;
		while (!m.empty()) {
			++ret;
			auto bit = m.end();
			--bit;
			int rem = X - *bit;
			m.erase(bit);
			auto it = m.lower_bound(rem);
			while (1) {
				if (*it <= rem) {
					m.erase(it);
					break;
				}
				if (it == m.begin()) break;
				--it;
			}
		}
		cout << "Case #" << q << ": " << ret << endl;
	}
	return 0;
}