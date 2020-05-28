#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		string S;
		int K;
		cin >> S >> K;
		int ret = 0;
		int i = 0;
		while(true) {
			while (i < S.length() && S[i] == '+') ++i;
			if (i + K > S.length()) break;
			for (int j = 0; j < K; ++j) {
				S[j+i] = S[j+i] == '-' ? '+' : '-';
			}
			++ret;
		}
		cout << "Case #" << q << ": ";
		if (i == S.length()) cout << ret;
		else cout << "IMPOSSIBLE";
		cout << endl;
	}
	return 0;
}