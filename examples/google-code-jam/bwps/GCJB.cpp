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

int T, P, M[1 << 11];
int cost[1 << 12], tab[1 << 12][20];

int rek(int p, int c) {
	if (p >= (1 << P) - 1) {
		int ind = p - (1 << P) + 1;
		if (c < P - M[ind]) return oo;
		return 0;
	}
	int &res = tab[p][c];
	if (res != -1) return res;
	res = min(rek(2*p+1, c) + rek(2*p+2, c), cost[p] + min(oo, rek(2*p+1, c+1) + rek(2*p+2, c+1)));
	if (res > oo) res = oo;
	return res;
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> P;
		FOR(i, 0, 1 << P) cin >> M[i];
		FOR(i, 0, P) {
			FOR(j, 0, 1 << (P-i-1)) {
				cin >> cost[(1 << (P-i-1)) - 1 + j];
			}
		}
		memset(tab, -1, sizeof(tab));
		cout << "Case #" << cs << ": " << rek(0, 0) << endl;
	}
	return 0;
}
