#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1024;

int nt, nt0;
int l, t, n, c;

bool boost[N];
int a[N];

int test() {
  double time = .0;

  for(int i=0 ; i<n ; i++)
    if(boost[i]) {
      double delta = max(.0, t - time);
      time += delta + (a[i%c] - delta/2.);
    }
    else time += 2 * a[i%c];

  return int(time);
}

int main() {
  scanf(" %d", &nt0);
  for(nt = 1 ; nt <= nt0 ; nt++) {
    scanf(" %d %d %d %d", &l, &t, &n, &c);
    for(int i=0 ; i<c ; i++)
      scanf(" %d", &a[i]);

    for(int i=0 ; i<n-l ; i++)
      boost[i] = false;
    for(int i=n-l ; i<n ; i++)
      boost[i] = true;

    int ans = 0x7f7f7f7f;
    do {
      int x = test();
      ans = min(ans, x);
    } while(next_permutation(boost, boost+n));

    printf("Case #%d: %d\n", nt, ans);
  }
  return 0;
}
