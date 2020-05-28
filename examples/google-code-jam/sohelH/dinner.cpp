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

#define debug 0

struct node {
	vector<int> v;
	node() { v.clear(); };
};

vector<node> VN;
vector<int> P;
void gen() {
	int i, j;
	P.clear();
	for(i=2;i<=1000;i++) {
		for(j=2;j<i;j++) {
			if( i % j == 0 ) break;
		}
		if( j == i ) P.pb(i);
	}

	VN.clear();
	node A; VN.pb(A); VN.pb(A);
	for(i=2;i<=1000;i++){
		int ii = i;
		int j = 0;
		VI T; T.clear();
		while(ii > 1 ) {
			while( ii % P[j] == 0 ) {
				T.pb(P[j]);
				ii /= P[j];			
			}
			j++;
		}
		node A; A.v = T;
		VN.pb(A);		
	}
}

vector<node> VT;

int main() {
	gen();
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		int n;
		cin >> n;	
		VT = VN;
		// max
		int minv = 0;
		while(1) {
			int sz = 0;
			int ii = -1;
			int i;
			for(i=n;i>=2;i--) {
                if( sz < VT[i].v.size() ){ sz = VT[i].v.size(); ii = i; }
			}
			if( sz == 0 ) break;
			if( debug ) cout << "::" << ii << endl;
			minv++;
			int a, b;
			
			if( ii == 9 ) {
               a = 0;   
             }

			for(i=ii-1;i>=2;i--) {
				a = b = 0;				
				while( a < VT[ii].v.size() && b < VT[i].v.size() ) {
					if( VT[ii].v[a] == VT[i].v[b] ) {
						VT[i].v.erase(VT[i].v.begin() + b);
						a++;
					}
					else {
						if( VT[ii].v[a] < VT[i].v[b] ) a++;
						else b++;
					}
				} 
			}
			VT[ii].v.clear();
		}

		int maxv = 1;
		int siv[1001];
		int i, j;
		for(i=1;i<=n;i++) siv[i] = i;
		for(i=2;i<=n;i++) {
			if( siv[i] != 1 ) {
				maxv++;
				for(j=i+i;j<=n;j+=i)
					siv[j] /= siv[i];
			}
		}
		if( debug ) pf("--%d %d\n", maxv, minv);
		if( n == 1 ) maxv = minv;
		pf("Case #%d: %d\n", cases, maxv - minv);
	}
	return 0;
}
