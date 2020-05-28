#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1024;

typedef pair<int,int> pii;

int nt, nt0;
int x, s, r, t, n;
int b[N], e[N], w[N];
pii xv[2*N];
int sx;
double ans, aux;
double ch;

bool check(double d, int v) {
  aux = double(d) / double(v);
  if(ans + aux > t && !ch) {
    aux = t-ans + double(d - v * (t-ans)) / double(v - (r-s));
    ans += aux;
    ch = true;
    r = s;
    //printf("1<%lf %d %lf>\n", d,v,aux);
    return true;
  }
  //printf("2<%lf %d %lf>\n", d,v,aux);
  ans += aux;

  return false;
}

int main() {
  scanf(" %d", &nt0);
  for(nt = 1 ; nt <= nt0 ; nt++) {
    scanf(" %d %d %d %d %d", &x, &s, &r, &t, &n);

    ch = false;
    e[0] = 0;
    ans = 0.0;
    int k = 0;
    for(int i=1 ; i<=n ; i++) {
      scanf(" %d %d %d", &b[i], &e[i], &w[i]);
      xv[k++] = pii(s, b[i]-e[i-1]);
      xv[k++] = pii(s+w[i], e[i]-b[i]);
    }
    xv[k++] = pii(s, x-e[n]);
    sort(xv, xv+k);

    for(int i=0 ; i<k ; i++)
      check(xv[i].second, xv[i].first + (r-s));

    printf("Case #%d: %lf\n", nt, ans);
    /*
    int v = r;
    ch = false;

    e[0] = 0;
    ans = 0.0;
    for(int i=1 ; i<=n ; i++) {
      scanf(" %d %d %d", &b[i], &e[i], &w[i]);

      if(check(b[i]-e[i-1], v)) v = s;
      if(check(e[i]-b[i], v+w[i])) v = s;
    }

    check(x-e[n], v);

    printf("Case #%d: %lf\n", nt, ans);
    */
    /*
    sx = 0;
    ans = 0;
    for(int i=0 ; i<n ; i++) {
      scanf(" %d %d %d", &b[i], &e[i], &w[i]);
      dx[i] = e[i] - b[i];
      sx += dx[i];

      ans += double(dx[i]) / double(s + w[i]);
    }

    double vm = double(x) / ans;
    double R = double(t*vm*r) / double(r);

    ans += double(x - sx - R) / double(s);

    printf("<%d %d %lf>\n", x, (r-s)*t, R);
    printf("Case #%d: %lf\n", nt, ans);
    */
  }
  return 0;
}
