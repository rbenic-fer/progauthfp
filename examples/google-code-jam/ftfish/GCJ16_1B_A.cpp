#include <bits/stdc++.h>
using namespace std;

const int ml = 2016;

const string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[ml];

int solved, ans[10];

bool possible(const string &d, int *cnt) {
	for (unsigned i = 0; i < d.size(); ++i) {
		if (cnt[d[i] - 'A'] == 0){
			for (unsigned j = 0; j < i; ++j)
				cnt[d[j] - 'A'] ++;
			return 0;
		}
		cnt[d[i] - 'A'] --;
	}
	for (unsigned j = 0; j < d.size(); ++j)
		cnt[d[j] - 'A'] ++;
	return 1;
}

void modify (const string &d, int *cnt, int delta){
	for (unsigned i = 0; i < d.size(); ++i)
		cnt[d[i] - 'A'] += delta;

}
void dfs(int d, int *cnt) {
	if (d > 9) {
		bool found = true;
		for (int i = 0; i < 26; ++i)
			if (cnt[i]) {
				found = false;
			}
		if (found) {
			solved = true;
		}
		return;
	}

	dfs(d + 1, cnt);
	for (int i = 0; !solved ;++i) {
		if (possible(digits[d], cnt)) {
			modify(digits[d], cnt, -1);
			ans[d] ++;
			dfs(d + 1, cnt);
		} else {
			modify(digits[d], cnt, i);
			ans[d] = 0;
			break;
		}
	}


}

int main() {
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("A-small-attempt0.out", "w", stdout);
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		scanf("%s", s);

		int cnt[26] = {};
		int N = strlen(s);
		for (int i = 0; i < N; ++i){
			cnt[s[i] - 'A']++;
		}

		memset(ans, 0, sizeof(ans));
		solved = 0;
		dfs(0, cnt);

		printf("Case #%d: ", Tn);
		for (int i = 0; i < 10; ++i) {
			if (ans[i] > 0) {
				for (int j = 0; j < ans[i]; ++j)
					putchar(i + '0');
			}
		}
		putchar('\n');
	}
	return 0;
}
