#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define INPUT_FILE    "C-small-attempt0.in"
#define OUTPUT_FILE   "C-small-attempt0.out"


long long solve(int a, int b)
{
  long long res = 0;
  int x, y;

  for (x = a; x <= b; ++x)
  {
    // go through all rotations and count only pairs (x, y) with y > x.
    char sz[16];
    sprintf(sz, "%d", x);
    string s = sz;

    for (int i = 0; i < s.size(); ++i)
    {
      rotate(s.begin(), s.end() - 1, s.end());
      y = atol(s.c_str());

      if (y > x && y >= a && y <= b)
      {
        //printf("%d %d\n", x, y);
        ++res;
      }
    }
  }
  return res;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);
  freopen(OUTPUT_FILE, "wt", stdout);

  int t, a, b;

  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    scanf("%d %d", &a, &b);
    printf("Case #%d: ", i);

    printf("%lld\n", solve(a, b));
  }

  return 0;
}