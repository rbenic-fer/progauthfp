/*
 * Google Code Jam 2013
 * Qualification Round - Problem A - Tic-Tac-Toe-Tomek
 */

#include <string>
#include <vector>
#include <list>
#include <map>
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

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

using namespace std;


#define OFFICIAL 1

#if OFFICIAL
  #define INPUT_FILE    "A-large.in"
  #define OUTPUT_FILE   "A-large.out"
#else
  #define INPUT_FILE    "input.txt"
#endif

#define MIN(a, b)       ((a) > (b) ? (b) : (a))
#define MAX(a, b)       ((a) > (b) ? (a) : (b))
#define ABS(a)          ((a) > 0 ? (a) : -(a))

char T[4][5];

bool cell(int l, int c, char ch)
{
  return T[l][c] == ch || T[l][c] == 'T';
}

bool checkWin(char ch)
{
  for (int i = 0; i < 4; ++i)
  {
    // whole line
    if (cell(i, 0, ch) && cell(i, 1, ch) && cell(i, 2, ch) && cell(i, 3, ch))
    {
      return true;
    }

    // whole column
    if (cell(0, i, ch) && cell(1, i, ch) && cell(2, i, ch) && cell(3, i, ch))
    {
      return true;
    }
  }

  // first diagonal
  if (cell(0, 0, ch) && cell(1, 1, ch) && cell(2, 2, ch) && cell(3, 3, ch))
  {
    return true;
  }

  if (cell(0, 3, ch) && cell(1, 2, ch) && cell(2, 1, ch) && cell(3, 0, ch))
  {
    return true;
  }

  return false;
}

void Solve()
{
  memset(T, 0, sizeof(T));

  for (int i = 0; i < 4; ++i)
  {
    scanf("%s", &T[i]);
  }
  scanf("\n");

  if (checkWin('X'))
  {
    printf("X won");
    return;
  }
  else if (checkWin('O'))
  {
    printf("O won");
    return;
  }

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (T[i][j] == '.')
      {
        printf("Game has not completed");
        return;
      }

  printf("Draw");

  return;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);

#if OFFICIAL
  freopen(OUTPUT_FILE, "wt", stdout);
#endif

  int T, nt;

  scanf("%d\n", &T);

  for (nt = 1; nt <= T; ++nt)
  {
    printf("Case #%d: ", nt);

    Solve();

    printf("\n");
  }

  return 0;
}