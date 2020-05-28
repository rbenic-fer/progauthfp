#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<utility>
#include<sstream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<assert.h>

using namespace std;

const int maxn = 2000 + 50;

int N, M;
int u[maxn], v[maxn];
int g[maxn][maxn], to[maxn][maxn];
int id[maxn][maxn];
bool vis[maxn][maxn];
vector<int> poly[maxn];
int cpoly;

int flavor[maxn];
bool polygon[maxn][maxn];
int answer;
bool used[maxn];

bool out[maxn];

void dfs(int depth)
{
	bool *p = polygon[depth];
	int t = -1, s;

  	memset(out, 0, sizeof(out));
	 
	int temp = -1; 
	for(int i=0; i<M; i++)
		if(used[i]==false && p[u[i]] && p[v[i]])
		{
			out[u[i]] = true;
			out[v[i]] = true;
			temp = u[i];
		}

	if(temp == -1)
	{
		int u = 0;
		for(int i=0; i<N; i++)
			if(p[i])
			{
				flavor[i] = u++;
			}
		answer = u;
		return;
	}

	int be = temp;
	int count = 0;
	for(int i=1; i<N; i++)
	{
		int x = (i+temp) % N;

		if(p[x]) count++;

		if(out[x])
		{
			if(g[be][x] && count > 1)
			{
				t = be;
				s = x;
				break;
			}
			else
			{
				count = 0;
				be = x;
			}
		}
	}

	assert(t!=-1);

	used[id[s][t]] = true;

	for(int i=0; i<N; i++)
		polygon[depth+1][i] = p[i];

	int u = 0;
	for(int i=t+1; i!=s; i=(i+1)%N)
	{
		if(p[i]) u++;
		polygon[depth+1][i] = false;
	}

	if(u == 0)
	{
		int u = 0;
		for(int i=0; i<N; i++)
			if(p[i])
			{
				flavor[i] = u++;
			}
		answer = u;
		return;
	}

	dfs(depth + 1);

	if(answer > u+2) answer = u+2;

	int p0 = flavor[s];
	int p1 = flavor[t];
	int it = 0;
	while(it == p0 || it == p1) it++;

	for(int i=t+1; i!=s; i=(i+1)%N)
	{
		if(p[i])
		{
			flavor[i] = it;
			it++;
			while(it == p0 || it == p1) it++;
		}
	}
}

void dfs2(int depth)
{
	bool *p = polygon[depth];
	int t = -1, s;

  	memset(out, 0, sizeof(out));
	 
	int temp = -1; 
	for(int i=0; i<M; i++)
		if(used[i]==false && p[u[i]] && p[v[i]])
		{
			out[u[i]] = true;
			out[v[i]] = true;
			temp = u[i];
		}

	if(temp == -1)
	{
		int u = 0;
		for(int i=0; i<N; i++)
			if(p[i])
			{
				flavor[i] = u++;
			}
		return;
	}

	int be = temp;
	int count = 0;
	for(int i=1; i<N; i++)
	{
		int x = (i+temp) % N;

		if(p[x]) count++;

		if(out[x])
		{
			if(g[be][x] && count > 1)
			{
				t = be;
				s = x;
				break;
			}
			else
			{
				count = 0;
				be = x;
			}
		}
	}

	assert(t!=-1);

	used[id[s][t]] = true;

	for(int i=0; i<N; i++)
		polygon[depth+1][i] = p[i];

	int u = 0;
	for(int i=t+1; i!=s; i=(i+1)%N)
	{
		if(p[i]) u++;
		polygon[depth+1][i] = false;
	}

	if(u == 0)
	{
		int u = 0;
		for(int i=0; i<N; i++)
			if(p[i])
			{
				if(u < answer)
				{
					flavor[i] = u;
				}
				else
				{
					flavor[i] = (u - answer) % 2 == 0 ? answer - 2 : answer -1;
				}
				u++;
			}
		return;
	}

	dfs2(depth + 1);

	int p0 = flavor[s];
	int p1 = flavor[t];
	int it = 0, last;
	while(it == p0 || it == p1) it++;

	for(int i=t+1; i!=s; i=(i+1)%N)
	{
		if(p[i])
		{
			if(it < answer)
			{
				flavor[i] = it;
				last = it;
			}
			else
			{
				flavor[i] = (it - answer) % 2 == 0 ? p0 : last;
			}
			it++;
			while(it == p0 || it == p1) it++;
		}
	}
}


int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++)
	{
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));

		scanf("%d%d", &N, &M);
		for(int i=0; i<M; i++)
		{
			scanf("%d", &u[i]);
			u[i]--;
		}
		for(int i=0; i<M; i++)
		{
			scanf("%d", &v[i]);
			v[i]--;
		}

		for(int i=0; i<M; i++)
		{
			g[u[i]][v[i]] = g[v[i]][u[i]] = 1;
			id[u[i]][v[i]] = id[v[i]][u[i]] = i;
		}

		for(int i=0; i<N; i++) polygon[0][i] = true;
		answer = 0;
		memset(used, 0, sizeof(used));
		dfs(0);
		
		for(int i=0; i<N; i++) polygon[0][i] = true;
		memset(used, 0, sizeof(used));
		dfs2(0);

		for(int i=0; i<N; i++) if(flavor[i] >= answer) flavor[i] = 0;

		printf("Case #%d: %d\n", test, answer);
		for(int i=0; i<N; i++)
		{
			printf("%d", flavor[i] + 1);
			if(i==N-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
