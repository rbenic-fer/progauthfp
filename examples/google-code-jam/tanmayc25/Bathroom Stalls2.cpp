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
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int main()
{
	freopen("C-small-2-attempt1.in","r",stdin);
	freopen("output.txt", "w", stdout);
	fast_io;
	int tests; cin >> tests;
	forall(tt, 1, tests + 1)
	{
		ll n, k;
		cin >> n >> k;
		priority_queue<int > pq;
		pair<int, int > ans;

		int cur = n;
		for (int i = 0; i < k && cur>0; i++)
		{
			if (pq.size())
			{
				cur = pq.top();
				pq.pop();
			}
			if (cur > 0)
			{
				if (cur & 1)ans = { (cur - 1) / 2, (cur - 1) / 2 };
				else ans = { cur / 2 ,cur / 2 - 1};
			}
			pq.push(ans.second);
			pq.push(ans.first);
		}
		cout << "Case #" << tt << ": " << ans.first << " " << ans.second << endl;
	}
	return 0;
}
