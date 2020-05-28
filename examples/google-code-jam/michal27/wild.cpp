#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
  int t1;
  scanf("%d ",&t1);
  for(int i1=1; i1<=t1; i1++)
  {
    int n;
    scanf("%d ",&n);
    vector<pair<int,int> > A;
    for(int i=0; i<n; i++)
    {
      int x,y;
      scanf("%d %d ",&x,&y);
      A.push_back(make_pair(x,y));
    }
    int d;
    scanf("%d ",&d);
    A.push_back(make_pair(d,0));
    vector<int> P; 
    for(int i=0; i<A.size(); i++) P.push_back(-1);
    P[0]=A[0].first;
    for(int i=0; i<A.size(); i++)
      for(int j=i+1; j<A.size(); j++)
      {
	if(A[j].first-A[i].first<=P[i]) P[j]=max(P[j],min(A[j].first-A[i].first,A[j].second));
      }
    //for(int i=0; i<P.size(); i++) printf("%d ",P[i]); printf("\n");
    if(P[P.size()-1]==-1) printf("Case #%d: NO\n",i1);
    else printf("Case #%d: YES\n",i1);
  }
return 0;
}