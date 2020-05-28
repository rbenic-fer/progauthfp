#include <cstdio>
#include <cstring>

using namespace std;

bool b[100];

int main () {
	int C;
	scanf("%d", &C);
	for (int T=1; T<=C; T++) {
		memset(b,0,sizeof(b));
		int ans;
		scanf("%d", &ans);
		for (int i=1; i<=4; i++) {
			for (int j=1; j<=4; j++) {
				int x;
				scanf("%d", &x);
				if (i == ans) b[x] = 1;
				else b[x] = 0;
			}
		}
		scanf("%d", &ans);
		for (int i=1; i<=4; i++) {
			for (int j=1; j<=4; j++) {
				int x;
				scanf("%d", &x);
				if (i == ans) b[x] = (b[x] && 1);
				else b[x] = 0;
			}
		}
		int cnt=0, out;
		for (int i=1; i<=16; i++) {
			if (b[i]) {
				cnt++;
				out=i;
			}
		}
		printf("Case #%d: ", T);
		if (cnt == 1) printf("%d\n", out);
		else if (cnt > 1) printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
	return 0;
}
