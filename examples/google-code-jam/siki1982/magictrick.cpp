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
  int rows1[4];
  int rows2[4];
  int row1, row2, trash;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> row1;
    for (int i = 1; i <= 4; ++i) {
      if (i == row1) {
        for (int j = 0; j < 4; ++j) {
          cin >> rows1[j];
        }
      } else {
        for (int j = 0; j < 4; ++j) {
          cin >> trash;
        }
      }
    }
    cin >> row2;
    for (int i = 1; i <= 4; ++i) {
      if (i == row2) {
        for (int j = 0; j < 4; ++j) {
          cin >> rows2[j];
        }
      } else {
        for (int j = 0; j < 4; ++j) {
          cin >> trash;
        }
      }
    }
    
    std::sort(rows1, rows1 + 4);
    std::sort(rows2, rows2 + 4);
    std::vector<int> res(4);
    
    vector<int>::iterator it = std::set_intersection(rows1, rows1 + 4,
                                                     rows2, rows2 + 4,
                                                     res.begin());

    res.resize(it - res.begin());
    
    // Print output for case j
    if (res.size() == 0) {
      cout << "Case #" << nc << ": " << "Volunteer cheated!" << endl;
    } else if (res.size() > 1) {
      cout << "Case #" << nc << ": " << "Bad magician!" << endl;
    } else {
      cout << "Case #" << nc << ": " << res[0] << endl;
    }
  }


  return 0;
}
