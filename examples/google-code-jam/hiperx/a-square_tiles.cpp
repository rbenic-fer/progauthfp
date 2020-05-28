#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 64;

int nt, nt0;
int r, c;
char tab[N][N];

bool check(int i, int j) {
  if(i+1 >= r || j+1 >= c) return false;
  if(tab[i+1][j] != '#') return false;
  if(tab[i][j+1] != '#') return false;
  if(tab[i+1][j+1] != '#') return false;

  tab[i][j] = '/';
  tab[i+1][j] = '\\';
  tab[i][j+1] = '\\';
  tab[i+1][j+1] = '/';

  return true;
}

int main() {
  scanf(" %d", &nt0);
  for(nt = 1 ; nt <= nt0 ; nt++) {
    scanf(" %d %d", &r, &c);
    for(int i=0 ; i<r ; i++)
      for(int j=0 ; j<c ; j++)
	scanf(" %c", &tab[i][j]);

    bool error = false;
    for(int i=0 ; i<r && !error ; i++)
      for(int j=0 ; j<c ; j++)
	if(tab[i][j] == '#')
	  if(!check(i,j)) {
	    error = true;
	    break;
	  }

    printf("Case #%d:\n", nt);
    if(error)
      printf("Impossible\n");
    else
      for(int i=0 ; i<r ; i++) {
	for(int j=0 ; j<c ; j++)
	  putchar(tab[i][j]);
	putchar('\n');
      }
  }
  return 0;
}
