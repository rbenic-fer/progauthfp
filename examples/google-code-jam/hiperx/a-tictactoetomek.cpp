#include <cstdio>
#include <cstdlib>

const int N=4;
char m[N][N];
bool complete;

bool check_(char c, int i0, int di, int j0, int dj) {
  for(int i=i0, j=j0;
      i>=0 && i<N && j>=0 && j<N;
      i+=di, j+=dj)
    if(m[i][j] != c &&
       m[i][j] != 'T')
      return false;
  return true;
}

bool check(char c) {
  for(int i=0; i<N; ++i)
    if(check_(c, i, 0, 0, 1)) return true;
  for(int j=0; j<N; ++j)
    if(check_(c, 0, 1, j, 0)) return true;
  if(check_(c, 0, 1, 0, 1)) return true;
  if(check_(c, 0, 1, N-1, -1)) return true;
  return false;
}

int main() {
  int ntests;
  scanf(" %d", &ntests);
  for(int nt=1; nt<=ntests; ++nt) {
    complete = true;
    for(int i=0; i<N; ++i)
      for(int j=0; j<N; ++j) {
	scanf(" %c", &m[i][j]);
	if(m[i][j] == '.') complete = false;
      }
    printf("Case #%d: ", nt);
    if(check('X')) puts("X won");
    else if(check('O')) puts("O won");
    else if(complete) puts("Draw");
    else puts("Game has not completed");
  }
  return 0;
}
