#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXK = 16;
const int MAXS = 50001;

void apply(char* buf, int* pat, int k) {
	char local[MAXK];
	while(*buf) {
		memcpy(local, buf, k);
		for (int i=0; i<k; i++)
			buf[i] = local[pat[i]];
		buf+=k;
	}
}

int judge(char* buf) {
	int len = 0;
	char last = 0;
	while (*buf) {
		if (*buf != last) {
			len++;
			last = *buf;
		}
		buf++;
	}
	return len;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n=1; n<=N; n++) {
		int k; 
		char text[MAXS], buf[MAXS];
		int perm[MAXK];

		scanf("%d %s", &k, text);
		for (int i=0; i<k; i++)
			perm[i] = i;
		int res = 2100000000;
		do {
			strcpy(buf, text);
			apply(buf, perm, k);
			int score = judge(buf);
			if (score < res)
				res = score;
		} while(next_permutation(perm, perm+k));
		printf("Case #%d: %d\n", n, res);
	}
	return 0;
}