#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int gt;
int n;
vector<int> nasl[1024];
int paths[1024];
queue<int> q;

bool check(int node) {
	memset(paths, 0, sizeof(paths));
	while(!q.empty()) {
		q.pop();
	}

	q.push(node);
	paths[node] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < nasl[curr].size(); i++) {
			int cn = nasl[curr][i];
			paths[cn]++;
			if (paths[cn] == 1) {
				q.push(cn);
			}
			else {
				return true;
			}
		}
	}

	return false;
}

int main() {

	freopen("A-large.in", "r", stdin);
	freopen("p1output.txt", "w", stdout);

	scanf("%d", &gt);

	for (int gi=1; gi <= gt; gi++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			nasl[i].clear();
			for (int j = 0; j < a; j++) {
				int b;
				scanf("%d", &b);
				nasl[i].push_back(b);
			}
		}

		printf("Case #%d: ", gi);
		bool found = false;
		for (int i = 1; i <= n; i++) {
			if (check(i)) {
				printf("Yes\n");
				found = true;
				break;
			}
		}

		if (!found) {
			printf("No\n");
		}
	}

	return 0;
}
