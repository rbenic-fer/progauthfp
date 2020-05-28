#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef map<pair<char, char>, char> combine_t;
typedef set<pair<char, char> > opposed_t;
combine_t combine;
opposed_t opposed;

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		combine.clear();
		opposed.clear();
		int C;
		scanf("%d", &C);
		for (int j = 0; j < C; j++) {
			char ss[10];
			scanf("%s", ss);
			combine.insert(make_pair(make_pair(ss[0], ss[1]), ss[2]));
			combine.insert(make_pair(make_pair(ss[1], ss[0]), ss[2]));
		}
		int D;
		scanf("%d", &D);
		for (int j = 0; j < D; j++) {
			char ss[10];
			scanf("%s", ss);
			opposed.insert(make_pair(ss[0], ss[1]));
			opposed.insert(make_pair(ss[1], ss[0]));
		}
		int N;
		scanf("%d", &N);
		char in[120];
		scanf("%s", in);
		char out[120];
		int len = 0;
		for (int j = 0; j < N; j++) {
			if (len > 0) {
				combine_t::iterator k =
					combine.find(make_pair(in[j], out[len-1]));
				if (k != combine.end()) {
					out[len-1] = k->second;
					continue;
				}
			}
			for (int k = 0; k < len; k++) {
				if (opposed.find(make_pair(in[j], out[k])) != opposed.end()) {
					len = 0;
					goto NEXT;
				}
			}
			out[len++] = in[j];
		NEXT:
			;
		}
		printf("Case #%d: [", i+1);
		const char *comma = "";
		for (int j = 0; j < len; j++) {
			printf("%s%c", comma, out[j]);
			comma = ", ";
		}
		printf("]\n");
	}
}
