//by Tanmay Chaudhari
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#pragma comment(linker, "/STACK:66777216")
#include <bits/stdc++.h>
using namespace std;

#define si(a)				scanf("%d",&a)
#define sl(a)				scanf("%lld",&a)
#define pi(a)				printf("%d\n",a)
#define pl(a)				printf("%lld\n",a)

typedef long long			ll;
typedef vector<int>			vi;
typedef pair<int, int>		ii;
typedef vector<vi>			vvi;
typedef vector<ii>			vii;

#define fast_io				ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SET(a,b)			memset(a,b,sizeof(a))	
#define forall(i,a,b)		for(int i=a; i<b; i++)
#define forrev(i,a,b)		for(int i=a; i>=b; i--)
#define forr(it,container)  for(auto it=container.begin(); it!=container.end(); it++)
#define w(t)				int t;si(t);while(t--)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int adj[55][55];
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	si(t);
	forall(tt, 1, t + 1)
	{
		ll b, m;
		cin >> b >> m;
		cout << "Case #" << tt << ": ";
		ll sum = (1LL << (b - 2));
		if (sum < m)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		ll cnt = 0;
		bool done = 0;
		if (b == 2)
			adj[0][b - 1] = 1;
		for (ll i = 1;i < sum;i++)
		{
			int prev = 0;
			for (int j = 0;j <= b - 2;j++)
			{
				if (i&(1LL << j))
				{
					adj[prev][j + 1] = 1;
					prev = j + 1;
					cnt++;
				}
				if (cnt == m)
				{
					done = 1;
					break;
				}
			}
			adj[prev][b - 1] = 1;
			if (done)break;
		}
		for (int i = 0;i < b;i++)
		{
			for (int j = 0;j < b;j++)
			{
				cout << adj[i][j];
			}
			cout << endl;
		}
		SET(adj, 0);
	}
	return 0;
}