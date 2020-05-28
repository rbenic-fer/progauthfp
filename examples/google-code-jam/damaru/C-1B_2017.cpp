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
	int t, n, aux, q;
	int e[100], s[100], d[100], v, llega[100];
	double sol[100];
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> n >> q;
		for (int j = 0; j< n; j++){
			cin>> e[j] >> s[j];
		}
		for (int j = 0; j< n; j++){
			for (int k = 0; k< n; k++){
				if(j+1==k)
					cin>> d[j];
				else
					cin >> aux;
			}
		}
		cin >> aux >> v;
		v--;
		for (int j = 0; j <v;j++){
			llega[j] = j;
			int aux = j, aux2 = e[j];

			while(aux2 > 0){
				aux2-=d[j];
				aux++;
				if (aux2 >= 0)
					llega[j] = aux;
			}
		}
		for (int j = 1; j< v; j++){
			d[j] += d[j-1];
		}
		sol[0] = 0;
		for (int j = 1; j<= v; j++){
			sol[j] = -1;
			for (int k = 0; k< j; k++){
				if(llega[k] >= j && sol[k] != -1){
					long int dist;
					if (k==0)
						dist = d[j-1];
					else
						dist = d[j-1]-d[k-1];
					double aux3 = dist/((double)(0.0+s[k]))+sol[k];
					if (sol[j] == -1)
						sol[j] = aux3;
					else{
						if (aux3< sol[j])
							sol[j] = aux3;
					}
				}
			}
		}
		std::cout << std::fixed;
		std::cout << std::setprecision(7);
		cout << "Case #" << i+1  << ": " << sol[v] << endl;
	}
	return 0;
}
