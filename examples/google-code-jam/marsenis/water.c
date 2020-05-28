#include <stdio.h>
#define MAXINT 100000
#define MAX 200

int map[MAX][MAX], h, w, coords[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
char res_map[MAX][MAX] = {0};

void dfs(int x, int y, char let) {
  int mn, i, j;
  
  while (res_map[x][y]==0) {
    res_map[x][y] = let;
    mn = MAXINT;
    for (i=0; i<4; i++)
      if (x+coords[i][0]<=h && x+coords[i][0]>=1 && y+coords[i][1]<=w && y+coords[i][1]>=1 && map[x+coords[i][0]][y+coords[i][1]]<mn)
	mn = map[x+coords[i][0]][y+coords[i][1]];
    if (mn==MAXINT || mn>=map[x][y]) return;
    for (i=0; i<4; i++)
      if (x+coords[i][0]<=h && x+coords[i][0]>=1 && y+coords[i][1]<=w && y+coords[i][1]>=1 && map[x+coords[i][0]][y+coords[i][1]]==mn) break;
    x += coords[i][0];
    y += coords[i][1];
  }
  
  for (i=1; i<=h; i++)
    for (j=1; j<=w; j++) if (res_map[i][j]==let) res_map[i][j] = res_map[x][y];
}

void print() {
  int i, j;
  for (i=1; i<=h; i++) {
    for (j=1; j<=w; j++)
      printf("%c ", res_map[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  int t, x, i, j;
  char let;
  
  scanf("%d", &t);
  for (x=1; x<=t; x++) {
    scanf("%d %d", &h, &w);
    
    for (i=1; i<=h; i++)
      for (j=1; j<=w; j++) {
	scanf("%d", &map[i][j]);
	res_map[i][j] = 0;
      }
    
    let = 'a';
    for (i=1; i<=h; i++)
      for (j=1; j<=w; j++)
	if (!res_map[i][j]) { dfs(i, j, let); if (res_map[i][j]==let) let++; /*printf("%d:\n", j); print();*/ }
    
    printf("Case #%d:\n", x);
    for (i=1; i<=h; i++) {
      printf("%c", res_map[i][1]);
      for (j=2; j<=w; j++) printf(" %c", res_map[i][j]);
      printf("\n");
    }
  }
}
