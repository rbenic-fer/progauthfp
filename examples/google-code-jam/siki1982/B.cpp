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
#define U unsigned int
#define LU long unsigned
#define LLU long long unsigned




int main() {
  // Declare members
  int num_case;
  cin >> num_case;

  string pcs;
  int num;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> pcs;
    num = 0;
    int par = 1;
    if (pcs[0] == '-') {
      par *= -1;
    }

    for (int i = 1; i < pcs.size(); i++) {
      if (pcs[i] != pcs[i-1]) {
        num++;
        par *= -1;
      }
    }
    if (par == -1) num++;

    // Print output for case j
    cout << "Case #" << nc << ": " << num << endl;
  }


  return 0;
}
