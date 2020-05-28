#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

#define ll long long

using namespace std;



void solve(int t) {

	ll n;
	cin>>n;
	set<ll> digits_seen;

	if(n == 0) {
		cout<<"Case #"<<t<<": "<<"INSOMNIA"<<"\n";
		return;
	}


	ll mul = 1;

	do{
		ll np = n*mul;
		// cout<<np<<" "<<t<<"\n";
		while(np > 0){
			digits_seen.insert(np % 10);
			np /= 10;
		}

		mul++;
	}while(digits_seen.size() != 10);

	cout<<"Case #"<<t<<": "<<n*(mul-1)<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// for(int i=0; i<=1000000; ++i){
		// solve(i, i);
	// }

	// return 0;

	int T;
	cin>>T;
	int t = 1;
	while(T--)
		solve(t++);

	return 0;

}