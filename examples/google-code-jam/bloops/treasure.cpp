#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
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
typedef vector<int> vi;
const int N = 210;

struct edge {
    bool used;
    int index;
    vector<int> to;
};

vector<edge> E[N];
int indegree[N], outdegree[N];
bool alive[N], visited[N];

bool bfs(const multiset<int>& cur){
    CLEAR(alive, 0);
    REP(i, N) if(indegree[i] > 0 or outdegree[i] > 0) alive[i] = 1;
    //REP(i, 4) cout << i << ": indegree: " << indegree[i] << " outdegree: " << outdegree[i] << endl;
    CLEAR(visited, 0);
    queue<int> que;
    FORE(x, cur) que.push(*x);
    while(!que.empty()) {
        int col = que.front();
        que.pop();
        if(visited[col]) continue;
        visited[col] = 1;
        //cout << "visiting: " << col << endl;
        FORE(edge, E[col]){
            if(edge->used) continue;
            FORE(to, edge->to)
                if(!visited[*to]) que.push(*to);
        }
    }
    REP(i, N) if(alive[i] and !visited[i]) {
        //cout << "not reachable: " << i << endl;
        return false;
    }
    //cout << "all reachable!" << endl;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int tcases;
    cin >> tcases;
    FOR(tc, 1, tcases + 1) {
        REP(i, N) E[i].clear();
        CLEAR(indegree, 0);
        CLEAR(outdegree, 0);

        int n, k;
        cin >> k >> n;
        vector<int> keys(k);
        REP(i, k) cin >> keys[i];

        REP(i, n) {
            int from, nto, to;
            cin >> from >> nto;
            edge e;
            e.used = 0;
            e.index = i + 1;
            outdegree[from]++;
            e.to.push_back(0);
            indegree[0]++;
            REP(j, nto) { 
               cin >> to;
               e.to.push_back(to);
               indegree[to]++;
            }
            E[from].push_back(e);
        }

        CLEAR(alive, 0);
        REP(i, N) if(indegree[i] > 0 or outdegree[i] > 0) alive[i] = 1;

        multiset<int> S;
        FORE(x, keys) S.insert(*x);

        bool ok = 1;
        REP(i, k) indegree[keys[i]]++;
        REP(i, N) if(alive[i] and indegree[i] < outdegree[i]) ok = 0;
        REP(i, k) indegree[keys[i]]--;
        if(!bfs(S)) ok = 0;

        cout << "Case #" << tc << ": ";
        if(!ok) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> order;
        REP(i, n) {
            int next = N, nextkey = -1;
            FORE(it, S) {
                int k = *it; // try this key on some box (edge)
                // cout << "Trying key " << k << endl;
                FORE(edge, E[k]) if(!edge->used) {
                    multiset<int> S2 = S;
                    S2.erase(S2.find(k));
                    FORE(to, edge->to) { S2.insert(*to); indegree[*to]--; }
                    edge->used = 1;
                    outdegree[k]--;
                    if(bfs(S2))
                        if(next > edge->index)
                            next = edge->index, nextkey = k;
                    edge->used = 0;
                    outdegree[k]++;
                    FORE(to, edge->to) {indegree[*to]++; }
                }
            }
            assert(nextkey != -1);
            S.erase(S.find(nextkey));
            outdegree[nextkey]--;
            FORE(edge, E[nextkey]) if(edge->index == next) {
                edge->used = 1;
                FORE(to, edge->to) { S.insert(*to); indegree[*to]--; }
            }
            //cout << "using key: " << nextkey << " for box: " << next << endl;
            order.push_back(next);
        }
        
        REP(i, n) cout << order[i] << ' ';
        cout << endl;
    }
    return 0;
}

