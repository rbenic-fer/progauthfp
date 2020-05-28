/*
 * Google Code Jam 2014
 * Qualification round - Problem A - Magic Trick
 */

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#include <functional>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MIN(a, b)           ((a) > (b) ? (b) : (a))
#define MAX(a, b)           ((a) > (b) ? (a) : (b))
#define ABS(x)              ((x) > 0 ? (x) : -(x))
#define SGN(x)              (((x) == 0) ? 0 : ((x) > 0 ? 1 : -1))
#define SZ(a)               ((a).size())
#define FORN(_i, _n)        for (int (_i) = 0; (_i) < (_n); ++(_i))
#define FOR_(_i, _a, _b)    for (int (_i) = (_a); (_i) <= (_b); ++(_i))
#define ALL(stl)            (stl).begin(), (stl).end()
#define INF                 1000000000

using namespace std;


#define OFFICIAL 1

#if OFFICIAL
  #define INPUT_FILE    "A-small-attempt0.in"
  #define OUTPUT_FILE   "A-small-attempt0.out"
#else
  #define INPUT_FILE    "input.txt"
  #define OUTPUT_FILE   "output.txt"
#endif


void PreGen()
{
  // stuff which executes only once, before reading the input
}

int Solve()
{
  int row;
  vector<int> flag(17, 0);

  scanf("%d", &row);
  for (int i = 1; i <= 4; ++i)
    for (int j = 0; j < 4; ++j)
    {
      int x;
      scanf("%d", &x);

      if (i == row)
      {
        ++flag[x];
      }
    };

  scanf("%d", &row);
  for (int i = 1; i <= 4; ++i)
    for (int j = 0; j < 4; ++j)
    {
      int x;
      scanf("%d", &x);

      if (i == row)
      {
        ++flag[x];
      }
    };

  int countDouble = 0, one;
  for (int i = 1; i <= 16; ++i)
    if (flag[i] == 2)
    {
      ++countDouble;
      one = i;
    }

  if (countDouble == 0)
  {
    printf("Volunteer cheated!");
  }
  else if (countDouble == 1)
  {
    printf("%d", one);
  }
  else
  {
    printf("Bad magician!");
  }

  return 0;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);

#if OFFICIAL
  freopen(OUTPUT_FILE, "wt", stdout);
#endif

  PreGen();

  int T, nt;

  scanf("%d\n", &T);

  for (nt = 1; nt <= T; ++nt)
  {
    printf("Case #%d: ", nt);

    if (Solve())
    {
    }

    printf("\n");
  }

  return 0;
}