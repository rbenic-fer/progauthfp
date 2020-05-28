#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
const int mn = 15;
int id[mn];
int s[mn], ref[mn];

int steps(int n, int *id) {
	int t[mn];
	bool found_top = 0;
	for (int i = 0; i < n; ++i) {
		ref[i] = s[id[i]];
		t[i] = s[i];
		if (found_top) {
			if (i > 0 && ref[i] > ref[i - 1])
				return 1 << 30;
		} else {
			if (i > 0 && ref[i] < ref[i - 1])
				found_top = 1;
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (t[i] != ref[i]) {
			for (int j = i + 1; j < n; ++j)
				if (ref[i] == t[j]) {
					res += j - i;
					for (int k = j; k > i; --k) {
						t[k] = t[k - 1];
					}
					break;
				}
		}
	}
	return res;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
//	freopen("sample.in", "r", stdin);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int n;

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &s[i]);
			id[i] = i;
		}

		int ans = -1;
		do {
			int res = steps(n, id);
			if (ans == -1 || res < ans)
				ans = res;
		} while (next_permutation(id, id + n));

		printf("Case #%d: %d\n", Tc, ans);
	}
	return 0;
}
