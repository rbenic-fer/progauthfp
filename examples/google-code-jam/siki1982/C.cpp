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


int arr[4][4] = {{1, 2, 3, 4},{2, -1, 4, -3},{3, -4, -1, 2},{4, 3, -2, -1}};

int toint(char c) {
  if (c == '1') return 1;
  if (c == 'i') return 2;
  if (c == 'j') return 3;
  if (c == 'k') return 4;
}

int main() {
  // Declare members
  int num_case;
  cin >> num_case;

  int numc;
  int mult;

  string str;

  bool bi;
  bool bj;
  bool bk;
  bool pos;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> numc;
    cin >> mult;
    cin >> str;

    bi = bj = bk = false;
    pos = true;

    int curr = 1;
    for (int i = 0; i < mult; ++i) {
      for (int j = 0; j < numc; ++j) {
        int sign = 1;
        if (curr < 0) {
          sign = -1;
          curr = -curr;
        }
        curr = arr[curr - 1][toint(str[j]) - 1]*sign;
        if (!bi && curr == 2) {
          bi = true;
          curr = 1;
        } else if (bi && !bj && curr == 3) {
          bj = true;
          curr = 1;
        } else if (bi && bj && !bk && curr == 4) {
          bk = true;
          curr = 1;
        }
      }
    }
    string res;
    if (bk && curr == 1) res = "YES";
    else res = "NO";

    // Print output for case j
    cout << "Case #" << nc << ": " << res << endl;
  }


  return 0;
}
