#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int t;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &t);

	for (int gi = 0; gi < t; gi++) {
		int n;
		scanf("%d", &n);
		int bt = 0;
		int ot = 0;
		int bp = 1;
		int op = 1;
		int currt = 0;
		for (int i = 0; i < n; i++) {
			char rob;
			int but;
			scanf(" %c %d", &rob, &but);
			if (rob == 'O') {
				int dist = abs(but - op);
				op = but;
				currt = max(currt + 1, ot + dist + 1);
				ot = currt;
			}
			else {
				int dist = abs(but - bp);
				bp = but;
				currt = max(currt + 1, bt + dist + 1);
				bt = currt;
			}
		}
		printf("Case #%d: %d\n", gi+1, currt);
	}
}
