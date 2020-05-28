#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

#define ll long long

using namespace std;

bool tidy(ll n){
	string x = std::to_string(n);

	// bool td = true;
	for(int i=1; i<x.length(); ++i){
		if (x[i-1] > x[i])
			return false;
	}

	return true;
}


void solve(int t) {

	ll n;
	cin>>n;

	while(n > 0) {
		if(tidy(n)) {
			cout<<"Case #"<<t<<": "<<n<<"\n";
			return;
		}

		n--;
	}

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