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

int f1(int N, ll P) {
	int m = -1;
	for (int i = 0; i < N; i++) {
		if ((P-1)&(1LL<<i)) {
			m = i;
		}
	}
	//printf("m=%d\n", m);
	int x;
	if (P-1 == (1LL<<(m+1))-1) {
		x = m+1;
	} else {
		x = m;
	}
	//printf("x=%d\n", x);
	return N-x;
}

ll f2(int N, ll P) {
	int j = N;
	for (int i = 0; i < N; i++) {
		if (P&(1LL<<(N-1-i))) {
			j = N-1-i;
		} else {
			break;
		}
	}
	//printf("j=%d\n", j);
	int x;
	if (P + (1LL<<j) == (1LL<<N)) {
		x = N-j;
	} else {
		x = N-j+1;
	}
	//printf("x=%d\n", x);
	return x-1;
}

pair<ll, ll> solve(int N, ll P) {
	ll a = f1(N, P);
	ll b = f2(N, P);
	return make_pair((1LL<<N)==P ? (1LL<<N)-1 : (1LL<<(b+1))-2,
					 (1LL<<N)-(1LL<<a));
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		ll P;
		cin >> N >> P;
		pair<ll, ll> ans = solve(N, P);
		cout << "Case #" << i+1 << ": " << ans.first << " " << ans.second << endl;
	}
}
