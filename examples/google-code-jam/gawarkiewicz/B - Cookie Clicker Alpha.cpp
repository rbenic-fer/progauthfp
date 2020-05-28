#include <cstdio>
#include <iostream>

using namespace std;

double solve(double C, double F, double X) {
	double ps = 2;
	double ret = 0;
	while (1) {
		if (X / ps <= C/ps + (X/(ps+F))) {
			break;
		}
		else {
			ret += C / ps;
			ps += F;
		}
	}
	ret += X / ps;
	return ret;
}

int main() {
	//cout.precision(8);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		double C, F, X;
		cin >> C >> F >> X;
		double ret = solve(C, F, X);
		//cout << "Case #" << t << ": " << ret << endl;
		printf("Case #%d: %.7f\n", t, ret);
	}
	return 0;
}