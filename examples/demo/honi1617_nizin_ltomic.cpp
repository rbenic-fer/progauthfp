#include <cstdio>

const int MAXN = 1000006;

int n, A[MAXN], sol;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", A+i);
	}

	int i = 0, j = n-1, prei = -1, prej = n;
	int zbp = 0, zbk = 0;
	for (; i <= j; ++i) {
		zbp += A[i];
		while (zbp > zbk && j > i) {
			zbk += A[j--];
		}
		if (zbk == zbp) {
			sol += (i-prei-1)+(prej-j-2);
			prei = i;
			prej = j+1;
			zbp = 0;
			zbk = 0;
		}
	}
	if (zbk != 0 || zbp != 0) {
		sol += prej-prei-2;
	}
	printf("%d\n", sol);
	return 0;
}
		
