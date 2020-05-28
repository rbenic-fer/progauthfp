#include<cstdio>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;

int main() {
	int C;
	scanf("%d", &C);
	for (int t=1; t<=C; t++) {
		int N, K, B, TT;
		scanf("%d%d%d%d", &N, &K, &B, &TT);
		vector<ll> X(N), V(N);	
		for (int i=0; i<N; i++)
			scanf("%d", &X[i]);
		for (int i=0; i<N; i++)
			scanf("%d", &V[i]);
		int can_pass = 0;
		for (int i=0; i<N; i++) {		
			can_pass += (B-X[i])<=TT*V[i];
		}
		if (can_pass < K)
			printf("Case #%d: IMPOSSIBLE\n", t);
		else {
			int passed = 0, res=0;
			for (int i=N-1; i>=0 && passed < K; i--)
				if ((B-X[i]>TT*V[i])) {
					res += K-passed;
				} else
					passed++;
			printf("Case #%d: %d\n", t, res);
		}
	}
	return 0;
}