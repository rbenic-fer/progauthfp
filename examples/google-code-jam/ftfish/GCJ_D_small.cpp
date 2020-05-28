#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

const int ml = 200, mn = 1005, mm = 10;
char s[mn][ml];
int num_of_nodes (int n, int *a) {
	set<string> v;
	for (int i=0;i<n;++i) {
		int l = strlen(s[a[i]]);
		for (int j=0;j<=l;++j) {
			v.insert(string(s[a[i]], s[a[i]]+j));
		}
	}
	return v.size();
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;++i) {
			scanf("%s", s[i]);
		}

		int total = int(pow(m, n) + 0.5);
		int seq[mm] = {};
		int num[mm];
		int a[mm][mn];

		int cnt_nodes = -1;
		int cnt_num_sol = 0;

		for(int i=0;i<total;++i) {
			for(int j=0, t=i;j<n;++j) {
				seq[j] = t % m;
				t /= m;
			}
			int cnt = 0;
			for (int j=0;j<m;++j) {
				num[j] = 0;
				for(int k=0;k<n;++k) {
					if (seq[k] == j) {
						a[j][num[j]] = k;
						num[j]++;
					}
				}
				cnt += num_of_nodes(num[j], a[j]);
			}
			if (cnt_nodes == -1 || cnt > cnt_nodes) {
				cnt_nodes = cnt;
				cnt_num_sol = 1;
			} else if (cnt == cnt_nodes) {
				cnt_num_sol++;
			}


		}



		printf("Case #%d: ", Tc);
		printf("%d %d\n", cnt_nodes, cnt_num_sol);
	}
	return 0;
}
