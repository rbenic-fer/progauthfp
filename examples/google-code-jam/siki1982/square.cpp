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





int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;



  for (int j = 1; j <= num_case; j++) {
    // Init members
    uint32_t r, c;
    
    cin >> r;
    cin >> c;

    char pic[r][c];
    char pic2[r][c];
    for (uint32_t i = 0; i < r; ++i) {
      for (uint32_t k = 0; k < c; ++k) {
	cin >> pic[i][k];
	pic2[i][k] = '.';
      }
    }


    bool done = true;
    for (uint32_t i = 0; i < r && done; ++i) {
      for (uint32_t k = 0; k < c && done; ++k) {
	if (pic2[i][k] != '.') continue;
	if (pic[i][k] == '#') {
	  if (i == r - 1 || k == c - 1) {
	    //cerr << i << " " << k << endl;
	    done = false;
	    continue;
	  }
	  for (int l = i ; l <= i + 1; l++) {
	    for (int n = k ; n <= k + 1; n++) {
	      if (pic[l][n] != '#') done = false;
	    }
	  }
	  if (done) {
	    pic2[i][k] = '/';
	    pic2[i + 1][k] = '\\';
	    pic2[i][k + 1] = '\\';
	    pic2[i + 1][k + 1] = '/';
	  }
	}
      }
    }



    // Print output for case j
    if (!done) {
      cout << "Case #" << j << ":" << endl;
      cout << "Impossible" << endl;
    } else {
      cout << "Case #" << j << ":" << endl;
      for (uint32_t i = 0; i < r; ++i) {
	for (uint32_t k = 0; k < c; ++k) {
	  cout << pic2[i][k];
	}
	cout << endl;
      }
    }
  }


  return 0;
}
