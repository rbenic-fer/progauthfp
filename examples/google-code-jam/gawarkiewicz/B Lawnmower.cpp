#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q=1; q<=T; ++q) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> we(N);
		for (int i=0; i<N; ++i) {
			we[i].resize(M);
			for (int j=0; j<M; ++j) {
				cin >> we[i][j];
			}
		}
		vector<int> maxRow(N, 0), maxCol(M, 0);
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				maxRow[i] = max(maxRow[i], we[i][j]);
				maxCol[j] = max(maxCol[j], we[i][j]);
			}
		}
		bool ans = true;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				if (we[i][j] < maxRow[i] && we[i][j] < maxCol[j]) {
					ans = false;
				}
			}
		}
		cout << "Case #" << q << ": " << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}