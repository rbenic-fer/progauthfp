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

int main() {
	int t, cases;
	cin >> t;
	for( cases = 1; cases <= t; cases++ ) {
		int n; cin >> n;
		VI O, B; O.clear(); B.clear();
		VI S; S.clear();
		int i;
		fo(i, n) {
			string s; int x;
			cin >> s >> x;
			if( s == "O") {
				S.pb(0);
				O.pb(x);
			}
			else {
				S.pb(1);
				B.pb(x);
			}
		}
		int op, bp;
		op = bp = 1;
		int tm = 0;
		int inc = 0;
		while( inc < S.size() ) {
			if( S[inc] == 0 ) { // orange
				if( O[0] == op ) { inc++; O.erase(O.begin()); }
				else op += op > O[0] ? -1 : 1;
				if( B.size() && bp != B[0] ) 
					bp += bp > B[0] ? -1 : 1;

			}			
			else if( S[inc] == 1 ) {
				if( B[0] == bp ) { inc++; B.erase(B.begin()); }
				else bp += bp > B[0] ? -1 : 1;

				if( O.size() && op != O[0] ) 
					op += op > O[0] ? -1 : 1;
			}
			tm++;
		}
		pf("Case #%d: %d\n", cases, tm);
	}
	return 0;
}

