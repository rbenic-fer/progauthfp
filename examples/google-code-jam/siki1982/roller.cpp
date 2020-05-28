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

struct S {
  uint32_t r;
  uint32_t p;
  S(uint32_t r_, uint32_t p_) {
    r = r_;
    p = p_;
  }
};

int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;

  uint32_t R, k, N, g;
  

  for (int j = 1; j <= num_case; j++) {
    // Init members
    cin >> R >> k >> N;
    vector<uint32_t> groups(N);
    vector<S*> start_groups;
    start_groups.resize(N, NULL);
    for (uint32_t i = 0; i < N; i++) {
      cin >> groups[i];
    }
    uint32_t cur_pos = 0;
    uint32_t num_group;
    uint32_t cur_num = 0;
    uint32_t eur = 0;
    bool rep = false;
    for (uint32_t i = 1; i <= R; i++) {
      cur_num = 0;
      num_group = 0;
      if (!rep) {
	if (start_groups[cur_pos] == NULL) {
	  start_groups[cur_pos] = new S(i, eur);
	} else {
	  uint32_t rrange = i - (*start_groups[cur_pos]).r;
	  uint32_t prange = eur - (*start_groups[cur_pos]).p;
	  uint32_t mod = (R - i + 1)%rrange;
	  uint32_t num_rep = (R - i + 1 - mod)/rrange;
	  //cout << i << " " << rrange << " "  << prange << " " << num_rep << " " << eur << endl;
	  eur += num_rep*prange;
	  i+=num_rep*rrange - 1;
	  rep = true;
	  //cout << i << " " << eur << " " << endl;
	  if (i == R) break;
	  i++;
	}
      }
      while (cur_num + groups[cur_pos] <= k && num_group < N) {
	cur_num+=groups[cur_pos];
	cur_pos = (cur_pos + 1)%N;
	num_group++;
      }
      eur += cur_num;
    }

    // Print output for case j
    cout << "Case #" << j << ": " << eur << endl;
  }


  return 0;
}
