#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>


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
  
  string number;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> number;
    cout << "Case #" << nc << ": ";
    bool found = false;
    int pos = number.size();
    for (int i = number.size() - 1; i >= 0; i--) {
      if (i == 0) {
        continue;
      }
      if (number[i] >= number[i-1]) {
        continue;
      } else {
        pos = i;
        number[i-1] = '0' + (number[i - 1] - '0' - 1);
        continue;
      }
    }
    for (int i = 0; i < number.size(); i++) {
      if (i < pos) {
        if (number[i] == '0') continue;
        cout << number[i];
      } else {
        cout << '9';
      }
    }
    cout << endl;

    // Print output for case j
    
  }


  return 0;
}
