#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int64;

int64 a,b;
int64 fplist[64];
int sz;

char n[16];
int len;
bool pal(int64 k) {
  sprintf(n, "%lld%n", k, &len);
  for(int i=0, j=len-1; i<j; ++i, --j)
    if(n[i] != n[j]) return false;
  return true;
}

void pre() {
  sz = 0;
  for(int64 i=1LL; i<=10000000LL; ++i)
    if(pal(i) && pal(i*i))
      fplist[sz++] = i*i;
}

int main() {
  pre();
  int ntests;
  scanf(" %d", &ntests);
  for(int nt=1; nt<=ntests; ++nt) {
    scanf(" %lld %lld", &a, &b);
    printf("Case #%d: ", nt);
    int i = lower_bound(fplist, fplist+sz, a) - fplist;
    int j = upper_bound(fplist, fplist+sz, b) - fplist;
    printf("%d\n", j - i);
  }
  return 0;
}
