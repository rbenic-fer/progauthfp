#include <cstdio>
#include <iostream>
using namespace std;
int T, X, R, C;
int main() {
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d%d%d", &X, &R, &C);
		if (R > C)
			swap(R, C);
		bool flag = false;
		if (X == 1) {
			flag = true;
		} else if (X == 2) {
			flag =
				(R == 1 && C == 2) ||
				(R == 1 && C == 4) ||
				(R == 2 && C == 2) ||
				(R == 2 && C == 3) ||
				(R == 2 && C == 4) ||
				(R == 3 && C == 4) ||
				(R == 4 && C == 4);
		} else if (X == 3) {
			flag =
				(R == 2 && C == 3) ||
				(R == 3 && C == 3) ||
				(R == 3 && C == 4);
		} else if (X == 4) {
			flag =
				(R == 3 && C == 4) ||
				(R == 4 && C == 4);
		}
		printf("Case #%d: %s\n", cas, flag ? "GABRIEL" : "RICHARD");
	}
	return 0;
}