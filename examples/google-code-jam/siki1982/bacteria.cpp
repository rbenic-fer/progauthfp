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

int tab[101][101];


bool run(uint32_t &xmi, uint32_t &xma, uint32_t &ymi, uint32_t &yma) {
  bool l = false;
  for (uint32_t i = 100; i > 0; i--) {
    for (uint32_t j = 100; j > 0; j--) {
      if (tab[i][j] == 1 && tab[i-1][j] == 0 && tab[i][j - 1] == 0) {
	tab[i][j] = 0;
      } else if (tab[i][j] == 0 && tab[i-1][j] == 1 && tab[i][j - 1] == 1) {
	tab[i][j] = 1;
	if (i > yma) yma = i;
	if (j > xma) xma = j;
      } else {
	tab[i][j] = tab[i][j];
      }
      if (tab[i][j] == 1) { l = true; }
    }
  }
  return l;
}


int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;
  uint32_t R, X1, X2, Y1, Y2;
  uint32_t xma = 0;
  uint32_t xmi = 100;
  uint32_t yma = 0;
  uint32_t ymi = 100;


  for (int j = 1; j <= num_case; j++) {
    // Init members
    for (uint32_t i = 0; i < 100; i++) {
      for (uint32_t k = 0; k < 100; k++) {
	tab[i][k] = 0;
      }
    }

    cin >> R;

    

    for (uint32_t i = 0; i < R; i++) {
      cin >> X1 >> Y1 >> X2 >> Y2;

      if (X1 < xmi) xmi = X1;
      if (X2 > xma) xma = X2;
      if (Y1 < ymi) ymi = Y1;
      if (Y2 > yma) yma = Y2;


      for (uint32_t l = X1; l <= X2; l++) {
	for (uint32_t k = Y1; k <= Y2; k++) {
	  tab[k][l] = 1;
	}
      }
    }

    uint32_t sec = 0;

      for (uint32_t i = 0; i < 6; i++) {
	for (uint32_t k = 0; k < 6; k++) {
	  //cerr << tab[i][k] << " ";
	}
	//cerr << endl;
      }
      //cerr << endl;


    while (run(xmi, xma, ymi, yma)) {
      sec++;
      for (uint32_t i = 0; i < 6; i++) {
	for (uint32_t k = 0; k < 6; k++) {
	  //cerr << tab[i][k] << " ";
	}
	//cerr << endl;
      }
      //cerr << endl;
    }

    // Print output for case j
    cout << "Case #" << j << ": " << sec+1 << endl;
  }


  return 0;
}
