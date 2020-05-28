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

bool field[10][10];
int nums[10][10];

int r, c;

bool ok(int i, int j) {
    return i >= 0 and i < r and j >= 0 and j < c;
}

void makenums() {
    clear(nums, 0);
    REP(i, r) REP(j, c) {
        if(field[i][j] == 1) {
            nums[i][j] = -1; 
            continue;
        }
        for(int di = -1; di <= 1; di++)
            for(int dj = -1; dj <= 1; dj++) {
                if(!ok(i + di, j + dj)) continue;
                nums[i][j] += field[i + di][j + dj];
            }
    }
}

// check if 0's are all connected, and if nonzeros are adjacnt to a zero

bool visited[10][10];

void dfs(int i, int j) {
    if(!ok(i,j)) return;
    if(nums[i][j] != 0) return;
    if(visited[i][j]) return;
    visited[i][j] = 1;
    for(int di = -1; di <= 1; di++)
        for(int dj = -1; dj <= 1; dj++)
            dfs(i + di, j + dj);
     
}


bool connected() {
    clear(visited, 0);
    REP(i, r) REP(j, c) if(nums[i][j] == 0) {
        dfs(i, j);

        REP(k, r) REP(l, c) 
            if(nums[k][l] == 0 and !visited[k][l])
                return false;
        return true;
    }
}

bool adj() {
    REP(i, r) REP(j, c) if(nums[i][j] > 0) {
        bool good = 0;
        for(int di = -1; di <= 1; di++)
            for(int dj = -1; dj <= 1; dj++) 
                if(ok(i + di, j + dj) and nums[i + di][j + dj] == 0)
                    good = 1;
        if(!good) return false;
    }
    return true;
}

char output[10][10];

void print() {
    REP(i, r) {
        REP(j, c) cout << output[i][j];
        cout << endl;
    }
}

int main() {
    int T; cin >> T; 
    REP(q, T){
        int m;
        cin >> r >> c >> m;
        cout << "Case #" << q + 1 << ":\n";

        bool found = 0;

        if(r*c == m + 1) {
            REP(i, r) REP(j, c) output[i][j] = '*';
            output[0][0] = 'c';
            print();
            found = 1;
        }
        else REP(mask, 1<< (r*c)) {
            if(__builtin_popcount(mask) != m) continue;
            REP(i, r) REP(j, c) 
                field[i][j] = (mask & (1 << (c*i + j))) > 0 ? 1 : 0;


            makenums();

            int numclean = 0;
            REP(i, r) REP(j, c) if(nums[i][j] == 0) numclean++;
            if(numclean == 0) continue;

            if(connected() and adj()) {
                int ci, cj;
                REP(i, r) REP(j, c) if(nums[i][j] == 0) ci = i, cj = j;

                REP(i,r) REP(j, c) output[i][j] = field[i][j] ? '*' : '.';
                output[ci][cj] = 'c';
                print();

                found = 1;
                break;
            }
        }

        if(!found) cout << "Impossible" << endl;
    }
}























