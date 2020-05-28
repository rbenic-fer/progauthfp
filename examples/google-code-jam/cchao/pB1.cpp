#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

double r[110], c[110];

int main() {
	Ttimes {
		int n; double v, x;
		scanf("%d%lf%lf", &n, &v, &x);
		rep(i, n) scanf("%lf%lf", &r[i], &c[i]);

		double ans = 0;
		bool fail = false;
		if(n == 1) {
			if(dcmp(c[0] - x) != 0) fail = true;
			else ans = v / r[0];
		}
		else {
			if(dcmp(c[0] - c[1]) == 0) {
				if(dcmp(c[0] - x) != 0) fail = true;
				else ans = v / (r[0] + r[1]);
			}
			else if(dcmp(c[0] - x) == dcmp(c[1] - x)) fail = true;
			else {
				if(c[0] > c[1]) {
					swap(c[0], c[1]);
					swap(r[0], r[1]);
				}
				double tb = (x - c[0]) / r[1];
				double ta = (c[1] - x) / r[0];
//				printf("time %f %f -> produce %f\n", ta, tb, (ta * c[0] + tb * c[1]) / (c[0] + c[1]));
				
				double q = ta * r[0] + tb * r[1];
				double t = max(ta, tb);

				ans = v / q * t;
			}
		}
		printf("Case #%d: ", ks);
		if(fail) puts("IMPOSSIBLE");
		else printf("%.9f\n", ans);
	}
	return 0;
}

