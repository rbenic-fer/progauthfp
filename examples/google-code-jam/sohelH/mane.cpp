#include<bits/stdc++.h>

using namespace std;

bool ok(char c, char p) {
	if (p == ' ') return true;
	if (c == 'R') if (p == 'Y' || p == 'B' || p == 'G') return true;
	if (c == 'O') if (p == 'B' ) return true;
	if (c == 'Y') if (p == 'R' || p == 'B' || p == 'V') return true;
	if (c == 'G') if (p == 'R' ) return true;
	if (c == 'B') if (p == 'Y' || p == 'R' || p == 'O') return true;
	if (c == 'V') if (p == 'Y') return true;
	return false;
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int N;
		int R, O, Y, G, B, V;
		cin >> N;
		cin >> R >> O >> Y >> G >> B >> V;

		string res = "";
		for (int i = 0; i < N; i++) res += '.';
		bool yes = true;
		for (int i = 0; i < N; i++) {
			char c;
			char prev;
			if (i == 0) prev = ' ';
			else prev = res[i-1];
			int m = 0;
			if (R > m && ok('R', prev)) m = R, c = 'R';
			if (O > m && ok('O', prev)) m = O, c = 'O';
			if (Y > m && ok('Y', prev)) m = Y, c = 'Y';
			if (G > m && ok('G', prev)) m = G,  c = 'G';
			if (B > m && ok('B', prev)) m = B, c = 'B';
			if (V > m && ok('V', prev)) m = V, c = 'V';

			if (prev == 'R' && G > 0) c = 'G';
			if (prev == 'Y' && V > 0) c = 'V';
			if (prev == 'B' && O > 0) c = 'O';

			if (m == 0) { yes = false; break; }

			res[i] = c;
			if (c == 'R') R--;
			if (c == 'O') O--;
			if (c == 'Y') Y--;
			if (c == 'G') G--;
			if (c == 'B') B--;
			if (c == 'V') V--;
			//cout << c;
		}
		if (!ok(res[N-1], res[0])) {
			swap(res[N-1], res[N-2]);
		}
		if (!ok(res[N-1], res[0]) || !ok(res[N-2], res[N-3]) ) yes = false;

		if (!yes) res = "IMPOSSIBLE";
		cout << "Case #" << cases << ": " << res << endl;

	}
	return 0;
}
