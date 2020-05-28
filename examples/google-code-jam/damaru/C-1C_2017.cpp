#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> //max...
#include <utility> //pair
#include <complex>
#include <climits> //int, ll...
#include <limits> //double...
#include <cmath> //abs, atan...

#include <cstring> //memset
#include <string>

using namespace std;

typedef long long ll;

typedef pair<int,int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


int main (){
	int t, n, k;
	long double ss[50];
	long double extra, aux, aux2, mean;
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> n >> k;
		cin >> extra;
		mean = 0;
		for (int j = 0; j < n ; j++){
			cin >> ss[j];
			mean += ss[j];
		}
		mean += extra;
		int q = 0;
		sort(ss, ss+n);
		for (int j = n-1; j >=0 ; j--){
			if (mean/(n-q) < ss[j]){
				mean -= ss[j];
				q++;
			}
			else
				break;
		}
		mean /= (n-q);
		long double sol = 1;
		for (int j = 0; j < n; j++){
			if (j < n-q)
				sol*= mean;
			else{
				sol *= ss[j];
			}
		}
		cout << "Case #" << i+1  << ": " << setprecision(10) << fixed << sol << endl;
	}
	return 0;
}
