#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <fstream>
using namespace std;

#define REP(i, n) for(int i=0;i<int(n);i++)
#define FOR(i, n) for(int i=1;i<=int(n);i++)
#define FORE(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) c.begin(), c.end()
#define clear(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;
typedef map<int, double>::iterator mit;

int A[5][5], B[5][5];

int main() {
    int T; cin >> T; 
    REP(q, T){

        int row1, row2;
        cin >> row1;
        FOR(i, 4) FOR(j, 4) cin >> A[i][j];
        cin >> row2;
        FOR(i, 4) FOR(j, 4) cin >> B[i][j];

        int cnt = 0, ans;
        FOR(x, 16) {
            int rowx1, rowx2;
            FOR(i, 4) FOR(j, 4) if(A[i][j] == x) rowx1 = i;
            FOR(i, 4) FOR(j, 4) if(B[i][j] == x) rowx2 = i;
            if(rowx1 == row1 and rowx2 == row2)
                cnt ++, ans = x;
        }
        cout << "Case #" << q + 1 << ": ";
        if(cnt > 1) cout << "Bad magician!\n";
        else if(cnt == 0) cout << "Volunteer cheated!\n";
        else cout << ans << "\n";
    }
}























