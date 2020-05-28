#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1){
		string state;
		cin >> state;
		int k;
		cin >> k;
		int flips = 0;
		for (unsigned int i = 0; i < state.size(); i += 1) {
			if (state[i] == '-') {
				flips += 1;
				if (i + k > state.size()) {
					flips = -1;
					break;
				}
				for (unsigned int j = i; j < i + k; j += 1){
					state[j] = state[j] == '-'
						? '+'
						: '-';
				}
			}
		}
		if (flips == -1) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		}
		else {
			cout << "Case #" << t << ": " << flips << endl;
		}
	}
	return 0;
}