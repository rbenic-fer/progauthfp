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

const int N = 27;
string s[N];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	fast_io;
	int tests;
	cin >> tests;
	for (int tt = 1; tt <= tests; tt++)
	{
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++)cin >> s[i];
		cout << "Case #" << tt << ":" << endl;
		for (int i = 0; i < r; i++)
		{
			bool ok = 1;
			for (int j = 0; j < c; j++)if (s[i][j] != '?')ok = 0;
			if (!ok)
			{
				for (int j = 0; j < c; j++)
				{
					if (s[i][j] != '?')
					{
						int l = j-1;
						while (l >= 0 && s[i][l] == '?')
						{
							s[i][l] = s[i][j];
							l--;
						}
						l = j + 1;
						while (l < c && s[i][l] == '?')
						{
							s[i][l] = s[i][j];
							l++;
						}
					}
				}
			}
			else
			{
				if (i != 0)for (int j = 0; j < c; j++)s[i][j] = s[i - 1][j];
			}
		}
		int rr = 0;
		for (int i = 0; i < r; i++)
		{
			bool ok = 1;
			for (int j = 0; j < c; j++)if (s[i][j] == '?')ok = 0;
			if (ok)
			{
				rr = i;
				break;
			}
		}
		for (int i = 0; i < rr; i++)
		{
			for (int j = 0; j < c; j++)s[i][j] = s[rr][j];
		}
		
		//if (ok)for (int j = 0; j < c; j++)s[0][j] = s[1][j];
		for (int i = 0; i < r; i++)cout << s[i] << endl;
	}
	return 0;
}