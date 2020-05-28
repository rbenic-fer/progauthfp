#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, C;
int num[10000000];
set<int> pos;

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		memset(num, 0, sizeof(num));
		pos.clear();
		cin >> C;
		FOR(i, 0, C) {
			int p, v;
			cin >> p >> v;
			num[p+5000000] = v;
			if (v > 1) pos.insert(p+5000000);
		}
		int res = 0;
		while (!pos.empty()) {
			res++;
			int p = *(pos.begin());
			num[p] -= 2;
			if (num[p] < 2) pos.erase(pos.find(p));
			num[p-1]++;
			if (num[p-1] >= 2) pos.insert(p-1);
			num[p+1]++;
			if (num[p+1] >= 2) pos.insert(p+1);
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}

