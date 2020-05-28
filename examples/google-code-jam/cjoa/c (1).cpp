#include <iostream>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

#define SZ(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

#define HIGHESTSETBIT(mask) ( sizeof(int)*8-1-__builtin_clz((mask)) )

#define INF 98765432

struct Edge {
   int u, v;
   int rev;  // index of reverse edge
   int cap, flow;
   Edge(int _u, int _v, int _rev = 0, int _cap = 1) :
     u(_u), v(_v), rev(_rev), cap(_cap), flow(0) {}
};

class MaxFlowAdj {
   size_t N;
   VI sp_par, sp_D;
   bool augmenting_path_bfs(int src, int dst, int mincap=0);
// bool augmenting_path_pfs(int src, int dst, int mincap=0);

   VI last_edge;
   int update_flow_dfs(int u, int dst, int cfp = INF);  // for Dinic

public:
   vector<Edge> edges;
   VVI adj;  // adjacency lists of edge indices

   MaxFlowAdj(size_t _N) : N(_N), adj(VVI(_N)) {}
   void add_edge(int u, int v, int _cap=1);

   // Edmonds-Karp Ford Fulkerson Shortest Augmenting Path -- O(V * E^2)
   int edmonds_karp(int s, int t, bool scaled=false);

   // Dinic's Algoritm -- O(V^2 * E)
   int dinic(int s, int t);

   // return one possible min cut
   vector<Edge> mincut(int s, int t);
};

inline void MaxFlowAdj::add_edge(int u, int v, int _cap) {
   int num_edges = edges.size();
   // forward edge
   edges.push_back( Edge(u, v, num_edges+1, _cap) );
   adj[u].push_back(num_edges++);
   // reverse edge
   edges.push_back( Edge(v, u, num_edges-1, 0) );
   adj[v].push_back(num_edges++);
}

bool MaxFlowAdj::augmenting_path_bfs(int src, int dst, int mincap) {
   sp_par.assign(N, -1);
   sp_D.assign(N, -1);

   sp_D[src] = 0;
   queue<int> q;
   q.push(src);
   while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int j = 0; j < (int) adj[cur].size(); ++j) {
         int e = adj[cur][j];
         int v = edges[e].v;
         if (sp_D[v] < 0 && edges[e].cap - edges[e].flow > mincap) {
            sp_D[v] = sp_D[cur] + 1;
            sp_par[v] = e;
            q.push(v);
         }
      }
   }
   return sp_D[dst] >= 0;
}

int MaxFlowAdj::update_flow_dfs(int u, int dst, int cfp) {
   if (u == dst)
      return cfp;
   for (; last_edge[u] < adj[u].size(); ++last_edge[u]) {
      int e = adj[u][ last_edge[u] ];
      int u = edges[e].u;
      int v = edges[e].v;

      if (sp_D[v] == sp_D[u] + 1 && edges[e].cap - edges[e].flow > 0) {
         int res = update_flow_dfs(v, dst, min( cfp, edges[e].cap - edges[e].flow ));
         if (res > 0) {
            edges[e].flow += res;
            edges[ edges[e].rev ].flow = -edges[e].flow;  // -= cfp;
            return res;
         }
      }
   }
   return 0;
}

int MaxFlowAdj::dinic(int s, int t) {
   N = int(adj.size());
   for (int j = 0; j < (int) edges.size(); ++j)
      edges[j].flow = 0;

   VI path;
   int res = 0;

   while ( augmenting_path_bfs(s, t) ) {
      // try finding more paths
      
      for (int j = 0; j < adj[t].size(); ++j) {
         int e = edges[ adj[t][j] ].rev;
         int w = edges[e].u;
         if (sp_D[w] >= 0 && edges[e].cap - edges[e].flow > 0) {
            int cfp = edges[e].cap - edges[e].flow;
            for (int curv = w; sp_par[curv] >= 0; ) {
               int ee = sp_par[curv];
               cfp = min(cfp, edges[ee].cap - edges[ee].flow);
               curv = edges[ee].u;
            }
            edges[e].flow += cfp;
            edges[ edges[e].rev ].flow = -edges[e].flow;  // -= cfp;
            for (int curv = w; sp_par[curv] >= 0; ) {
               int ee = sp_par[curv];
               edges[ee].flow += cfp;
               edges[ edges[ee].rev ].flow = -edges[ee].flow;  // -= cfp;
               curv = edges[ee].u;
            }
            res += cfp;
         }
      }

/*
      // UNTESTED
      last_edge.assign(N, 0);
      while (true) {
         int cfp = update_flow_dfs(s, t);
         if (cfp <= 0) break;
         res += cfp;
      }
*/
   }
   return res;
}

struct Rect {
   int x0, y0, x1, y1;
};

int W, H, B;
Rect buildings[12];
bool A[504][104];

#define IN(y, x) ( ( (x) + (y)*W ) * 2 )
#define OUT(y, x) ( ( (x) + (y)*W ) * 2 + 1 )

int dr[] = {-1, 0, 0, +1};
int dc[] = {0, -1, +1, 0};

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> W >> H >> B;

      REP(i, B) {
         Rect& b = buildings[i];
         cin >> b.x0 >> b.y0 >> b.x1 >> b.y1;
      }
      
      REP(y, H) REP(x, W) {
         bool blocked = false;
         REP(i, B) {
            const Rect& b = buildings[i];
            if (b.x0 <= x && x <= b.x1 && b.y0 <= y && y <= b.y1) {
               blocked = true;
               break;
            }
         }
         A[y][x] = blocked;
      }

/*
      for (int y = H-1; y >= 0; --y) {
         REP(x, W)
            cerr << ( A[y][x] ? '#' : '.' );
         cerr << endl;
      }
      cerr << endl;
*/
      
      MaxFlowAdj mf(W*H*2 + 2);
      const int SRC = W*H*2;
      const int DST = W*H*2 + 1;

      REP(y, H) REP(x, W)
         mf.add_edge( IN(y, x), OUT(y, x), 1 );

      REP(x, W) {
         if (!A[0][x])
            mf.add_edge( SRC, IN(0, x), 1 );
         if (!A[H-1][x])
            mf.add_edge( OUT(H-1, x), DST, 1 );
      }

      REP(y, H) REP(x, W) {
         REP(k, 4) {
            int ny = y + dr[k], 
                nx = x + dc[k];
            if (0 <= ny && ny < H && 0 <= nx && nx < W) {
               mf.add_edge( OUT(y, x), IN(ny, nx), 1 );
               mf.add_edge( OUT(ny, nx), IN(y, x), 1 );
            }
         }
      }

      int res = mf.dinic(SRC, DST);

      cout << "Case #" << tc << ": " << res-1 << endl;
   }

   return 0;
}
