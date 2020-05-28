#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int solve(int N, vector<string> *v) {
	int ans = (1<<29);
	map<string, int> dic;
	int count = 0;
	vector<int> w[210];
	for (int j = 0; j < N; j++) {
		for (auto &s: v[j]) {
			auto it = dic.find(s);
			if (it == dic.end()) {
				dic[s] = count++;
			}
		}
	}
	for (int j = 0; j < N; j++) {
		w[j].resize(count/32+1);
		for (auto &s: v[j]) {
			int b = dic[s];
			w[j][b/32] |= (1 << (b%32));
		}
	}
	for (int i = 2; i < (1<<N); i+= 4) {
		vector<int> english(count/32+1);
		vector<int> french(count/32+1);
		for (int j = 0; j < N; j++) {
			if (i&(1<<j)) {
				for (int k = 0; k < count/32+1; k++) {
					french[k] |= w[j][k];
				}
			} else {
				for (int k = 0; k < count/32+1; k++) {
					english[k] |= w[j][k];
				}
			}
		}
		int cc = 0;
		for (int k = 0; k < count/32+1; k++) {
			cc += __builtin_popcount(french[k] & english[k]);
		}
		ans = min(ans, cc);
	}
	return ans;
}

int main()
{
	int T;
	char s[10100];
	fgets(s, sizeof(s), stdin);
	sscanf(s, "%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		fgets(s, sizeof(s), stdin);
		sscanf(s, "%d", &N);
		vector<string> v[210];
		for (int i = 0; i < N; i++) {
			fgets(s, sizeof(s), stdin);
			char *p = strtok(s, " ");
			while (p != NULL) {
				v[i].push_back(p);
				p = strtok(NULL, " ");
			}
		}
		int ans = solve(N, v);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
