#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)

#define W 105
//#define H 30
#define H 505
#define N (2*W*H+5)
#define INF (W*W)

struct Block { int x0, y0, x1, y1; };

struct Edge
{
	int j, c, f;
	Edge * r;
};


bool bad[W][H];
int n, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vector<Edge*> g[N];

void add_edge(int i, int j, int c = 1)
{
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

Edge* pre[N];

int bfs(int s, int t)
{
	list<int> q;
	q.push_back(s);
	while(!q.empty())
	{
		int i = *q.begin();
		q.pop_front();
		for(auto e : g[i]) if(e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push_back(e->j);
	}
	if(!pre[t]) return 0;
	int f = INF;
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}

int max_flow(int s, int t)
{
	clr0(pre);
	while(bfs(s, t)) clr0(pre);
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

int work()
{
	int w, h, m;
	cin >> w >> h >> m;

	//map<int, int> ys {{0, 0}, {h, 0}};
	vector<Block> bs;
	rep(i, m)
	{
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		x1++, y1++;
		//ys[y0] = ys[y1] = 0;
		bs.push_back({x0, y0, x1, y1});
	}

	/*
	int cnt = 0;
	for(auto & p : ys)
		p.second = cnt++;
	*/

	clr0(bad);
	for(auto & b : bs)
	{
		//b.y0 = ys[b.y0], b.y1 = ys[b.y1];
		range(x, b.x0, b.x1) range(y, b.y0, b.y1)
			bad[x][y] = true;
	}
	//h = ys[h];
	
	n = 2 * w * h + 2;
	rep(i, n)
	{
		g[i].clear();
	}
	rep(x, w) rep(y, h) if(!bad[x][y])
	{
		int id = h * x + y, in = 2 * id, out = in + 1;
		if(out >= n - 2)
		{
			cerr << "wut" << endl;
		}
		add_edge(in, out);
		rep(dir, 4)
		{
			int xx = x + dx[dir], yy = y + dy[dir];
			if(xx >= 0 && xx < w && yy >= 0 && yy < h && !bad[xx][yy])
				add_edge(out, 2 * (h * xx + yy));
		}
		if(y == 0)
			add_edge(n - 2, in);
		else if(y == h - 1)
			add_edge(out, n - 1);
	}

	return max_flow(n - 2, n - 1);
}

int main()
{
	int nc;
	cin >> nc;
	for(int i = 1; i <= nc; i++)
		cout << "Case #" << i << ": " << work() << endl;
	return 0;
}
