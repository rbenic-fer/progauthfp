#include <cstdio>

void show (int num, int len){
	if (len){
		int b = num % 2;
		printf("%d", b);
		show (num / 2, len - 1);
		printf("%d", b);
	}
}

int main (){
	freopen ("C-large.in", "r", stdin);
	freopen ("C-large.out", "w", stdout);
	int T, N, J;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		printf("Case #%d:\n", i);
		scanf("%d %d", &N, &J);
		// Assume N is even
		for (int j = 0; j < J; j++){
			printf("1");
			show (j, N / 2 - 1);
			printf("1");
			for (int k = 2; k <= 10; k++)
				printf(" %d", k + 1);
			printf("\n");
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
