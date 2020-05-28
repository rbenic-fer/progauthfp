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
	int t, n, r, p, s, rr, pp, ss, j;

	cin >> t;
	char vs[13][5000];
	for (int i =0 ; i<t; i++){
		cin >> n >> r >> p >> s;
		cout << "Case #" << i+1  << ": ";
		for (j = 0; j< n; j++){
			pp = (r + p -s)/2;
			rr = (r+s -p)/2;
			ss = (p+s-r)/2;
			if (rr >= 0 && ss >= 0 && pp >= 0){
				r =rr;
				p = pp;
				s = ss;
			}
			else break;
		}
		if (j!=n){
			cout << "IMPOSSIBLE" <<endl;
		}
		else{
			if (p > 0)
				vs[0][0] = 'P';
			else if (r > 0)
				vs[0][0] = 'R';
			else
				vs[0][0] = 'S';
			for(j = 0; j<n; j++){
				for (int k = 0; k < (1<<j); k++){
					if (vs[j][k] == 'P'){
						if (j >= n-3){
							vs[j+1][2*k] = 'P';
							vs[j+1][2*k+1] = 'R';
						}
						else{
							vs[j+1][2*k] = 'R';
							vs[j+1][2*k+1] = 'P';
						}
					}else if (vs[j][k] == 'S'){
						if (j >= n-2){
							vs[j+1][2*k] = 'P';
							vs[j+1][2*k+1] = 'S';
						}
						else{
							vs[j+1][2*k] = 'S';
							vs[j+1][2*k+1] = 'P';
						}
					}else{
						if (j == n-1){
							vs[j+1][2*k] = 'R';
							vs[j+1][2*k+1] = 'S';
						}
						else{
							vs[j+1][2*k] = 'S';
							vs[j+1][2*k+1] = 'R';
						}
					}
				}

			}
			for (int k = 0; k < (1<<n); k++){
				cout << vs[n][k];
			}
			cout << endl;
		}
	}
	return 0;
}
