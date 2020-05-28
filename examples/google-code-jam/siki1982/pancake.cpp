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

void change(string &cakes, int pos) {
  if (cakes[pos] == '-') {
    cakes[pos] = '+';
  } else {
    cakes[pos] = '-';
  }
}

int main() {
  // Declare members
  int num_case;
  cin >> num_case;
  string cakes;
  int K;


  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> cakes;
    cin >> K;

    int num = 0;
    for (int i = 0; i <= cakes.size() - K; ++i) {
      if (cakes[i] == '-') {
        ++num;
        for (int j = 0; j < K; ++j) {
          change(cakes, i + j);
        }
      }
    }
    
    bool possible = true;
    for (int i = cakes.size() - K + 1; i < cakes.size(); ++i) {
      if (cakes[i] == '-') {
        possible = false;
        break;
      }
    }

    // Print output for case j
    if (possible) {
        cout << "Case #" << nc << ": " << num << endl;
    } else {
      cout << "Case #" << nc << ": " << "IMPOSSIBLE" << endl;
    }
  }


  return 0;
}
