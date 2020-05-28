#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<string> rev(vector <string> & v) {
	vector<string> ret(v);
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			ret[i][j] = v[j][i];
		}
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<string> P(N);
		for (auto& p : P) cin >> p;

		int ret = 0;

		for (int r = 0; r < P.size(); ++r) {
			for (int c = 0; c < P.size(); ++c) {
				int cnt = 0;
				for (int i = 0; i < P.size(); ++i) if (P[r][i] == '1') ++cnt;
				for (int i = 0; i < P.size(); ++i) if (P[i][c] == '1') ++cnt;
				if (P[r][c] == '1') --cnt;
				if (cnt <= 1) {
					if (cnt == 1 && P[r][c] != '1') continue;
					if (cnt == 0) ret++;
					P.erase(P.begin() + r);
					for (auto& row : P) row.erase(row.begin() + c);
					--r;
					--c;
					break;
				}
			}
		}

		int t1 = 0;
		for (auto& p : P) for (auto& c : p) if (c == '1') ++t1;

		sort(P.rbegin(), P.rend());
		P = rev(P);
		sort(P.rbegin(), P.rend());
		for (int t = 0; t < P.size(); ++t) P[t][t] = '1';
		for (int t = 0, beg = 0; t < P.size(); ++t) {
			bool empty = true;
			for (int i = beg; empty && i < t; ++i) if (P[i][t] == '1' || P[t][i] == '1') empty = false;
			if (!empty) {
				for (int i = beg; i <= t; ++i) P[i][t] = P[t][i] = '1';
			}
			else {
				beg = t;
			}
		}

		for (auto& p : P) for (auto& c : p) if (c == '1') ++ret;
		ret -= t1;
		cout << "Case #" << t << ": " << ret << endl;
	}
	return 0;
}