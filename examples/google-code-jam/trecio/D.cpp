#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
template<class T>
T sqr(T x) { return x*x;}
const int MAXN=40;
int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		double x[MAXN], y[MAXN], r[MAXN];
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> x[i] >> y[i] >> r[i];

		double a = sqrt(sqr(x[0]-x[1])+sqr(y[0]-y[1]))+r[0]+r[1];
		double b = sqrt(sqr(x[0]-x[2])+sqr(y[0]-y[2]))+r[0]+r[2];
		double c = sqrt(sqr(x[1]-x[2])+sqr(y[1]-y[2]))+r[1]+r[2];

		double res;

		switch(n) {
			case 1:
				res = r[0];
				break;
			case 2:
				res = max(r[0], r[1]);
				break;
			case 3:
				if (a <=b && a<=c) res = a/2;
				else if (b<=a && b<=c) res = b/2;
				else {
					assert(c <= a && c <= b);
					res = c/2;
				}
				break;
		}
		printf("Case #%d: %lf\n", t, res);
	}	
	return 0;
}