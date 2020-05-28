#include <cstdio>
#include <cstring>

const int N = 128;
int n,m;
int a[N][N];
int maxline[N], maxcol[N];

bool check() {
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      if(a[i][j] < maxline[i] &&
	 a[i][j] < maxcol[j])
	return false;
  return true;
}

int main() {
  int ntests;
  scanf(" %d", &ntests);
  for(int nt=1; nt<=ntests; ++nt) {
    scanf(" %d %d", &n, &m);

    memset(maxline, 0, n*sizeof(int));
    memset(maxcol, 0, m*sizeof(int));
    for(int i=0; i<n; ++i)
      for(int j=0; j<m; ++j) {
	scanf(" %d", &a[i][j]);
	if(a[i][j] > maxline[i]) maxline[i] = a[i][j];
	if(a[i][j] > maxcol[j]) maxcol[j] = a[i][j];
      }

    printf("Case #%d: ", nt);
    if(check()) puts("YES");
    else puts("NO");
  }
  return 0;
}
