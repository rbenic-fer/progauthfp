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
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		string s; int k;
		cin >> s >> k;
		int ans = 0;
		forall(i, 0, s.size() - k + 1)
		{
			if (s[i] == '-')
			{
				forall(j, i, i + k)
				{
					if (s[j] == '+')s[j] = '-';
					else s[j] = '+';
				}
				ans++;
			}
			int cnt = 0;
			forall(j, 0, s.size())if (s[j] == '-')cnt++;
			if (!cnt)break;
		}
		bool ok = 1;
		forall(i, 0, s.size())if (s[i] == '-')ok = 0;
		cout << "Case #" << tt << ": ";
		if (ok)cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
