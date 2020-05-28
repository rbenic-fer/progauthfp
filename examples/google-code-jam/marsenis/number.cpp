#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main() {
  //FILE *fin=fopen("number.in", "r"), *fout=fopen("number.out", "w");
  int t, x, i, n;
  char num[30];
  vector<int> v;
  
  scanf("%d\n", &t);
  for (x=1; x<=t; x++) {
    scanf("%s", num);
    n = strlen(num);
    for (i=0; i<n; i++) v.push_back(num[i]-'0');
    
    for (i=1; i<n; i++) if (num[i]!='0' && num[i]>num[i-1]) break;
    if (i!=n) {
      next_permutation(v.begin(), v.end());
    } else {
      v.push_back(0);
      sort(v.begin(), v.end());
      for (i=0; v[i]==0; i++) ;
      swap(v[0], v[i]);
    }
    printf("Case #%d: ", x);
    for (i=0; i<v.size(); i++) printf("%d", v[i]); printf("\n");
    v.clear();
  }
  
  //fclose(fin); fclose(fout);
  return 0;
}
