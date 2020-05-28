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

	ll n, k;
	cin>>n>>k;
	
	priority_queue<ll> q;
	q.push(n);


	ll dist = 0;
	ll dist2 = 0;

	for(int i=0; i<k; ++i) {

		ll n1 = q.top()/2;
		ll n2 = n1;


		if(q.top() % 2 == 0)
			n1--;

		dist = n1;
		dist2 = n2;

		q.pop();

		q.push(n1);
		q.push(n2);
	}


	cout<<"Case #"<<t<<": "<<dist2<<" "<<dist<<"\n";

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