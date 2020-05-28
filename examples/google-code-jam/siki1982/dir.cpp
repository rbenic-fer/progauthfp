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

set<string> dirs;

int findp(string dir) {
  if (dirs.find(dir) != dirs.end()) {
    return 0;
  } else {
    dirs.insert(dir);
    size_t pos = dir.rfind("/");
    if (pos == 0) return 1;
    //cerr << dir.substr(0, pos) << endl;
    return 1 + findp(dir.substr(0, pos));
  }
}


int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;
  int N, M;

  for (int j = 1; j <= num_case; j++) {
    // Init members
    cin >> N >> M;
    dirs.clear();

    string dir;
    for (int i = 0; i < N; i++) {
      cin >> dir;
      dirs.insert(dir);
    }

    set<string>::iterator it;
    int mkdir = 0;
    for (int i = 0; i < M; i++) {
      cin >> dir;
      mkdir += findp(dir);
    }

    // Print output for case j
    cout << "Case #" << j << ": " << mkdir << endl;
  }


  return 0;
}
