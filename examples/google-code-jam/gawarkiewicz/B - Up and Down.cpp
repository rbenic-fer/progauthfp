#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int licz(vector<int> v1, const vector<int>& v2) {
	int ret = 0;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] == v2[i]) continue;
		auto it = find(v1.begin(), v1.end(), v2[i]);
		ret += it - (v1.begin() + i);
		v1.erase(it);
		v1.insert(v1.begin() + i, v2[i]);
	}
	return ret;
}

bool isok(vector<int>& v) {
	int p = 1;
	for (int i = 1; i < v.size(); ++i) {
		if (p == 1) {
			if (v[i - 1] > v[i]) {
				p = 2;
			}
		}
		else {
			if (v[i - 1] < v[i]) return false;
		}
	}
	return true;
}

int brut(vector<int> v) {
	auto vOrg(v);
	sort(v.begin(), v.end());
	int ret = v.size()*v.size();
	do {
		if (isok(v)) {
			int r = licz(vOrg, v);
			ret = min(ret, r);
		}
	} while (next_permutation(v.begin(), v.end()));
	return ret;
}

int solve(vector<int> v) {
	{
		auto sorted(v);
		sort(sorted.begin(), sorted.end());
		map<int, int> m;
		for (auto& t : sorted) m[t] = m.size();
		for (auto& t : v) t = m[t];
	}
	int m = v[0];
	for (auto& t : v) m = max(m, t);
	int ret = 0;
	for (int cur = m - 1; cur >= 0; --cur) {
		auto pmax = find(v.begin(), v.end(), m);
		auto pcur = find(v.begin(), v.end(), cur);
		auto p1 = min(pmax, pcur);
		auto p2 = max(pmax, pcur); ++p2;
		for (auto it = p1;; --it) {
			if (it == p1) {} else
			if (*it > cur) p1 = it;
			if (it == v.begin()) break;
		}
		for (auto it = p2;; ++it) {
			//if (it == p2) continue;
			if (it == v.end()) break;
			if (*it > cur) { p2 = it; ++p2; }
		}
		int d1 = pcur - p1, d2 = p2 - pcur;
		if (pcur - p1 < p2 - pcur) {
			int dst = pcur - p1;
			ret += dst;
			if (dst > 0) {
				int p = pcur - v.begin();
				v.insert(p1, cur);
				pcur = v.begin() + p;
				v.erase(pcur);
			}
		}
		else {
			int dst = p2 - pcur - 1;
			ret += dst;
			if (dst > 0) {
				int p = pcur - v.begin();
				v.insert(p2, cur);
				pcur = v.begin() + p;
				v.erase(pcur);
			}
		}
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (auto& t : v) cin >> t;
		cout << "Case #" << q << ": " << brut(v) << endl;
	}
	return 0;
}