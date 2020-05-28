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

int R, C, D;
string S[105];

bool ok(int sr, int sc, int er, int ec, int K) {
	double y = (er - sr) / 2.0 + sr;
	double x = (ec - sc) / 2.0 + sc;
	int i, j;
	double sumy = 0;
	double sumx = 0;
	for(i=sr;i<=er;i++)
		for(j=sc;j<=ec;j++) {
			if( i == sr && j == sc ) continue;
			if( i == sr && j == ec ) continue;
			if( i == er && j == sc ) continue;
			if( i == er && j == ec ) continue;
			sumy += 1.0 * (i - y) * (D + S[i][j] - '0');
		        sumx += 1.0 * (j - x) * (D + S[i][j] - '0');	
		}
	if( fabs(sumy) > 1e-9 ) return false;
	if( fabs(sumx) > 1e-9 ) return false;
	if( debug ) {
		if( sr == 1 && sc == 1 && K == 5 ) {
			cout << sumy << " " << sumx << endl;
		}
	}
	return true;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		cin >> R >> C >> D;		
		int i, j, k;
		fo(i, R) cin >> S[i];
		int res = 0;
		for(i=0;i<R;i++) {
			for(j=0;j<C;j++) {
				for(k=3;;k++) {
					int ii = i + k - 1;
					int jj = j + k - 1;
					if( ii >= R || jj >= C ) break;	
					if( k < res ) continue;
					if( ok(i, j, ii, jj, k) ) res = k;
				}
			}
		}
		if( res < 3 ) pf("Case #%d: IMPOSSIBLE\n", cases);
		else pf("Case #%d: %d\n", cases, res);
	}
	return 0;
}

