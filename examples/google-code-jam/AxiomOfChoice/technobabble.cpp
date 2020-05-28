#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
#define fst first
#define snd second
#define tup make_tuple

#define N 2006
#define INF 2006


struct Edge {
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[N];
int n;

void add_edge(int i, int j, int c = 1) {
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

bool seen[N];

int dfs(int s, int t, int mf) {
	if(s == t) return mf;
	if(seen[s]) return 0;
	seen[s] = true;
	for(auto e : g[s]) if(e->c > e->f) {
		int mf2 = min(mf, e->c - e->f);
		mf2 = min(mf2, dfs(e->j, t, mf2));
		if(mf2) {
			e->f += mf2, e->r->f -= mf2;
			return mf2;
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	for(clr0(seen); dfs(s, t, INF); clr0(seen));
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

int get_id(string & s, map<string, int> & id_map) {
	if(!id_map.count(s)) {
		id_map[s] = id_map.size() - 1;
	}
	return id_map[s];
}

int work() {
	map<string, int> ls, rs;
	vector<pii> es;
	int m;
	cin >> m;
	rep(i, m) {
		string l, r;
		cin >> l >> r;
		es.emplace_back(get_id(l, ls), get_id(r, rs));
	}

	n = ls.size() + rs.size();
	rep(i, N) g[i].clear();

	int k = ls.size();
	rep(i, k) {
		add_edge(n, i);
	}
	range(i, k, n) {
		add_edge(i, n + 1);
	}
	for(auto & e : es) {
		add_edge(e.fst, e.snd + k);
	}
	
	n += 2;

	int max_match = max_flow(n - 2, n - 1);
	int min_edge_cover = n - max_match - 2;
	int ans = m - min_edge_cover;
	return ans;
}

int main() {
	int sz;
	cin >> sz;
	rep(i, sz) {
		cout << "Case #" << (i + 1) << ": " << work() << endl;
	}
	return 0;
}
