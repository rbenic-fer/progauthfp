#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

#define ll long long

using namespace std;


void flip(string &s, int i, int k) {

	for( int j=i; j<k+i; j++) {

		if(s[j] == '-')
			s[j] = '+';
		else
			s[j] = '-';

	}

}

void solve(int t) {

	string s;
	int k;
	cin>>s>>k;

	int flips = 0;

	for(int i=0; i<s.length() - k + 1; ++i) {
		if(s[i] == '-') 
		{
			flip(s, i, k);
			// cout<<s<<"\n";
			// return;
			flips++;
		}
	}

	// return;

	bool imp = false;
	for(int i=0; i<s.length(); ++i) {
		if (s[i] == '-')
			imp = true;
	}


	if(imp) {
		cout<<"Case #"<<t<<": IMPOSSIBLE"<<"\n";
	} else {
		cout<<"Case #"<<t<<": "<<flips<<"\n";

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