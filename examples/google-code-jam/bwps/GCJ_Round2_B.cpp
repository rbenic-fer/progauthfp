#include <iostream>
using namespace std;

int C, N, M, A;

int main() {
	cin >> C;
	for (int tcs = 1; tcs <= C; tcs++) {
		cin >> N >> M >> A;
		int x1, x2, x3, y1, y2, y3;
		bool found = false;
		for (int n = 0; n <= N; n++) {
			for (int m = 0; m <= M; m++) {
				for (int x = 0; x <= N; x++) {
					for (int y = 0; y <= M; y++) {
						int a = m*n - n*y - m*x;
						if (a < 0) a = -a;
						if (a == A) {
							found = true;
							x1 = n; x2 = 0; x3 = x; y1 = 0; y2 = m; y3 = y;
							goto end;
						}
					}
				}
			}
		}
end:
		if (found) {
			cout << "Case #" << tcs << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
		} else {
			cout << "Case #" << tcs << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
