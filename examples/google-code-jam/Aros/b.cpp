#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 1000;
const int MAXN = MAX+5;
int T, D, P[MAXN];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("put.out", "w", stdout);
	cin>>T;
	for (int cas = 1; cas <= T; cas++) {
		cin>>D;
		multiset<int, greater<int> > st;
		for (int i = 1; i <= D; i++) {
			cin>>P[i];
			st.insert(P[i]);
		}
		int ans = MAX, special = 0;
		while (true) {
			multiset<int, greater<int> >::iterator it = st.begin();
			int maxi = *it;
			ans = min(ans, maxi+special);
			if (maxi == 1)
				break;
			st.erase(it);
			int a = maxi/2, b = maxi-a;
			st.insert(a);
			st.insert(b);
			special++;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
