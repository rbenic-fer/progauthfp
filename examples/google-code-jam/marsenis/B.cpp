#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

char sol[MAX];

void solve(int testcase) {
   int i;
   int n, r, o, y, g, b, v;
   scanf("%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);
   if (g || o || v) return;
   if (!r && b == y)
      for (i = 0; i < n; i+= 2) { sol[i] = 'B'; sol[i+1] = 'Y'; }
   else if (!b && r == y)
      for (i = 0; i < n; i+= 2) { sol[i] = 'R'; sol[i+1] = 'Y'; }
   else if (!y && r == b)
      for (i = 0; i < n; i+= 2) { sol[i] = 'R'; sol[i+1] = 'B'; }
   else if (!y || !r || !b) i = 0;
   else 
      for (i = 0; i < n; ) {
         if (r && y && b) {
            if( (r == b && b == 1) ||
               (b == 1 && (b+y+r-3) % 2 == 1) ) {
               sol[i] = 'R';
               sol[i+1] = 'Y';
               sol[i+2] = 'B';
               r--; y--; b--;
               i += 3;
            } else {
               sol[i] = 'R';
               sol[i+1] = 'B';
               sol[i+2] = 'Y';
               r--; y--; b--;
               i += 3;
            }
         } else if (!r && y && b) {
            sol[i] = 'B';
            sol[i+1] = 'Y';
            b--; y--;
            i += 2;
         } else if (r && !y && b) {
            if ((r+b) % 2 == 0) {
               sol[i] = 'R';
               sol[i+1] = 'B';
               r--; b--;
               i+=2;
            } else {
               sol[i] = 'B';
               sol[i+1] = 'R';
               r--; b--;
               i+=2;
            }
         } else if (r && y && !b) {
            if ((r+y) % 2 == 0) {
               sol[i] = 'R';
               sol[i+1] = 'Y';
               r--; y--;
               i+=2;
            } else {
               sol[i] = 'Y';
               sol[i+1] = 'R';
               r--; y--;
               i+=2;
            }
         } else if (!r && !y && b) {
            if (b == 1) sol[i++] = 'B';
            else break;
         } else if (!r && y && !b) {
            if (y == 1) sol[i++] = 'Y';
            else break;
         } else if (r && !y && !b) {
            if (r == 1) sol[i++] = 'R';
            else break;
         }
      }
   sol[n] = '\0';
   if (i < n) printf("Case #%d: IMPOSSIBLE\n", testcase);
   else printf("Case #%d: %s\n", testcase, sol);
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) solve(t);
	return 0;
}
