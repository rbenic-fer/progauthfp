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

double dp[(1<<20)+10];

double solve(string o) {
	int N = o.size();
	for (int i = 0; i < (1<<N); i++)
		dp[i] = 0.0;
	for (int i = 1; i < (1<<N); i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i&(1<<((j+k)%N))) {
					int m = i&~(1<<((j+k)%N));
					dp[i] += (dp[m] + (double)(N-k)) / N;
					break;
				}
			}
		}
		//printf("dp[%d]=%.12f\n", i, dp[i]);
	}
	int x = 0;
	for (int i = 0; i < N; i++) {
		if (o[i] == '.') {
			x |= (1<<i);
		}
	}
	return dp[x];
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string o;
		cin >> o;
		double e = solve(o);
		printf("Case #%d: %.12f\n", i+1, e);
	}
}
