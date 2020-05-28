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
#define UI unsigned int
#define LLU unsigned long long


bool is_p(LLU n) {
  stringstream ss;
  ss.clear();
  ss << n;
  string str = ss.str();
  size_t s = str.size();
  for (size_t i = 0; 2*i < s; ++i) {
    if (str[i] != str[s - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  // Pre calculations
  UI max = 10000000;
  vector<int> numtil(max + 1, 0);
  int countr = 0;
  for (LLU i = 1; i <= max; ++i) {
    if (is_p(i)) {
      if (is_p(i*i)) {
        numtil[i] = countr;
        ++countr;
        continue;
      }
    }
    numtil[i] = countr;
  }

  // Declare members
  int num_case;
  cin >> num_case;

  LLU A, B;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> A;
    cin >> B;

    int a = ceil(sqrt(A));
    int b = floor(sqrt(B));

    // Print output for case j
    cout << "Case #" << nc << ": " << numtil[b + 1] - numtil[a] << endl;
  }


  return 0;
}
