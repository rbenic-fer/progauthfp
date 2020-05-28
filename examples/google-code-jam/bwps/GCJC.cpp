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

int C, R;
int old[200][200], nu[200][200];

int main() {
	cin >> C;
	FOR(cs, 1, C+1) {
		cin >> R;
		memset(old, 0, sizeof(old));
		FOR(i, 0, R) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			FOR(x, x1, x2+1) FOR(y, y1, y2+1) old[x][y] = 1;
		}
		int res = 0;
		while (1) {
			res++;
			FOR(x, 1, 101) FOR(y, 1, 101) {
				if (old[x-1][y] && old[x][y-1]) {
					nu[x][y] = 1;
				} else if (!old[x-1][y] && !old[x][y-1]) {
					nu[x][y] = 0;
				} else {
					nu[x][y] = old[x][y];
				}
			}
			bool live = false;
			FOR(x, 1, 101) FOR(y, 1, 101) {
				if (nu[x][y]) live = true;
				old[x][y] = nu[x][y];
			}
			if (!live) break; 
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
