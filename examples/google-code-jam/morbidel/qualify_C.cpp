/*
 * Google Code Jam 2017
 * Qualification Round - Problem C - Bathroom Stalls
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
#include <utility>

#define MIN(a, b)           ((a) > (b) ? (b) : (a))
#define MAX(a, b)           ((a) > (b) ? (a) : (b))
#define ABS(x)              ((x) > 0 ? (x) : -(x))
#define SGN(x)              (((x) == 0) ? 0 : ((x) > 0 ? 1 : -1))
#define SZ(a)               ((a).size())
#define FORN(_i, _n)        for (int (_i) = 0; (_i) < (_n); ++(_i))
#define FOR_(_i, _a, _b)    for (int (_i) = (_a); (_i) <= (_b); ++(_i))
#define ALL(stl)            (stl).begin(), (stl).end()
#define INF                 1000000000

typedef unsigned long long  LLU;

using namespace std;


#define OFFICIAL 1

#if OFFICIAL
  #define INPUT_FILE    "C-large.in"
  #define OUTPUT_FILE   "C-large.out"
#else
  #define INPUT_FILE    "input.txt"
  #define OUTPUT_FILE   "output.txt"
#endif

LLU N, K;
vector<int> V;
map<LLU, LLU, greater<LLU> > Current, Next;

void PreGen()
{
  // stuff which executes only once, before reading the input
}

void Simulate(int& maxLR, int& minLR)
{
  int the_place = -1;
  int max_minLR = 0 , max_maxLR = 0;

  for (int i = 0; i < V.size(); ++i)
    if (V[i] == 0)
    {
      int l = 0, r = 0;

      for (int j = i - 1; j >= 0; --j)
        if (V[j] == 1) break;
        else
        {
          ++l;
        }
      for (int j = i + 1; j < V.size(); ++j)
        if (V[j] == 1) break;
        else
        {
          ++r;
        }

      if (the_place == -1)
      {
        the_place = i;
        max_minLR = MIN(l, r);
        max_maxLR = MAX(l, r);
      }
      else if (MIN(l, r) > max_minLR)
      {
        max_minLR = MIN(l, r);
        max_maxLR = MAX(l, r);
        the_place = i;
      }
      else if (MIN(l, r) == max_minLR && MAX(l, r) > max_maxLR)
      {
        the_place = i;
        max_maxLR = MAX(l, r);
      }
    }

  if (the_place == -1)
  {
    printf("no place found !!!\n");
  }
  else
  {
    V[the_place] = 1;
    maxLR = max_maxLR;
    minLR = max_minLR;
  }

  printf("%d %d\n", maxLR, minLR);
  
  for (int i = 0; i < V.size(); ++i)
    printf("%d", V[i]);
  printf("\n");
}

int Solve()
{
  // stuff which is executed for each input
  // expects the output to be printed out
  scanf("%llu %llu", &N, &K);
  
  LLU minLR, maxLR;
  /*V.clear();
  V.resize(N + 2, 0);
  V[0] = V[N + 1] = 1;

  
  for (int i = 0; i < K; ++i)
  {
    Simulate(maxLR, minLR);
  }*/

  Next.clear();
  Current.clear();
  Current.insert(make_pair(N, 1));

  LLU currK = 0;
  while (currK < K)
  {
    for (map<LLU, LLU, greater<LLU> >::const_iterator it = Current.begin(); it != Current.end(); ++it)
    {
      LLU hole = it->first;
      LLU count = it->second;
      
      // before splitting current hole, we put some guys to pee there, for which the answer (max, min) is the same
      currK += count;
      // hole is it->first size, so max is the bigger half, min is the smaller half
      maxLR = MAX(hole / 2, hole - hole / 2 - 1);
      minLR = MIN(hole / 2, hole - hole / 2 - 1);

      // we reached at least K iterations, exit
      if (currK >= K) break;

      LLU group = hole / 2;
      if (group > 0)
        Next[group] += count;

      group = hole - group - 1; // 1 disappears as the guy wants to pee
      if (group > 0)
        Next[group] += count;

      // copy 1-holes as they are
      if (hole == 1)
      {
        Next[hole] += count;
      }
    }

    Current.clear();
    Current = Next;
    Next.clear();

    // when we have only 1-holes, break -> we can fill them in any order, and the result for each of these guys is (0, 0)
    if (Current.size() == 1 && Current.begin()->first == 1)
    {
      break;
    }
  }

  if (currK < K)
  {
    // only 1-holes, answer is (0, 0)
    maxLR = minLR = 0;
  }
  printf("%lld %lld", maxLR, minLR);

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