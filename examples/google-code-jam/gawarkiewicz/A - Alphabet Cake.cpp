#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int R, C;
		cin >> R >> C;
		vector<string> v(R);
		for (auto& row : v) cin >> row;
		for (int i = 0; i < R; ++i) {
			string& row = v[i];
			if (row == string(C, '?')) {
				continue;
			}
			int pos = -1;
			for (int j = 0; ; ++j) if (row[j] != '?') { pos = j; break; }
			for (int j = 0; j < C; ++j) {
				if (row[j] == '?') row[j] = row[pos];
				else pos = j;
			}
		}
		int pos = 0;
		for (int i = 0; i < R; ++i) {
			string& row = v[i];
			if (row == string(C, '?')) {
				continue;
			}
			pos = i;
			break;
		}
		for (int i = 0; i < R; ++i) {
			string& row = v[i];
			if (row == string(C, '?')) {
				row = v[pos];
			}
			else pos = i;
		}
		cout << "Case #" << q << ":" << endl;
		for (auto& r : v) cout << r << endl;
	}
	return 0;
}