#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>

using namespace std;

#define pf printf
#define sf scanf
#define VI vector<int>
#define pb push_back
#define fo(a,b) for(a=0;a<b;a++)

const int inf = 1000000000;

int debug = 0;

int n;
string S[105];
double OWP[105];

double find_wp(int u) {
	int i;
	int w, l;
	w = l = 0;
	for(i=0;i<n;i++)
		if( S[u][i] == '1' ) w++;
		else if( S[u][i] == '0') l++;
	return 1.0 * w / (w + l);
}

double f_wp1(int u, int v) {
	int i;
	int w, l;
	w = l = 0;
	for(i=0;i<n;i++) {
		if( i == v ) continue;
		if( S[u][i] == '1' ) w++;
		else if( S[u][i] == '0') l++;

	}
	return 1.0 * w / (w + l);	
}

double find_owp(int u) {
	int i;
	double sum = 0;
	int cnt = 0;
	for(i=0;i<n;i++) {
		if( S[u][i] != '.') {
			sum += f_wp1(i, u);	
			cnt++;
		}
	}
	return sum / cnt;
}

double find_oowp(int u) {
	int i;
	double sum = 0;
	int cnt = 0;
	for(i=0;i<n;i++) {
		if( S[u][i] != '.') {
			sum += OWP[i];
			cnt++;
		}
	}
	return sum / cnt;
}

int main() {
	int t; cin >> t;
	int cases = 1;
	for( cases = 1; cases<= t; cases++) {
		cin >> n;
		int i, j;
		for(i=0;i<n;i++) cin >> S[i];

		for(i=0;i<n;i++) {
			double rpi = 0;
			double wp = find_wp(i);
			double owp = find_owp(i);
			OWP[i] = owp;
			//double oowp = find_oowp(i);

			//pf("%.9lf\n", rpi);
		}
		pf("Case #%d:\n", cases);
		for(i=0;i<n;i++) {
			double rpi = 0;
			double wp = find_wp(i);
			double oowp = find_oowp(i);
if(debug) {
	pf("%d - %lf %lf %lf\n", i, wp, OWP[i], oowp);
}			
			rpi = 0.25 * wp + 0.5 * OWP[i] + 0.25 * oowp;

			pf("%.9lf\n", rpi);
		
		}

	}
	return 0;
}
