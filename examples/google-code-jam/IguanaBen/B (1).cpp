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
const ll prime = 1000000007;

const ll big_inf =  10000000000000LL;

ll dp[1033];

void fillDP(int k, int lim)
{
	for(int i=0; i<=k; ++i)
		dp[i] = 0;

	for(int i=k+1; i<=lim; ++i)
	{
		dp[i] = big_inf;
		for(int j=1; j<=i/2; ++j)
			dp[i] = min( dp[i-j] + dp[j] + 1, dp[i]);
	}
}


ll sol2(vector<int> vin)
{
	int mxv = 0;
	for(int i=0; i<vin.size(); ++i)
		mxv = max(vin[i], mxv);

	ll mn = big_inf;
	for(int i=1; i<=mxv; ++i)
	{
		fillDP(i, mxv);

		// cout<<i<<" "<<dp[9]<<"\n";
		ll res = 0;
		for(int j=0; j<vin.size(); ++j)
			res += dp[vin[j]];

		res += i;
		mn = min(res, mn);
	}
	return mn;
}

void solve(int c)
{
	int n;
	cin>>n;
	vector<int> vin;
	for(int i=0; i<n; ++i)
	{
		int t;
		cin>>t;
		vin.push_back(t);
	}
	cout<<"Case #"<<c<<": "<<sol2(vin)<<"\n";
}

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(NULL);

	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
		solve(i);

	return 0;
}