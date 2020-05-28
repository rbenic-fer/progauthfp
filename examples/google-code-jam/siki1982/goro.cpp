#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long


double num[1001];

int f(int num) {
  return (num - 1)*2;
}


int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;



  for (int j = 1; j <= num_case; j++) {
    // Init members
    int num;
    
    cin >> num;

    vector<int> vals(num + 1);
    vector<bool> touch(num + 1);

    for (int i = 1; i <= num; ++i) {
      cin >> vals[i];
      touch[i] = false;
    }

    int res = 0;
    for (int i = 1; i <= num; ++i) {
      if (!touch[i]) {
	int next = vals[i];
	int num = 1;
	while (next != i) {
	  num++;
	  touch[next] = true;
	  next = vals[next];
	}
	res += f(num);
      }
    }


    // Print output for case j
    cout << "Case #" << j << ": "  << res << ".000000" << endl;
  }


  return 0;
}
