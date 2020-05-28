#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50

int n, cnt;
char mat[MAX][MAX];

int check(char mat[MAX]) { int i; for (i=n; i>=1; i--) if (mat[i]) return n-i; return n;}

int min(int a, int b) { return a<b ? a : b; }
int max(int a, int b) { return a>b ? a : b; }

void swap(int r1, int r2) {
  int i, tmp;
  
  for (i=1; i<=n; i++) {
    tmp = mat[r1][i];
    mat[r1][i] = mat[r2][i];
    mat[r2][i] = tmp;
  }
  
  cnt++;
}

void trans(int r1, int r2) { int i; for (i=r2; i>r1; i--) swap(i, i-1); }


int main() {
  int t, i, j, x, dist, pos;
  
  scanf("%d", &t);
  for (x=1; x<=t; x++) {
    scanf("%d\n", &n);
    cnt = 0;
    
    for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) {
	scanf("%c", &mat[i][j]);
	mat[i][j]-='0';
      }
      scanf("\n");
     }
    
    for (i=1; i<=n; i++) {
      if (check(mat[i]) >= n-i) continue;
      dist = MAX+1;
      for (j=i+1; j<=n; j++) if ( check(mat[j]) >= n-i && abs(i-j)<dist ) { dist = abs(i-j); pos = j; }
      //printf("%d %d %d\n", i, pos, mat[i][1]);
      trans( min(i, pos), max(i, pos) );
    }
    
    printf("Case #%d: %d\n", x, cnt);
  }
  return 0;
}
