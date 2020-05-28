#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main() {
	int t, z, n, i, p, a, b, k, time, f;
	char r;
	queue<int> qa, qb;
	queue< pair<char, int> > q;
	pair<char, int> tmp;

	scanf("%d", &t);
	
	for (z=1; z<=t; z++) {
		while (!q.empty()) q.pop();
		while (!qa.empty()) qa.pop();
		while (!qb.empty()) qb.pop();

		scanf("%d ", &n);
		for (i=1; i<=n; i++) {
			scanf("%c %d ", &r, &p);
			q.push( make_pair(r, p) );
			if (r == 'O') qa.push(p);
			else qb.push(p);
		}

		a = b = 1;
		k = 0;
		while (!q.empty()) {
			tmp = q.front(); q.pop();

			if (tmp.first == 'O') {
				time = abs(a - tmp.second) + 1;
				a = tmp.second;
				k += time ;
				if (!qb.empty()) {
					f = qb.front();
					if (f > b) { b += time; if (b > f) b = f; }
					if (f < b) { b -= time; if (b < f) b = f; }
				}
				qa.pop();
			}
			if (tmp.first == 'B') {
				time = abs(b - tmp.second) + 1;
				b = tmp.second;
				k += time ;
				if (!qa.empty()) {
					f = qa.front();
					if (f > a) { a += time; if (a > f) a = f; }
					if (f < a) { a -= time; if (a < f) a = f; }
				}
				qb.pop();
			}
		}
		printf("Case #%d: %d\n", z, k);
	}
	return 0;
}

