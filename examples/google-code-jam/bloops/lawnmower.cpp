#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

#define FOR(i,a,n) for(int i = (int)a; i < (int)n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ALL(c) c.begin(), c.end()
#define CLEAR(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;

const int N = 110;
bool done[N][N];
int A[N][N];

int main(){
    ios::sync_with_stdio(false);
    int tcases;
    cin >> tcases;
    FOR(tc, 1, tcases + 1) {
        int n, m;
        cin >> n >> m;

        REP(i, n) REP(j, m) cin >> A[i][j];

        set<int> S;
        REP(i, n) REP(j, m) S.insert(A[i][j]);

        CLEAR(done, 0);
        bool ok = 1;
        FORE(it, S) {
            int val = *it;
            REP(i, n) REP(j, m) if(A[i][j] == val) {
                bool rowok = 1, colok = 1;
                REP(x, m) if(!done[i][x] and A[i][x] != val) rowok = 0;
                REP(y, n) if(!done[y][j] and A[y][j] != val) colok = 0;
                if(!rowok and !colok) ok = 0;
                done[i][j] = 1;
            }
        }

        cout << "Case #" << tc << ": ";
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

