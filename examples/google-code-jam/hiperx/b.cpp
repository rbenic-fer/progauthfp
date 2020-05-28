#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <inttypes.h>

using namespace std;

#define REP3(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(i,n) REP3(i,0,n)
#define INF 0x3f3f3f3f

int P;
int N;

int M[1<<11];
int price[11][1<<11];

int main() {
  int nt0;

  scanf(" %d", &nt0);
  REP(nt,nt0) {
    scanf(" %d", &P);
    N = 1<<P;

    REP(i,N) scanf(" %d", &M[i]);
    REP(i,P) REP(j,1<<(P-i-1)) scanf(" %d", &price[i][j]);

    int ans = 0;
    REP(i,N) REP(j,P-M[i]) {
      int k = i >> (P-j);
      //printf("(%d %d %d)\n", i,P-j-1,k);
      ans += price[P-j-1][k];
      price[P-j-1][k] = 0;
    }

    printf("Case #%d: ", nt+1);
    printf("%d\n", ans);
  }

  return 0;
}
