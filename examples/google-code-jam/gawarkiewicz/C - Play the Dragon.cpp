#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

int HdOrg;

int play(int Hd, int Ad, int Hk, int Ak, int B, int D, int best, map<tuple<int, int, int, int>, int>& c) {
	bool ne = c.find(make_tuple(Hd, Ad, Hk, Ak)) == c.end();
	int& ret = c[make_tuple(Hd, Ad, Hk, Ak)];
	if (!ne) return ret;
	ret = 999;
	if (Hk <= 0) return 0;
	Hd -= Ak;
	if (Hd <= 0) return 999;
	int t = 0;
	t = 1 + play(Hd, Ad, Hk - Ad, Ak, B, D, best, c); if (t < ret) ret = t;
	if (B > 0 && Ad < Hk) t = 1 + play(Hd, Ad+B, Hk, Ak, B, D, best, c); if (t < ret) ret = t;
	if (Hd < HdOrg) t = 1 + play(HdOrg, Ad, Hk, Ak, B, D, best, c); if (t < ret) ret = t;
	if (Ak > 0 && D > 0) t = 1 + play(Hd, Ad, Hk, max(Ak-D, 0), B, D, best, c); if (t < ret) ret = t;
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int Hd, Ad, Hk, Ak, B, D;
		cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
		int ret = 0;
		map<tuple<int, int, int, int>, int> c;
		HdOrg = Hd;
		ret = play(Hd+Ak, Ad, Hk, Ak, B, D, 999, c);

		cout << "Case #" << q << ": ";
		if (ret < 999) cout << ret << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}