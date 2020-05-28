#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;
const int MOD = 1000002013;

int o[1010], e[1010], p[1010];
pair<int, int> op[1010];
pair<int, int> ep[1010];

ll cost(int N, int t) {
	return (((ll)t*N)%MOD - ((ll)t*(t-1)/2)%MOD + MOD)%MOD;
}

ll ncost(int N, int M) {
	ll r = 0;
	for (int i = 0; i < M; i++) {
		r = (r + (ll)p[i]*cost(N, e[i]-o[i]))%MOD;
	}
	return r;
}

int solve(int N, int M) {
	typedef map<int, ll> map_t;
	map_t m;
	for (int i = 0; i < M; i++) {
		op[i] = make_pair(o[i], p[i]);
		ep[i] = make_pair(e[i], p[i]);
	}
	sort(op, op+M);
	sort(ep, ep+M);
	int j = 0;
	ll r = 0;
	for (int i = 0; i < M; i++) {
		for (; op[j].first <= ep[i].first && j < M; j++) {
			m[op[j].first] += op[j].second;
		}
		int x = ep[i].second;
		for (map_t::reverse_iterator it = m.rbegin(); it != m.rend(); ++it) {
			int y = min(it->second, (ll)x);
			it->second -= y;
			r = (r + (ll)y*cost(N, ep[i].first-it->first))%MOD;
			x -= y;
			if (x == 0)
				break;
		}
		for (map_t::iterator it = m.begin(); it != m.end(); ++it) {
			if (it->second == 0) {
				m.erase(it, m.end());
				break;
			}
		}
	}
	return (ncost(N, M) - r + MOD) % MOD;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		for (int j = 0; j < M; j++) {
			cin >> o[j] >> e[j] >> p[j];
		}
		int ans = solve(N, M);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
