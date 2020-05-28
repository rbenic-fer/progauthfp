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

constexpr int N = 720, INF = 1234567890;

int must[2 * N], mem[N + 1][N + 1][2][2];

int f(int i, int j, int fst, int cur) {
	int & ans = mem[i][j][fst][cur];
	if (ans != -1) {
		return ans;
	}
	if (i == 0 && j == 0) {
		return ans = (fst == cur ? 0 : INF);
	}
	int t = i + j - 1;
	if (must[t] != -1 && cur != must[t]) {
		return ans = INF;
	}
	if ((cur == 0 && i == 0) || (cur == 1 && j == 0)) {
		return ans = INF;
	}
	if (cur == 0) {
		return ans = min(
			f(i - 1, j, fst, 0),
			f(i - 1, j, fst, 1) + 1
		);
	}
	else {
		return ans = min(
			f(i, j - 1, fst, 0) + 1,
			f(i, j - 1, fst, 1)
		);
	}
}

int work() {
	clr1(must), clr1(mem);

	int n, m;
	cin >> n >> m;
	rep (_, n) {
		int a, b;
		cin >> a >> b;
		range (t, a, b) {
			must[t] = 0;
		}
	}
	rep (_, m) {
		int a, b;
		cin >> a >> b;
		range (t, a, b) {
			must[t] = 1;
		}
	}

    return min(f(N, N, 0, 0), f(N, N, 1, 1));
}

int main() {
	int t;
	cin >> t;
	rep (i, t) {
		cout << "Case #" << i + 1 << ": " << work() << endl;
	}
	return 0;
}
