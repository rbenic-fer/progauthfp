#include <cstdio>
#include <vector>

using namespace std;

int tt;
vector<int> vals;
int nums[10][3];
int ans;
int n, s, p;

void check(int levs) {
	int numhigh = 0;
	int numsurp = 0;
	for (int i = 0; i < levs; i++) {
		if (nums[i][0] - nums[i][2] == 2) numsurp++;
		if (nums[i][0] >= p) numhigh++;
	}

	if (numsurp == s && ans < numhigh) {
		ans = numhigh;
	}
}

bool rec(int n, int lev) {
	if (lev == n) {
		check(n);
		return (ans == n);
	}

	for (int i = 10; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int k = vals[lev] - i - j;
			if (k >= 0 && k <= j && i - k <= 2) {
				nums[lev][0] = i;
				nums[lev][1] = j;
				nums[lev][2] = k;
				if (rec(n, lev+1)) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &tt);
	for (int i = 1; i <= tt; i++) {
		vals.clear();
		ans = 0;
		scanf("%d %d %d", &n, &s, &p);
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			vals.push_back(tmp);
		}
		rec(n, 0);
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}