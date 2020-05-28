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
  double C, F, X, prod, seconds, cookies;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cookies = 0;
    seconds = 0;
    prod = 2;
    cin >> C;
    cin >> F;
    cin >> X;
    
    while (true) {
      double next = C/prod;
      double left = (X - cookies)/prod;
      if (left <= next) {
        seconds += left;
        break;
      } else {
        seconds += next;
        cookies += next*prod;
        left = (X - cookies)/prod;
        double build = (X - (cookies - C))/(prod + F);
        if (left <= build) {
          seconds += left;
          break;
        } else {
          cookies -= C;
          prod += F;
        }
      }
    }

    // Print output for case j
    std::cout << std::fixed;
    cout << "Case #" << nc << ": " << setprecision(7) << seconds << endl;
  }


  return 0;
}
