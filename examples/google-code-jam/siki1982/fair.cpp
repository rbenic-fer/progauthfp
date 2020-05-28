#include <iostream>
#include <iomanip>
#include <sstream>

#include <cmath>
#include <algorithm>

#include <map>
#include <vector>

using namespace std;


#define PI acos(-1.)
#define EPS 1e-7

class BigNum{

public:
  BigNum(string num) {
    n.resize(num.size(), 0);
    for (uint32_t i = 0; i < num.size(); i ++) {
      const char ch = num[i];
      n[i]=atoi(&ch);
    }
  }

  uint32_t mod(BigNum bn, uint32_t d) {
    uint32_t pos;
  }

  void print() {
    for (uint32_t i = 0; i < n.size(); i++) {
      cout << n[i];
    }
    cout << endl;
  }

private:
  vector<int> n;
};


int main() {

  // Declare members
  uint32_t num_case;
  cin >> num_case;
  
  uint32_t N;
  vector<uint32_t> events;


  for (int j = 1; j <= num_case; j++) {
    // Init members
    cin >> N;
    events.resize(N, 0);
    uint32_t maxs = 0;
    uint32_t maxt = 0;
    for (int i = 0; i < N; i++) {
      cin >> events[i];
      if (events[i] > maxt) {
	maxt = events[i];
      }
    }

    uint32_t i = 1;
    bool cont = true;
    for (; i <= maxt; i++) {
      // cout << "i: " << i << endl;
      uint32_t mod = events[0]%i;
      uint32_t k = 1;
      for (; k < N; k++) {
	// cout << "k: " << k << endl;
	if (mod != events[k]%i) break;
      }
      if (k == N) maxs = i;
    }
    uint32_t mod = events[0]%maxs;

    // Print output for case j
    cout << "Case #" << j << ": " << (mod==0?0:(maxs - mod)) << endl;
  }


  return 0;
}
