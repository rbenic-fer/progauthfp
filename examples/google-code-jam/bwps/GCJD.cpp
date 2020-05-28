#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

struct Point {
	double x, y;
	Point(double x=0, double y=0) : x(x), y(y) {}
};

double intersect(double r, double R, double d) {
	return r*r*acos((d*d + r*r - R*R)/(2*d*r)) +
		   R*R*acos((d*d + R*R - r*r)/(2*d*R)) -
		   0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));
}

int T, N, M;
Point P[20], Q[20];

double dist(Point a, Point b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N >> M;
		FOR(i, 0, N) cin >> P[i].x >> P[i].y;
		FOR(i, 0, M) cin >> Q[i].x >> Q[i].y;
		cout << "Case #" << cs << ":";
		FOR(i, 0, M) {
			printf(" %.7lf", intersect(dist(P[0], Q[i]), dist(P[1], Q[i]), dist(P[0], P[1])));
		}
		cout << endl;
	}
	return 0;
}
