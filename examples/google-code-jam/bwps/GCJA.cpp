#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, K;
string diam[200];

bool check_vert(int x, int y) {
	for (int d = 1; x - d >= 0 && x + d < 2*K-1; d++) {
		if (diam[x-d][y] == ' ' || diam[x+d][y] == ' ') continue;
		if (diam[x-d][y] != diam[x+d][y]) return false;
	}
	return true;
}

bool check_horz(int x, int y) {
	for (int d = 1; y - d >= 0 && y + d < 2*K-1; d++) {
		if (diam[x][y-d] == ' ' || diam[x][y+d] == ' ') continue;
		if (diam[x][y-d] != diam[x][y+d]) return false;
	}
	return true;
}

bool check(int x, int y) {
	FOR(i, 0, 2*K-1) {
		if (!check_vert(x, i)) return false;
		if (!check_horz(i, y)) return false;
	}
	return true;
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> K;
		getline(cin, diam[0]);
		FOR(i, 0, 2*K-1) {
			getline(cin, diam[i]);
			while (sz(diam[i]) < 2*K-1) diam[i] += ' ';
		}
		int res = oo;
		FOR(i, 0, 2*K-1) {
			FOR(j, 0, 2*K-1) {
				if (check(i, j)) {
					res = min(res, abs(K-1-i) + abs(K-1-j) + K);
				}
			}
		}
		cout << "Case #" << cs << ": " << res*res - K*K << endl;
	}
	return 0;
}
