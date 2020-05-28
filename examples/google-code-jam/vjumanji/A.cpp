#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define  FOR(i,a,b)    for(int i=(a); i<(b); ++i)
#define  REP(i,a)      FOR(i,0,a)
#define FORN(i,a)      FOR(i,1,(a)+1)
#define FORD(i,a,b)    for(int i(a-1);i>=b;--i)

typedef long long int iLong;
typedef vector<int> iVec;
typedef pair<int,int> iiPair;

int rint() { int x; scanf("%d", &x); return x;}
long long int rLL() { long long int x; scanf("%lld", &x); return x;}

vector<iiPair> p;

int main() {
  int T = rint();
  FORN(t, T)
  {
    p.clear();
    int n = rint();
    REP(i, n) {
      int c = rint();
      p.push_back(iiPair(c, i));
    }
    printf("Case #%d: ", t);

    while (1) {
      sort(p.begin(), p.end(), greater<iiPair>());
      if (p[0].first == 0) break;
      if (p[0].first == 1 && p[1].first == 1 && (n > 2 && p[2].first == 1 && (n == 3 || p[3].first == 0))) {
        char a = 'A' + p[0].second;
        p[0].first--;
        printf("%c ", a);
      } else if (p[0].first == p[1].first) {
        char a = 'A' + p[0].second;
        char b = 'A' + p[1].second;
        p[0].first--;
        p[1].first--;
        printf("%c%c ", a, b);
      } else if (p[0].first > 1) {
        p[0].first-=2;
        char a = 'A' + p[0].second;
        printf("%c%c ", a, a);
      } else {
        p[0].first--;
        char a = 'A' + p[0].second;
        printf("%c ", a);
      }
    }
    printf("\n");
  }
  return 0;
}
