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

const long double pi =acos(-1.0);
stack<int> st;
vii ss;
int n, k;
long double tam[1000][2], tamx[1000][2]; //tamaño de la LIS que termina en i

long double dplis(){

	int bestEnd=0;
	for(int i=0; i<n; i++){
		tamx[i][0]=pi*ss[i].first*ss[i].first+2*pi*ss[i].second*ss[i].first;
		tamx[i][1] = 1;
		tam[i][0]=pi*ss[i].first*ss[i].first+2*pi*ss[i].second*ss[i].first;
		tam[i][1] = 1;
	}
	for(int l=1; l<k; l++){
		for(int i=0; i<n; i++){
			for(int j=0; j<i; j++) if(tamx[j][0]+2*pi*ss[i].second*ss[i].first > tam[i][0]){
				tam[i][0]=tamx[j][0]+2*pi*ss[i].second*ss[i].first;
				tam[i][1] = tamx[j][1]+1;
		}	}
		for(int i=0; i<n; i++){
			tamx[i][0] = tam[i][0];
			tamx[i][1] = tam[i][1];
		}
	}
	for(int j=0; j<n; j++) if(tamx[j][0]>tamx[bestEnd][0] && tamx[j][1]==k) bestEnd=j;
	return tamx[bestEnd][0];
}

bool asdf(ii a, ii b){
	return a.first > b.first;
}

int main (){
	int t;
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> n >> k;
		ss.clear();
		int aux, aux2;
		for (int j =0 ; j<n; j++){
			cin >> aux >> aux2;
			ss.push_back(ii(aux, aux2));
		}
		sort(ss.begin(), ss.end(), asdf);
		cout << "Case #" << i+1  << ": " << setprecision(9) << fixed << dplis() << endl;
	}
	return 0;
}
