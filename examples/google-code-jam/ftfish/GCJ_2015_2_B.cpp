#include <bits/stdc++.h>
using namespace std;

const int mn = 200;
const double eps = 1e-8;

inline int cmp(double x) {
	if (x < -eps)
		return -1;
	return x > eps;
}

int main() {
	//freopen("sample.in", "r", stdin);
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		int n;
		double V, X, v[mn], x[mn];
		cin >> n >> V >> X;

		bool L = 0, LE = 0, G = 0, GE = 0;

		for (int i = 0; i < n; ++i) {
			cin >> v[i] >> x[i];
			if (x[i] < X)
				L = 1;
			if (x[i] <= X)
				LE = 1;
			if (x[i] > X)
				G = 1;
			if (x[i] >= X)
				GE = 1;
		}
//		cout << L << LE << G << GE << endl;

		double ans = -1;

		if (!LE || !GE) {
			ans = -1;
		} else if (!L || !G) {
			double totalv = 0;
			for (int i = 0; i < n; ++i)
				if (x[i] == X)
					totalv += v[i];
			ans = V / totalv;
		} else {
			double l = 0, r = 1e20, m;
			for (int iter = 0; iter <= 300; ++iter) {

				m = (l + r) / 2.0;
				double LV = 0, LX = 0, GV = 0, GX = 0, EV = 0;

				for (int i = 0; i < n; ++i) {
					if (x[i] == X)
						EV += m * v[i];
					else if (x[i] < X) {
						LV += m * v[i];
						LX += m * v[i] * x[i];
					} else {
						GV += m * v[i];
						GX += m * v[i] * x[i];
					}
				}
				LX /= LV;
				GX /= GV;

				double tmpGV = (LX * LV - X * LV) / (X - GX);
				double tmpLV = (GX * GV - X * GV) / (X - LX);
				if ((GV >= tmpGV && LV + tmpGV + EV >= V)
						|| (LV >= tmpLV && tmpLV + GV + EV >= V)) {
					r = m;
				} else {
					l = m;
				}
			}
			ans = (l + r) / 2;
		}

		printf("Case #%d: ", Tn);
		if (ans < 0)
			puts("IMPOSSIBLE");
		else
			printf("%.10f\n", ans);
	}
	return 0;
}
