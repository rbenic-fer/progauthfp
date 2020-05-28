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
typedef priority_queue < pair<int, char> , vector < pair<int, char> >, less < pair<int,char > > > maxheap;
int p[26];
maxheap pq;
vector<pair<int, char> > v;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	si(t);
	forall(tt, 1, t + 1)
	{
		int n, cnt=0, rem, pr;
		si(n);
		rem = pr = 0;
		forall(i, 0, n)
		{
			si(p[i]);
			cnt += p[i];
			v.push_back({ p[i], i+'A' });
		}	
		cout << "Case #" << tt << ": ";
		while (1)
		{
			sort(v.begin(),v.end());
			reverse(v.begin(), v.end());
			if (v[0].first == 0)break;
			bool ok = 1;
			if (v[0].first >= 2)
			{
				int temp = max(v[0].first - 2, v[1].first);
				if (2 * temp <= cnt - rem - 2)
				{
					cout << v[0].second << v[0].second << " ";
					v[0].first -= 2;
					rem += 2;
					ok = 0;
					continue;
				}
				temp = max(v[0].first - 1, v[1].first - 1);
				if (ok && 2 * temp <= cnt - rem - 2)
				{
					cout << v[0].second << v[1].second << " ";
					v[0].first--;v[1].first--;
					rem += 2;
					ok = 0;
					continue;
				}
				temp = max(v[0].first - 1, v[1].first);
				if (ok && 2 * temp <= cnt - rem - 1)
				{
					cout << v[0].second << " ";
					v[0].first--;
					rem++;
					ok = 0;
					continue;
				}
			}
			else
			{
				if (cnt - rem == 2)
				{
					cout << v[0].second << v[1].second << " ";
					v[0].first--;
					v[1].first--;
					rem += 2;
					continue;
				}
				else
				{
					cout << v[0].second << " ";
					v[0].first--;
					rem++;
					continue;
				}
			}
		}
		cout << endl;
	}
	return 0;
}