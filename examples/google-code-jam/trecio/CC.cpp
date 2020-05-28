#include <cstdio>
#include <set>
using namespace std;

int main() {
	int T; 
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int K;
		scanf("%d", &K);

		set<int> cards;
		for (int i=1; i<=K; i++)
			cards.insert(i);

		int rtab[5001];
		int pos = 1;
		set<int>::iterator i = cards.end();
		i--;

		for (int card = 1; card <= K; card++) {
			int c = card%cards.size();
			while (c--) {
				i++;
				if (i == cards.end())
					i = cards.begin();
			}
			rtab[*i] = card;
			set<int>::iterator j = i;
			if (i==cards.begin())
				i = cards.end();
			i--;
			cards.erase(j);
		}

		printf("Case #%d:", t);

		int n;
		scanf("%d", &n);
		while (n--) {
			int di;
			scanf("%d", &di);
			printf(" %d", rtab[di]);
		}
		printf("\n");
	}
	return 0;
}