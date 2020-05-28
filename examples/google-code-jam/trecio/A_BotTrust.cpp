#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN=100;

typedef pair<string, int> psi;
typedef vector<psi> vpsi;

const int FINISH = 1000000;
unsigned seek(vpsi& data, int start, const string& what) {
	for (int i=start+1; i<data.size(); i++)
		if (data[i].first == what)
			return i;
	return FINISH;
}

int main() {
	ios_base::sync_with_stdio(false);

	const string O = "O";
	const string B = "B";

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int n;
		cin >> n;

		vpsi seq(n);
		for (int i=0; i<n; i++) 
			cin >> seq[i].first >> seq[i].second;

		int o_pos = 1, o_next;
		int b_pos = 1, b_next;
		bool o_finish=false, b_finish = false;
		o_next = seek(seq, -1, O);
		b_next = seek(seq, -1, B);

		int rounds = 0;
		while (b_next != FINISH || o_next != FINISH) {
			rounds++;

			bool b_press = false, o_press = false;

			if (o_next != FINISH && o_pos == seq[o_next].second && o_next < b_next) {
				o_next = seek(seq, o_next, O);
				o_press = true;
			} else if (b_next != FINISH && b_pos == seq[b_next].second && b_next < o_next) {
				b_next = seek(seq, b_next, B);
				b_press = true;
			}

			if (b_next != FINISH && !b_press && b_pos != seq[b_next].second)
				b_pos += 2*(b_pos < seq[b_next].second)-1;
			if (o_next != FINISH && !o_press && o_pos != seq[o_next].second)
				o_pos += 2*(o_pos < seq[o_next].second)-1;
		}

		printf("Case #%d: %d\n", t, rounds);
	}
	return 0;
}