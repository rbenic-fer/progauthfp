#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

pair<char, int> seq[110];

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		char rs[10];
		for (int j = 0; j < N; j++) {
			scanf("%s %d", rs, &seq[j].second);
			seq[j].first = rs[0];
		}
		int pos = 0;
		int op = 1;
		int bp = 1;
		for (int ans = 0;; ans++) {
			int oj = N;
			for (int j = pos; j < N; j++) {
				if (seq[j].first == 'O') {
					oj = j;
					break;
				}
			}
			int bj = N;
			for (int j = pos; j < N; j++) {
				if (seq[j].first == 'B') {
					bj = j;
					break;
				}
			}
			if (oj == N && bj == N) {
				printf("Case #%d: %d\n", i+1, ans);
				break;
			}
			if (oj < bj) {
				if (op == seq[oj].second)
					pos++;
			} else {
				if (bp == seq[bj].second)
					pos++;
			}
			if (oj != N) {
				if (op < seq[oj].second)
					op++;
				else if (op > seq[oj].second)
					op--;
			}
			if (bj != N) {
				if (bp < seq[bj].second)
					bp++;
				else if (bp > seq[bj].second)
					bp--;
			}
		}
	}
}
