#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double EPS = 1e-9;
const double PI  = 2*acos(0);

int N;
double f, R, RR, t, r, g;

double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx*dx + dy*dy);
}

double sector(double x1, double y1, double x2, double y2) {
	double triangle = 0.5 * fabs(x1*y2 - x2*y1);
	double alpha = acos((x1*x2 + y1*y2) / (dist(0, 0, x1, y1) * dist(0, 0, x2, y2)));
	return 0.5*RR*RR*alpha - triangle;
}

double area(double x, double y) {
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	if (dist(0, 0, x - g/2, y - g/2) >= RR) return 0;
	if (dist(0, 0, x + g/2, y + g/2) <= RR) return g*g;
	double d1 = dist(0, 0, x - g/2, y + g/2);
	double d2 = dist(0, 0, x + g/2, y - g/2);
	if (d1 >= RR && d2 >= RR) {
		double sx = sqrt(fabs(RR*RR - (y - g/2)*(y - g/2)));
		double sy = sqrt(fabs(RR*RR - (x - g/2)*(x - g/2)));
		return 0.5 * (sx - x + g/2) * (sy - y + g/2) + sector(sx, y - g/2, x - g/2, sy);
	} else if (d1 >= RR && d2 < RR) {
		double sy1 = sqrt(fabs(RR*RR - (x - g/2)*(x - g/2)));
		double sy2 = sqrt(fabs(RR*RR - (x + g/2)*(x + g/2)));
		return 0.5 * g * (sy1 - sy2) + sector(x + g/2, sy2, x - g/2, sy1) + g * (sy2 - y + g/2);
	} else if (d1 < RR && d2 >= RR) {
		double sx1 = sqrt(fabs(RR*RR - (y + g/2)*(y + g/2)));
		double sx2 = sqrt(fabs(RR*RR - (y - g/2)*(y - g/2)));
		return 0.5 * g * (sx2 - sx1) + sector(sx2, y - g/2, sx1, y + g/2) + g * (sx1 - x + g/2);
	} else {
		double sx = sqrt(fabs(RR*RR - (y + g/2)*(y + g/2)));
		double sy = sqrt(fabs(RR*RR - (x + g/2)*(x + g/2)));
		return 0.5 * (x + g/2 - sx) * (y + g/2 - sy) + sector(x + g/2, sy, sx, y + g/2)
		     + g * (sx - x + g/2) + g * (sy - y + g/2) - (sx - x + g/2) * (sy - y + g/2);
	}
}

double solve() {
	g -= 2*f;
	r += f;
	RR = R - t - f;
	if (RR <= 0 || g <= 0) return 1;
	double d = g + 2*r;
	double res = 0;
	double x = r + g/2;
	while (1) {
		x += d;
		double y = r + g/2;
		double v = area(x, y);
		if (v < EPS) break;
		res += v;
		while (1) {
			y += d;
			double v = area(x, y);
			if (v < EPS) break;
			res += v;
		}
		y = r + g/2;
		while (1) {
			y -= d;
			double v = area(x, y);
			if (v < EPS) break;
			res += v;
		}
	}
	x = r + g/2 + d;
	while (1) {
		x -= d;
		double y = r + g/2;
		double v = area(x, y);
		if (v < EPS) break;
		res += v;
		while (1) {
			y += d;
			double v = area(x, y);
			if (v < EPS) break;
			res += v;
		}
		y = r + g/2;
		while (1) {
			y -= d;
			double v = area(x, y);
			if (v < EPS) break;
			res += v;
		}
	}
	return 1.0 - res / (R*R*PI);
}

int main() {
	cin >> N;
	for (int tcs = 1; tcs <= N; tcs++) {
		cin >> f >> R >> t >> r >> g;
		printf("Case #%d: %.6lf\n", tcs, solve());
	}
	return 0;
}
