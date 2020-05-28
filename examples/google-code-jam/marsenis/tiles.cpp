#include <cstdio>
#define MAX 55

using namespace std;

char M[MAX][MAX];
int r, c;

int check(int i, int j) {
	return i>=1 && i<=r && j>=1 && j<=c && M[i][j] == '#';
}

int main() {
	int t, z, i, j, con;

	scanf("%d", &t);
	for (z=1; z<=t; z++) {
		scanf("%d %d\n", &r, &c);
		for (i=1; i<=r; i++) {
			for (j=1; j<=c; j++)
				scanf("%c", &M[i][j]);
			scanf("\n");
		}

		con = 1;
		for (i=1; i<=r && con; i++)
			for (j=1; j<=c && con; j++) {
				if ( M[i][j] == '#' && check(i+1, j) && check(i, j+1) && check(i+1, j+1) )
				{
					M[i][j] = M[i+1][j+1] = '/';
					M[i+1][j] = M[i][j+1] = '\\';
				} else if ( M[i][j] == '#' ) con = 0;
			}

		printf("Case #%d:\n", z);
		if ( con )
			for (i=1; i<=r; i++) {
				for (j=1;j<=c; j++)
					printf("%c", M[i][j]);
				printf("\n");
			}
		else printf("Impossible\n");
	}
	return 0;
}
