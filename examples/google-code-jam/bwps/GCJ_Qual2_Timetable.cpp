#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int N, T, NA, NB;

list<pair<int, int> > ta;
list<pair<int, int> > tb;

int read_time() {
	string s;
	cin >> s;
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	return h * 60 + m;
}

void input() {
	cin >> T >> NA >> NB;
	ta.clear();
	tb.clear();
	while (NA--) {
		int t = read_time();
		ta.push_back(make_pair(t, 1));
		t = read_time();
		tb.push_back(make_pair(t+T, -1));
	}
	while (NB--) {
		int t = read_time();
		tb.push_back(make_pair(t, 1));
		t = read_time();
		ta.push_back(make_pair(t+T, -1));
	}
	ta.sort();
	tb.sort();
}

pair<int, int> solve() {
	pair<int, int> res = make_pair(0, 0);
	int a = 0, b = 0;
	for (list<pair<int, int> >::iterator i = ta.begin(); i != ta.end(); i++) {
		a += i->second;
		res.first = max(res.first, a);
	}
	for (list<pair<int, int> >::iterator i = tb.begin(); i != tb.end(); i++) {
		b += i->second;
		res.second = max(res.second, b);
	}
	return res;
}

int main() {
	cin >> N;
	for (int tcs = 1; tcs <= N; tcs++) {
		input();
		pair<int, int> res = solve();
		cout << "Case #" << tcs << ": " << res.first << " " << res.second << endl;
	}
	return 0;
}
