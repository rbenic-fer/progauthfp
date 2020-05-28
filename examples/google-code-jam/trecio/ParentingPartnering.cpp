#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct period {
	int from;
	int to;
	char who;

	int duration() const {
		return to - from;
	}

	bool operator<(const period& other) {
		return from < other.from;
	}
};

bool by_duration_descending(const period& left, const period& right) {
	return left.duration() > right.duration();
}

int get_time(const vector<period>&p, char who) {
	int t = 0;
	for (unsigned i = 0; i < p.size(); i += 1) {
		if (p[i].who == who) {
			t += p[i].duration();
		}
	}
	return t;
}

void dump(const vector<period>&p, char who) {
	cerr << who << ":";
	for (int i = 0; i < p.size(); i += 1){
		if (p[i].who == who) {
			cerr << "(" << p[i].from << ", " << p[i].to << ": " << p[i].duration() << ")\t";
		}
	}
	cerr << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		int ac, aj;
		cin >> ac >> aj;
		vector<period> p;
		p.resize(ac + aj);
		for (int i = 0; i < ac + aj; i += 1) {
			cin >> p[i].from >> p[i].to;
		}
		for (int i = 0; i < ac; i += 1) {
			p[i].who = 'J';
		}
		for (int i = ac; i < ac + aj; i += 1){
			p[i].who = 'C';
		}
		sort(p.begin(), p.end());

		dump(p, 'C');
		dump(p, 'J');

		int c_t = 720 - get_time(p, 'C');
		int j_t = 720 - get_time(p, 'J');

		cerr << "Capacity: C = " << c_t << " J = " << j_t << endl;

		
		vector<period> to_take;
		for (unsigned i = 1; i < p.size(); i += 1) {
			period pp;
			pp.to = p[i].from;
			pp.from = p[i - 1].to;
			pp.who = p[i].who == p[i - 1].who
				? p[i].who
				: '?';
			to_take.push_back(pp);
		}
		period pp;
		pp.from = p[p.size() - 1].to;
		pp.to = p[0].from + 1440;
		pp.who = p[0].who == p[p.size() - 1].who
			? p[0].who
			: '?';
		to_take.push_back(pp);

		sort(to_take.begin(), to_take.end(), by_duration_descending);
		for (int i = to_take.size() - 1; i >= 0; i -= 1) {
			switch (to_take[i].who)
			{
			case 'C':
				if (to_take[i].duration() < c_t) {
					p.push_back(to_take[i]);
					c_t -= to_take[i].duration();
					to_take.erase(to_take.begin() + i);
					cerr << "C: (" << to_take[i].from << ", " << to_take[i].to << ": " << to_take[i].duration() << ")" << endl;
				}
				break;
			case 'J':
				if (to_take[i].duration() < j_t) {
					p.push_back(to_take[i]);
					j_t -= to_take[i].duration();
					to_take.erase(to_take.begin() + i);
					cerr << "J: (" << to_take[i].from << ", " << to_take[i].to << ": " << to_take[i].duration() << ")" << endl;
				}
				break;
			}
		}

		cerr << "Capacity: C = " << c_t << " J = " << j_t << endl;

		int result = 0;
		for (unsigned i = 0; i < to_take.size(); i += 1) {
			if (to_take[i].who == '?') {
				result += 1;
				cerr << "Switch between " << to_take[i].from << " and " << to_take[i].to << endl;
			}
			else {
				result += 2;
				cerr << "Switch between " << to_take[i].from << " and " << to_take[i].to << " and back" << endl;
			}
		}
		cout << "Case #" << t << ": " << result << endl;
		cerr << "Case #" << t << ": " << result << endl;
	}
	return 0;
}