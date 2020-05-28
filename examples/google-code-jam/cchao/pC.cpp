#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d\n", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;

char s[220][15010];
vector<int> a[220];
int l[3010], f[3010], h[3010], vis[3010];
int main() {
	Ttimes {
		map<string, int> m;
		memset(l, 0, sizeof l);
		memset(f, 0, sizeof f);
		memset(h, -1, sizeof h);
		memset(vis, -1, sizeof vis);
		int cnt = 0;
		int n; ri(n);
		rep(i, n) {
			fgets(s[i], 15010, stdin);
			stringstream ss(s[i]);
			a[i].clear();
			string t;
			while(ss >> t) {
				if(!m.count(t)) m[t] = cnt++;
				int no = m[t];
				a[i].push_back(no);
				if(i == 0) l[no] = 1;
				if(i == 1) f[no] = 1;
			}
		}
		int base = 0;
		rep(i, cnt) if(l[i] && f[i]) base++;
		int ans = 0;
		rep(i, (1 << (n - 2))) {
			int tmp = base;
			for(int j = 2; j < n; ++j) {
				if(i & (1 << (j - 2))) {
					for(int t: a[j]) {
						h[t] = i;
						if(f[t] == 1 && (l[t] + f[t] != 2) && vis[t] != i) {
							tmp++;
							vis[t] = i;
						}
					}
				}
			}
			for(int j = 2; j < n; ++j) {
				if(i & (1 << (j - 2))) continue;
				for(int t: a[j]) if((h[t] == i || l[t] == 1) && (l[t] + f[t] != 2) && vis[t] != i) {
					tmp++;
					vis[t] = i;
				}
			}
			if(i == 0 || tmp < ans) ans = tmp;
		}
		printf("Case #%d: %d\n", ks, ans);
	}
	return 0;
}

