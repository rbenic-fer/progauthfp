#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> zmen(int a)
{
  vector<int> A;
  while(a>0) {A.push_back(a%10); a/=10;}
  return A;
}

int spat(vector<int> A)
{
  int vys=0;
  for(int i=A.size()-1; i>=0; i--) {vys*=10; vys+=A[i];}
  return vys;
}

set<pair<int,int> > S;

int main()
{
  int t1;
  scanf("%d ",&t1);
  for(int i1=1; i1<=t1; i1++)
  {
    int a,b;
    S.clear();
    int vys=0;
    scanf("%d %d ",&a,&b);
    for(int i=a; i<=b; i++)
    {
      vector<int> A=zmen(i);
      for(int j=0; j<A.size()-1; j++)
      {
	vector<int> B;
	for(int k=j+1; k<A.size(); k++) B.push_back(A[k]);
	for(int k=0; k<=j; k++) B.push_back(A[k]);
	int co=spat(B);
	if(a<=co && b>=co && i!=co) {vys++; S.insert(make_pair(i,co)); /*printf("%d %d\n",i,co);*/}
      }
    }
   printf("Case #%d: %d\n",i1,S.size()/2);
  }
return 0;
}