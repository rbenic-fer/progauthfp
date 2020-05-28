/*
	Michał Gańczorz
	code jam 2015
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <queue>
#include <list>
#include <sstream>
 // #include <unistd.h>
// #include <unordered_map>

#define ll long long

using namespace std;
// const ll prime = 1000000007;

void solve(int c)
{
	int n;
	string str;
	cin>>n>>str;
	int res = 0;

	for(int i=0; i<1010; ++i)
	{
		res = i;

		bool ok = true;
		int sm = i;
		for(int k=0; k<=n; ++k)
			if(sm >= k || str[k] == '0')
				sm += (str[k]-'0');
			else
				ok = false;

		if(ok)
			break;
	}

	cout<<"Case #"<<c<<": "<<res<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
		solve(i);

	return 0;
}