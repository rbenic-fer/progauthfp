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

const ll MOD = 100003;
int T, N;
ll binom[600][600];
ll tab[600][600];

ll rek(int n, int k) {
	if (k == 1) return 1;
	if (n <= k) return 0;
	ll &res = tab[n][k];
	if (res != -1) return res;
	res = 0;
	FOR(i, 0, n-k) {
		if (k-i-1 <= 0) continue;
		res = (res + binom[n-k-1][i] * rek(k, k-i-1)) % MOD;
	}
	return res;
}

int main() {
	binom[0][0] = 1;
	FOR(n, 1, 600) {
		binom[n][0] = binom[n][n] = 1;
		FOR(k, 1, n) binom[n][k] = (binom[n-1][k] + binom[n-1][k-1]) % MOD;
	}
	memset(tab, -1, sizeof(tab));
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N;
		ll res = 0;
		FOR(k, 1, N+1) res = (res + rek(N, k)) % MOD;
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
