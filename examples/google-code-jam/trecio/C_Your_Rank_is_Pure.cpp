#include<algorithm>
#include<cstdio>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

const int MAXN=501;
const int SSIZE=MAXN;
int cache[MAXN];
int buf[MAXN];
int ranks[MAXN];

int bi[MAXN][MAXN];
const int M = 100003;

void init_bi(){
	for (int i=0; i<MAXN; i++) 
		bi[i][0] = bi[i][i] = 1;
	for (int n=1; n<MAXN; n++)
		for (int k=1; k<n; k++)
			bi[n][k] = (bi[n-1][k-1]+bi[n-1][k])%M;
}

int binom(int n, int k) {
	if (n>=k) return bi[n][k];
	return 0;
}

int dp[MAXN][MAXN];

void init_dp() {
	for (int x=2; x<MAXN; x++)
		dp[1][x] = dp[x-1][x] = 1;
	for (int n=2; n<MAXN; n++)
		for (int x=n+2; x<MAXN; x++) 
			for (int i=1; i<n; i++)
				dp[n][x] = (dp[n][x] + dp[i][n]*binom(x-n-1, n-i-1))%M;		
}

void init_cache() {
	for (int i=2; i<MAXN; i++)
		for (int n=1; n<i; n++)
			cache[i] = (cache[i] + dp[n][i])%M;
}

int main() {
	int T;
	scanf("%d", &T);
	init_bi();
	init_dp();
	init_cache();
	for (int t=1; t<=T; t++) {
		int n; 
		scanf("%d", &n);
		printf("Case #%d: %d\n", t, cache[n]%100003);
	}
	return 0;
}