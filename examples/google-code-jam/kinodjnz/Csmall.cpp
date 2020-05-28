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

const double INF = 1e+100;

double solve0(int N, int *E, int *S, int *D) {
  double dp[110][110] = {};
  int e[110][110] = {};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0.0;
  e[0][0] = E[0];
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (D[i-1] <= e[i-1][j]) {
        e[i][j] = e[i-1][j] - D[i-1];
        dp[i][j] = min(dp[i][j], dp[i-1][j] + (double)D[i-1] / S[j]);
      }
    }
    double mindp = INF;
    for (int j = 0; j < i; j++)
      mindp = min(mindp, dp[i][j]);
    dp[i][i] = mindp;
    e[i][i] = E[i];
  }
  return dp[N-1][N-1];
}

double solve(int N, int *E, int *S, int (*D)[100], int , int *, int *) {
  int d[110] = {};
  for (int i = 0; i < N-1; i++) {
    d[i] = D[i][i+1];
  }
  return solve0(N, E, S, d);
}

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, Q;
    cin >> N >> Q;
    int E[110] = {};
    int S[110] = {};
    for (int j = 0; j < N; j++) {
      cin >> E[j] >> S[j];
    }
    int D[100][100] = {};
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        cin >> D[j][k];
      }
    }
    int U[110] = {};
    int V[110] = {};
    for (int j = 0; j < Q; j++) {
      cin >> U[j] >> V[j];
    }
    double ans = solve(N, E, S, D, Q, U, V);
    printf("Case #%d: %.12f\n", i+1, ans);
  }
}
