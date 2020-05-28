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

int C, N, K, B, T, X[100], V[100];

int main() {
	cin >> C;
	FOR(cs, 1, C+1) {
		cin >> N >> K >> B >> T;
		FOR(i, 0, N) cin >> X[i];
		FOR(i, 0, N) cin >> V[i];
		bool can[N];
		FOR(i, 0, N) can[i] = (V[i]*T >= B-X[i]);
		int num = 0, p = N;
		while (num < K && p > 0) { 
			p--;
			if (can[p]) num++;
		}
		if (num < K) {
			cout << "Case #" << cs << ": IMPOSSIBLE" << endl;
		} else {
			int res = 0;
			num = 0;
			FOR(i, p, N) {
				if (can[i]) {
					num++;
				} else {
					res += num;
				}
			}
			cout << "Case #" << cs << ": " << res << endl;
		}
	}
	return 0;
}
