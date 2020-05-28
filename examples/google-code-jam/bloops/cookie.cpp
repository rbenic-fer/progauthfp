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

long double eps = 1e-15;
int main() {
    int T; cin >> T; 
    REP(q, T){
        long double c, f, x;
        cin >> c >> f >> x;
        long double step = 0.5 * c, best = 0.5 * x, time = 0.0;
        int maxfarms = (int) ((x + eps)/ c);

        long double rate;
        for(int farms = 0; farms <= maxfarms; farms ++){
            rate  = 2.0 + (farms * f);
            best = min(best, time + (x / rate));
            // add time to get to buy next farm
            time += c / rate;
        }

        cout << "Case #" << q + 1 << ": ";
        cout << setprecision(12) << fixed << best << endl;
    }
}























