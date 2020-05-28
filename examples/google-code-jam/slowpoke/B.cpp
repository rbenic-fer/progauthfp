#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <array>
#include <string>
#include <deque>
#include <list>
#include <numeric>
#include <limits>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <assert.h>
#include <iomanip>

using namespace std;

void comp(int tc){
	int N;
	double V, X;
	cin >> N >> V >> X;

	vector<double> r(N), c(N);
	for (int i = 0; i < N; ++i){
		cin >> r[i] >> c[i];
	}

	cout << "Case #" << tc << ": ";
	
	double res = 0;
	if (N == 1){
		if (c[0] != X){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		res = V / r[0];
	}
	else if (N == 2){
		if ((c[0] > X && c[1] > X) ||
			(c[0] < X && c[1] < X)){
			cout << "IMPOSSIBLE" << endl;
			return;
		}

		if (r[0] < r[1]){
			swap(r[0], r[1]);
			swap(c[0], c[1]);
		}

		if (c[0] == X){
			res = V / r[0];
		}
		else if(c[1] == X){
			res = V / r[1];
		}
		else{
			double v0 = -V*(c[1] - X) / (c[0] - c[1]);
			double v1 = V - v0;
			res = max(v0 / r[0], v1 / r[1]);
		}
	}

	cout << fixed << setprecision(20) << res << endl;
	
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}