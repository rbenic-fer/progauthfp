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

int T, N, M, C;
vector<pair<string, int> > adj[1000000];

int add(string _path) {
	FOR(i, 0, sz(_path)) if (_path[i] == '/') _path[i] = ' ';
	istringstream is(_path);
	vs path;
	string s;
	while (is >> s) path.push_back(s);
	int cur = 0, pos = 0, res = 0;
	while (pos < sz(path)) {
		int found = -1;
		FOR(i, 0, sz(adj[cur])) {
			if (adj[cur][i].first == path[pos]) {
				found = i;
				break;
			}
		}
		if (found == -1) {
			adj[cur].push_back(make_pair(path[pos], C));
			C++; res++;
			found = sz(adj[cur])-1;
		}
		cur = adj[cur][found].second;
		pos++;
	}
	return res;
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		FOR(i, 0, C) adj[i].clear();
		C = 1;
		cin >> N >> M;
		FOR(i, 0, N) {
			string path;
			cin >> path;
			add(path);
		}
		int res = 0;
		FOR(i, 0, M) {
			string path;
			cin >> path;
			res += add(path);
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
