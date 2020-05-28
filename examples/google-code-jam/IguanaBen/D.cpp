#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

#define type long long
#define pp pair<float, int> 

using namespace std;

bool cmp(pp fst, pp snd)
{
	return fst.first < snd.first;
}

// int no_cheat(vector<int> v1, vector<int> v2)
// {

// 	for(int i=0; i<v1.size(); i++)
// 	{
// 		if(v1[i] != 0)
// 		{

// 			int j=0;
// 			while(v1[i] > v2[j] && j<v2.size())
// 				j++;

// 			int t1 = v1[i];
// 			int t2 = v2[j];

// 			v1[i] = 0;
// 			if(j == v2.size())
// 				v2[0] = 0;
// 			else
// 			{
// 				return no_cheat(v1,v2);
// 			}

// 			v1[i] = t1;
// 			v2[j] = 

// 		}
// 	}

// 	return 0;
// }

pp tab[10808];
int t1[10440];
int t2[10440];


int main()
{
  set <int> s1;
	  set<int> s2;

  cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  int t;
  cin>>t;
  int cas = 1;
  while(t--)
  {
	  int n;
	  cin>>n;
	  s1.clear();
	  s2.clear();

	  for(int i=0; i<n; i++)
	  {
	  	cin>>tab[i].first;
	  	tab[i].second = 0;
	  }

	  for(int i=n; i<n+n; i++)
	  {
	  	cin>>tab[i].first;
	  	tab[i].second = 1;
	  }

	  sort(tab, tab+(2*n), cmp);

	 
	  int i1 =0;
	  int i2 = 0;
	  for(int i=0; i<2*n; i++)
	  	if(tab[i].second)
	  		t2[i2++] = i+1;
	  	else
	  		t1[i1++] = i+1;

	

	  for(int i=0; i<n; i++) s1.insert(t1[i]);
	  for(int i=0; i<n; i++) s2.insert(t2[i]);

	  // sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
	  set<int>::iterator itmn, itu;
	  int result = 0;
	  for(int i=0; i<n; i++)
	  {
	  	itmn = s1.lower_bound(0);
	  	itu = s2.upper_bound(*itmn);
	  	if(itu == s2.end())
	  	{
	  		itu = s2.lower_bound(0);
	  		result ++;
	  	} 
	  	
	  	s1.erase(itmn);
	  	s2.erase(itu);
	  }

	  int ch_r = 0;

	  for(int i=0; i<n; i++)
	  {
	  	int rs = 0;
	  	for(int j=0; j<n-i; j++)
	  		if(t1[j+i] > t2[j])
	  			rs++;
	  	ch_r = max(ch_r, rs);
	  }

	  cout<<"Case #"<<cas<<": ";
	  cout<<ch_r<<" "<<result<<"\n";
	  cas++;
	}

  return 0;
 
}