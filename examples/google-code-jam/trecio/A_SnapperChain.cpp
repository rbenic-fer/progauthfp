#include <cstdio>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int n, k;
		scanf("%d%d", &n, &k);
		int powered=0;
		while (k&1) {
			powered++;
			k/=2;
		}
		printf("Case #%d: %s\n", t, powered >= n ? "ON" : "OFF");
	}
	return 0;
}