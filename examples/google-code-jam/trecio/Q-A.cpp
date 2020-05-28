#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

istream& operator>> (istream& ins, vector<vector<int> > &out) {
	out.resize(4);
	for (int i=0; i<4; i++) {
		out[i].resize(4);
		for (int j=0; j<4; j++) {
			ins >> out[i][j];
		}
	}
	return ins;
}

int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int a_first, a_second;
		vector<vector<int> > first, second;
		cin >> a_first >> first >> a_second >> second;

		vector<int> r_first = first[a_first-1],
			r_second = second[a_second-1];

		sort(r_first.begin(), r_first.end());
		sort(r_second.begin(), r_second.end());
		vector<int> out(4);
		vector<int>::iterator out_end = set_intersection(r_first.begin(), r_first.end(), r_second.begin(), r_second.end(), out.begin());
		out.resize(out_end - out.begin());

		cout << "Case #" << t << ": ";
		switch (out.size()) {
		case 0:
			cout << "Volunteer cheated!" << endl;
			break;
		case 1:
			cout << out[0] << endl;
			break;
		default:
			cout << "Bad magician!" << endl;
		}
	}
	return 0;
}