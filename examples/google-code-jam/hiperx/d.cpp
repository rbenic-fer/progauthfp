#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 0x3f3f3f3f

const double EPS = 1e-8;
const double pi = acos(-1);

inline int cmp(double a, double b = 0){
  if(fabs(a-b)<=EPS) return 0;
  if(a<b) return -1;
  return 1;
}

struct point {
  double x,y;
  point(double x = 0, double y = 0): x(x), y(y) {}

  point operator +(point q){ return point(x + q.x, y + q.y); }
  point operator -(point q){ return point(x - q.x, y - q.y); }
  point operator *(double t){ return point(x * t, y * t); }
  point operator /(double t){ return point(x / t, y / t); }
  double operator *(point q){ return x * q.x + y * q.y; }
  double operator %(point q){ return x * q.y - y * q.x; }
};

typedef vector<point> poly;
typedef point vetor;

double norma(vetor v){ return hypot(v.x, v.y); }
vetor versor(vetor v){ return v/norma(v); }

int n;
poly p;
double r[3];

int main() {
  int nt0;
  point k;

  scanf(" %d", &nt0);
  rep(nt,nt0) {
    p.clear();
    scanf(" %d", &n);
    rep(i,n) {
      scanf(" %lf %lf %lf", &k.x, &k.y, &r[i]);
      p.push_back(k);
    }

    double ans = double(INF);

    if(n == 3) {
      rep(i,n) for(int j=i+1 ; j<n ; j++) {
	vetor v = p[i] - p[j];
	vetor v_ = versor(v);

	v = v_ * (norma(v) + r[i] + r[j]);
	int outro = 3 - i - j;
	ans = min(ans, max(r[outro], norma(v)/2.0));
      }
    } else if(n == 2) {
      vetor v = p[0] - p[1];
      vetor v_ = versor(v);

      v = v_ * (norma(v) + r[0] + r[1]);
      ans = norma(v)/2.0;
    } else ans = r[0];

    printf("Case #%d: %lf\n", nt+1, ans);
  }

  return 0;
}
