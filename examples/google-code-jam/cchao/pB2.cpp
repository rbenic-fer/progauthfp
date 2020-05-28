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

int n; double v, x;
double r[110], c[110];

bool ok(double m, bool dbg = false) {
	vector<pdd> a;
	rep(i, n) a.push_back(pdd(c[i], m * r[i]));
	sort(a.begin(), a.end());
	double sum = 0;

	int i = 0, j = a.size() - 1;
	while(i < j) {
		if(dcmp(a[i].first - x) == 0) {
			sum += a[i].second;
			i++;
			continue;
		}
		if(dcmp(a[j].first - x) == 0) {
			sum += a[j].second;
			j--;
			continue;
		}
		if(dcmp(a[i].first - x) == dcmp(a[j].first - x)) break;
		double va = (a[j].first - x);
		double vb = (x - a[i].first);
		double ratio = min(a[i].second / va, a[j].second / vb);
		va *= ratio;
		vb *= ratio;
		sum += va + vb;
		a[i].second -= va;
		a[j].second -= vb;
		if(dcmp(a[i].second) == 0) sum += a[i++].second;
		if(dcmp(a[j].second) == 0) sum += a[j--].second;
	}
	if(dcmp(a[i].first - x) == 0) {
		sum += a[i].second;
		i++;
	}
	if(dbg) printf("time %.12f, sum %.12f\n", m, sum);
	return sum >= v;
	return dcmp(sum - v) >= 0;
}


int main() {
	Ttimes {
		scanf("%d%lf%lf", &n, &v, &x);
		rep(i, n) scanf("%lf%lf", &r[i], &c[i]);


		bool fail = false;
		int aa = 0, bb = 0, cc = 0;
		rep(i, n) {
			int t = dcmp(c[i] - x);
			if(t == 1) aa = 1;
			if(t == -1) bb = 1;
			if(t == 0) cc = 1;
		}
		if(!cc && aa + bb != 2) fail = true;

		double l = 0, r = 1e9, ans;
		ans = r;
		if(!fail) while(dcmp(r - l) == 1) {
			double m = (l + r) / 2;
			if(ok(m)) ans = r = m;
			else l = m;
		}

		printf("Case #%d: ", ks);
		if(fail) puts("IMPOSSIBLE");
		else {
			printf("%.12f\n", r);
		}
	}
	return 0;
}

