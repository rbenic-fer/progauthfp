#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1000000;

int N, S, Q;

map<string, int> M;
int queries[1000];
int tab[1001][100];

void input() {
	M.clear();
	cin >> S;
	string tmp;
	getline(cin, tmp);
	for (int i = 0; i < S; i++) {
		getline(cin, tmp);
		M[tmp] = i;
	}
	cin >> Q;
	getline(cin, tmp);
	for (int i = 0; i < Q; i++) {
		getline(cin, tmp);
		queries[i] = M[tmp];
	}
}

int solve() {
	for (int i = 0; i < S; i++) tab[Q][i] = 0;
	for (int i = Q-1; i >= 0; i--) {
		for (int j = 0; j < S; j++) {
			tab[i][j] = INF;
			if (queries[i] == j) continue;
			for (int k = 0; k < S; k++) {
				int add = (k == j) ? 0 : 1;
				tab[i][j] = min(tab[i][j], tab[i+1][k] + add);
			}
		}
	}
	int res = INF;
	for (int i = 0; i < S; i++) res = min(res, tab[0][i]);
	return res;
}

int main() {
	cin >> N;
	for (int tcs = 1; tcs <= N; tcs++) {
		input();
		cout << "Case #" << tcs << ": " << solve() << endl;
	}
	return 0;
}
