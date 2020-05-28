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

#define MAXN 1000
#define MAXL 2

LL store[MAXN + 1][MAXL + 1];

LL count(LL n, LL l, LL t, vector<LL> &d) {
  //cerr << n << " " <<  l << endl;
  if (n == 0) {
    store[n][l] = 0;
    //cerr << "1 " << store[n][l] << endl;
    return 0;
  }
  if (store[n][l] != 0) return store[n][l];
  if (l == 0) {
    LL res = count(n - 1, l, t, d) + d[n - 1]*2;
    store[n][l] = res;
    //cerr << "2 " << store[n][l] << endl;
    return res;
  }

  LL res1 = count(n - 1, l, t, d) + d[n - 1]*2;
  LL res2 = count(n - 1, l - 1, t , d);
  if (t <= res2) {
    res2 += d[n-1];
  } else if (t <= res2 + d[n - 1]*2) {
    res2 = res2 + t - res2 + d[n - 1] - (t - res2)*0.5;
  } else {
    res2 = res2 + d[n - 1]*2;
  }
  //LL res2 = max(count(n - 1, l - 1, t , d), t) + d[n-1];
//   if (t <= res2) {
//     res2 = res2 + d[n - 1];
//   } else {
//     res2 = res2 + d[n - 1]*2;
//   }
  
  LL res = min(res1, res2);
  store[n][l] = res;
  //cerr << res1 << " " << res2 << endl;
  //cerr << "3 " << n << " " << l << " " << store[n][l] << endl;
  return res;
}


int main() {
  // Declare members
  LL num_case;
  cin >> num_case;



  for (int j = 1; j <= num_case; j++) {
    // Init members
    LL L, t, N, C;
    cin >> L;
    cin >> t;
    cin >> N;
    cin >> C;
    vector<LL> c(C);
    vector<LL> d(N + 1);

    for (LL i = 0; i <= MAXN; ++i) {
      for (LL k = 0; k <= MAXL; ++k) {
	store[i][k] = 0;
      }
    }

    for (LL i = 0; i < C; ++i) {
      cin >> c[i];
      ////cerr << c[i] << endl;
    }

    
    for (LL i = 0; i*C <= N - 1; ++i) {
      for (LL k = 0; k < C && i*C + k <= N - 1; ++k) {
	d[i*C + k] = c[k];
	//cerr << i*C + k << " " << c[k] << endl;
      }
    }

    // Print output for case j
    cout << "Case #" << j << ": " << count(N, L, t, d) << endl;
  }


  return 0;
}
