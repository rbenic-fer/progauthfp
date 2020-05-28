#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

double solve(int D, int N, int *K, int *S) {
  double max_t = -1.0;
  for (int i = 0; i < N; i++) {
    double t = ((double)D-K[i])/S[i];
    max_t = max(max_t, t);
  }
  return D / max_t;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int D, N;
    cin >> D >> N;
    int K[1010] = {};
    int S[1010] = {};
    for (int j = 0; j < N; j++) {
      cin >> K[j] >> S[j];
    }
    double ans;
    ans = solve(D, N, K, S);
    printf("Case #%d: %.12f\n", i+1, ans);
  }
}
