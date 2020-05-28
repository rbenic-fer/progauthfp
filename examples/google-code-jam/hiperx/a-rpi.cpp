#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 128;

int nt, nt0;
int n;
int lista[N][N], q[N];
double WP[N][N], OWP[N], OOWP[N];
char tab[N][N];

int main() {
  scanf(" %d", &nt0);
  for(nt = 1 ; nt <= nt0 ; nt++) {
    scanf(" %d", &n);

    for(int i=0 ; i<n ; i++) {
      q[i] = 0;
      for(int j=0 ; j<n ; j++) {
	scanf(" %c", &tab[i][j]);
	if(tab[i][j] != '.')
	  lista[i][q[i]++] = j;
      }
    }

    for(int jog=0 ; jog<n ; jog++) {
      int sum = 0;
      for(int i=0 ; i<q[jog] ; i++) {
	int k=lista[jog][i];
	sum += tab[jog][k] - '0';
      }
      WP[jog][jog] = double(sum) / double(q[jog]);
      for(int i=0 ; i<q[jog] ; i++) {
	int k=lista[jog][i];
	WP[jog][k] = double(sum - (tab[jog][k] - '0')) / double(q[jog] - 1);
      }
    }

    for(int jog=0 ; jog<n ; jog++) {
      double sum = 0.0;
      for(int i=0 ; i<q[jog] ; i++) {
	int k=lista[jog][i];
	sum += WP[k][jog];
      }
      OWP[jog] = sum / double(q[jog]);
    }

    for(int jog=0 ; jog<n ; jog++) {
      double sum = 0.0;
      for(int i=0 ; i<q[jog] ; i++) {
	int k=lista[jog][i];
	sum += OWP[k];
      }
      OOWP[jog] = sum / double(q[jog]);
    }

    printf("Case #%d:\n", nt);
    for(int jog=0 ; jog<n ; jog++) {
      double RPI = WP[jog][jog]/4 + OWP[jog]/2 + OOWP[jog]/4;
      printf("%.6lf\n", RPI);
    }
  }
  return 0;
}
