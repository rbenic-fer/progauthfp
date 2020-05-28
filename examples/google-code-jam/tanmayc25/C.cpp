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

int J[1 << 20], P[1 << 20], S[1 << 20];
int K[25][25][25];
int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	si(t);
	forall(tt, 1, t + 1)
	{
		cout << "Case #" << tt << ": ";
		int j, p, s, k, cnt = 0;
		cin >> j >> p >> s >> k;
		s = min(s, k);
		cnt = j*p*s;
		cout << cnt << endl;
		int temp = 0;
		forall(i1, 1, j + 1)
		{
			int temp2 = 0;
			forall(i2, 1, p + 1)
			{
				forall(i3, 1, s + 1)
				{
					if (temp2 == s)
					{
						temp2 -= s;
						temp++;
					}
					cout << i1 << " " << i2 << " " << i3 + temp << endl;
					temp2++;
				}
			}
		}
	}
	return 0;
}