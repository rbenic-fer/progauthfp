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

const int N = 123;
pair<pair<ll, ll >, pair<ll, ll > > arr[N];

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	fast_io;
	int tests; cin >> tests;
	forall(tt, 1, tests + 1)
	{
		ll n, k;
		cin >> n >> k;
		SET(arr, 0);
		if (k != 1)arr[0] = { { n / 2, 1 }, { n / 2, 1 } };
		if (k != 1 && !n%2)arr[0].first.first--;

		int itr = 0;
		ll cnt = 0, itr2;
		//trace(arr[itr].first.first, arr[itr].first.second, arr[itr].second.first, arr[itr].second.second);
		for (itr2 = 2; cnt < k - 1; itr2 *= 2)
		{
			cnt += itr2;
			if (cnt >= (k - 1))break;
			pair<ll, ll > q = arr[itr].second, q1;
			if (q.first & 1)q1 = { q.first / 2,q.first / 2 };
			else q1 = { q.first / 2 - 1,q.first / 2 };

			pair<ll, ll > p = arr[itr++].first, p1;
			if (p.first & 1)p1 = { p.first / 2,p.first / 2 };
			else p1 = { p.first / 2 - 1,p.first / 2 };

			arr[itr].first = { p1.first, arr[itr - 1].first.second };

			if (p.first & 1)arr[itr].first.second += arr[itr - 1].first.second;
			else
			{
				arr[itr].second.first = p1.second;
				arr[itr].second.second += arr[itr - 1].first.second;
			}

			if (p1.first == q1.first)arr[itr].first.second += arr[itr - 1].second.second;
			else
			{
				arr[itr].second.first = q1.first;
				arr[itr].second.second += arr[itr - 1].second.second;
			}

			if (p1.first == q1.second)arr[itr].first.second += arr[itr - 1].second.second;
			else
			{
				arr[itr].second.first = q1.second;
				arr[itr].second.second += arr[itr - 1].second.second;
			}

			//trace(arr[itr].first.first, arr[itr].first.second, arr[itr].second.first, arr[itr].second.second);
		}

		ll temp = k, ans;
		if (k != 1)k -= (cnt - itr2);
		else ans = n;

		if (temp != 1 && arr[itr].first.first > arr[itr].second.first)
		{
			if (arr[itr].first.second > k)ans = arr[itr].first.first;
			else ans = arr[itr].second.first;
		}
		else if (temp != 1 && arr[itr].first.first <= arr[itr].second.first)
		{
			if (arr[itr].second.second > k)ans = arr[itr].second.first;
			else ans = arr[itr].first.first;
		}

		if (ans == 1 || ans == 0)cout << "Case #" << tt << ": 0 0" << endl;
		else
		{
			cout << "Case #" << tt << ": ";
			if (ans & 1)cout << ans / 2 << " " << ans / 2 << endl;
			else cout << ans / 2 << " " << ans / 2 - 1 << endl;
		}
	}
	return 0;
}
