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

	int n;

string tr(int r, int y, int b, char c, char d, char e)
{
	string s = "";


	char prev = -1;

	int arr[] = {r, y, b};
	char chars[] = {c, d, e};

			// cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";


	while(s.size() != n) {


		int mx = -1;
		int mx_ind = -1;

		for(int j = 0; j<3; ++j) {
			if( mx < arr[j] && prev != chars[j] && arr[j]){

				mx = arr[j];
				mx_ind = j;
			}

		}

		if(mx_ind == -1)
			return s;

		prev = chars[mx_ind];
		s += prev;

		arr[mx_ind]--;



		// if(r > 0)
			// s += c;
		// if(y > 0)
			// s += d;
		// if( e > 0)
			// s += e;

	}

	return s;
}


bool check(string s1)
{
	bool not_ok = false;

	not_ok = (s1[0] == s1[s1.length()-1]);
	not_ok = not_ok || (s1.length() != n);

	for (int i=0; i<s1.length()-1; ++i)
		not_ok = not_ok || (s1[i] == s1[i+1]);

	return not_ok;
}

void solve(int t) {


	cin>>n;
	int r, o, y, g, b, v;
	cin>>r>>o>>y>>g>>b>>v;

	string s1 = tr(r, y, b, 'R', 'Y', 'B');

	// bool ok = false;
	bool not_ok = check(s1);
	if(not_ok && s1.length() == n-1)
	{
		// cout<<s1<<"\n";
		
		swap(s1[n-2], s1[n-1]);
		not_ok = check(s1);
		// cout<<s1<<"\n";
	}



	if(not_ok)
		cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<"\n";
	else
		cout<<"Case #"<<t<<": "<<s1<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin>>T;
	int t = 1;
	while(T--)
		solve(t++);

	return 0;

}