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
	int t, n;
	unsigned long int d, k, s;
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> d >> n;
		double max = 0;
		for (int j =0 ; j<n; j++){
			cin >> k >> s;
			double aux = (d-k)/((double)(0.0+s));
			if (max < aux) max = aux;
		}
		std::cout << std::fixed;
		std::cout << std::setprecision(6);
		cout << "Case #" << i+1  << ": " << (double)d/max << endl;
	}
	return 0;
}
