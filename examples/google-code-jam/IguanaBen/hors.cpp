#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <iomanip>

#define ll long long

using namespace std;


void solve(int t) {

	double result = -9000000003.0;

	double d;
	cin>>d;
	int n;
	cin>>n;


	for (int i=0; i<n ;++i ){
		double a, b;
		cin>>a>>b;
		double t = (d-a)/b;
		if(result < 0 )
			result = b + a/t;
		else
 			result = min(result, b + a/t );
	}

	 cout << fixed << setprecision(6);
	cout<<"Case #"<<t<<": "<<result<<"\n";

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