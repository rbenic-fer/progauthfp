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


LL coun(LL l, LL p, LL c) {
  //cerr << l << " " <<  p << endl;
  LL L = l;
  LL P = p;
  if (l*c >= p) return 0;
  LL test = 0;
  while (l < p) {
    l*=c;
    p=ceil((double)p/c);
  }
  LL down = coun(L, (l+p)/2, c);
  LL up = coun((l+p)/2, P, c);
  test = 1 + (up>down?up:down);
  return test;
}


int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;
  LL L, P, C;


  for (int j = 1; j <= num_case; j++) {
    // Init members
    cin >> L >> P >> C;    
    
    // Print output for case j
    cout << "Case #" << j << ": " << coun(L, P, C) << endl;
  }


  return 0;
}
