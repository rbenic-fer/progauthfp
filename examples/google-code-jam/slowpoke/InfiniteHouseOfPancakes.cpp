#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

void comp(int tc){
	int D;
	cin >> D;
	vector<int> v(D);
	for (int &val : v)
		cin >> val;

	int lim = *max_element(v.begin(), v.end());
	int best = numeric_limits<int>::max();
	for (int i = 1; i <= lim; ++i){
		int pen = 0;
		for (int val : v){
			if (val > i){
				pen += (val - 1) / i;
			}
		}
		best = min(best, pen + i);
	}

	cout << "Case #" << tc << ": " << best << endl;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}