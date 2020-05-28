#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		map<int, int> no2cnt;
		for (int p = 0; p < 2; ++p) {
			int ans;
			cin >> ans;
			for (int r = 1; r <= 4; ++r) {
				for (int c = 1; c <= 4; ++c) {
					int v;
					cin >> v;
					if (r == ans) {
						no2cnt[v] ++;
					}
				}
			}
		}
		set<int> possible;
		for (auto p : no2cnt) {
			if (p.second == 2) {
				possible.insert(p.first);
			}
		}
		cout << "Case #" << t << ": ";
		if (possible.size() == 1) cout << *possible.begin();
		else if (possible.empty()) cout << "Volunteer cheated!";
		else cout << "Bad magician!";
		cout << endl;
	}
	return 0;
}