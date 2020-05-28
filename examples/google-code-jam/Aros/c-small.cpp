#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 10000+5;
/*
1, i, j, k, -1, -i, -j, -k
0, 1, 2, 3,  4,  5,  6,  7
*/
int g[4][4] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}
};
int T, L, X, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
char str[MAXN];
int main() {
	// freopen("put.in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("put.out", "w", stdout);
	cin>>T;
	for (int cas = 1; cas <= T; cas++) {
		cin>>L>>X>>str;
		int len = L*X;
		b[0] = 0; c[0] = 1;
		for (int i = 1; i <= len; i++) {
			a[i] = str[(i-1)%L]-'i'+1;
			int x = g[b[i-1]][a[i]];
			b[i] = x%4;
			c[i] = c[i-1]*(x < 4 ? 1 : -1);
			d[i] = (c[i] > 0 ? 0 : 4)+b[i];
		}
		bool flag = false;
		for (int i = 1; i <= len && !flag; i++) {
			if (d[i] == 1) {
				for (int j = i+1; j <= len && !flag; j++) {
					if (d[j] == 3) {
						if (d[len] == 4)
							flag = true;
					}
				}
			}
		}
		// cout<<flag<<endl;
		printf("Case #%d: %s\n", cas, flag ? "YES" : "NO");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
