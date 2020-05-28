#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <limits>
#include <utility>
#include <functional>
#include <iterator>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdlib>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace boost::multiprecision;

void comp(int tc){
	int N;
	cin >> N;
	vector<int> ori(N);
	for (int i = 0; i < N; ++i){
		cin >> ori[i];
	}

	int count = 0;

	for (int i = 0; i < N; ++i){
		auto it = min_element(ori.begin(), ori.end());
		count += min((int)(it - ori.begin()), (int)(ori.end() - 1 - it));
		ori.erase(it);
	}

	cout << "Case #" << tc << ": " << count << endl;
}

int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		comp(tc);
	}
}