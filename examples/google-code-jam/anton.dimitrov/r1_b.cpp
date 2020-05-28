#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

const int MAXN = 101;
const int MAXL = 101;
const int MAXM = 101;

int t;
int n, m;
char words[MAXN][MAXL];
char orders[MAXM][27];
int allowed[MAXN];
int allowed_let[27];

void filter_words_patt(const char* patt) {
	int len = strlen(patt);
	for (int i = 0; i < n; i++) {
		if (allowed[i]) {
			for (int j = 0; j < len; j++) {
				if (patt[j] != '_' && patt[j] != words[i][j]) {
					allowed[i] = 0;
					break;
				}
				if (allowed_let[words[i][j] - 'a'] && patt[j] == '_') {
					allowed[i] = 0;
					break;
				}
			}
		}
	}
}

void filter_words_let(char let) {
	for (int i = 0; i < n; i++) {
		if (allowed[i]) {
			int len = strlen(words[i]);
			for (int j = 0; j < len; j++) {
				if (words[i][j] == let) {
					allowed[i] = 0;
					break;
				}
			}
		}
	}
}

bool is_good(int let) {
	for (int i = 0; i < n; i++) {
		if (allowed[i]) {
			int len = strlen(words[i]);
			for (int j = 0; j < len; j++) {
				if (words[i][j] == let) {
					return true;
				}
			}
		}
	}

	return false;
}

int solve(int or_idx) {

	int best_score = -1;
	int res = -1;

	for (int i = 0; i < n; i++) {
		memset(allowed, 0, sizeof(allowed));
		memset(allowed_let, 0, sizeof(allowed_let));
		int curr_len = strlen(words[i]);
		for (int j = 0; j < n; j++) {
			if (strlen(words[j]) == curr_len) {
				allowed[j] = 1;
			}
		}

		char pattern[MAXL];
		for (int j = 0; j < curr_len; j++) {
			pattern[j] = '_';
		}
		pattern[curr_len] = 0;
		int score = 0;
		for (int j = 0; j < 26; j++) {
			if (is_good(orders[or_idx][j])) {
				bool found = false;
				for (int k = 0; k < curr_len; k++) {
					if (words[i][k] == orders[or_idx][j]) {
						found = true;
						pattern[k] = orders[or_idx][j];
					}
				}
				if (found) {
					allowed_let[orders[or_idx][j] - 'a'] = 1;
					filter_words_patt(pattern);
					bool is_over = true;
					for (int k = 0; k < curr_len; k++) {
						if (pattern[k] == '_') {
							is_over = false;
						}
					}
					if (is_over) {
						break;
					}
				}
				else {
					filter_words_let(orders[or_idx][j]);
					score++;
				}
			}
		}
		if (score > best_score) {
			best_score = score;
			res = i;
		}
	}

	return res;
}

int main() {

	freopen("B-small-attempt2.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d", &t);

	for (int gi = 1; gi <= t; gi++) {
		scanf("%d %d\n", &n, &m);
		printf("Case #%d:", gi);
		for (int i = 0; i < n; i++) {
			scanf(" %s ", words[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf(" %s ", orders[i]);
			int idx = solve(i);
			printf(" %s", words[idx]);
		}
		printf("\n");
	}

	return 0;
}
