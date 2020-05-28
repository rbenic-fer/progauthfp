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

struct S {
  S(uint32_t a_, uint32_t b_) {
    a = a_;
    b = b_;
  }

  uint32_t a;
  uint32_t b;
};

int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;
  vector<S> wires;
  uint32_t N, A, B;

  
  for (int j = 1; j <= num_case; j++) {
    // Init members
    wires.clear();
    cin >> N;

    for (uint32_t i = 0; i < N; i++) {
      cin >> A >> B;
      wires.push_back(S(A,B));
    }

    uint32_t inter = 0;
    for (uint32_t i = 0; i < N - 1; i++) {
      for (uint32_t j = i + 1; j < N; j++) {
	if ((wires[i].a < wires[j].a && wires[i].b > wires[j].b) || 
	    (wires[i].a > wires[j].a && wires[i].b < wires[j].b)) {
	  inter++;
	}
      }
    }

    // Print output for case j
    cout << "Case #" << j << ": " << inter << endl;
  }


  return 0;
}
