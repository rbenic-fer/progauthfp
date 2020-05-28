#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

#define  FOR(i,a,b)		for(int i=(a); i<(b); ++i)
#define  REP(i,a)		FOR(i,0,a)
#define FORN(i,a)		FOR(i,1,(a)+1)
#define FORD(i,a,b)    	for(int i(a-1);i>=b;--i)

typedef long long int iLong;
typedef vector<int> iVec;
typedef pair<int,int> iiPair;

int rint() { int x; scanf("%d", &x); return x;}
long long int rLL() { long long int x; scanf("%lld", &x); return x;}

string A[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
std::map<char, int> cnt;

void delWord(int w, int k)
{
	REP(i, A[w].size()) {
		cnt[A[w][i]]-=k;
	}
}
void addWord(int w, int k)
{
	REP(i, A[w].size()) {
		cnt[A[w][i]]+=k;
	}
}

int hasWord(int w) {
	int mn = -1;
	// printf("size of %d: %d\n", w, A[w].size());
	REP(i, A[w].size()) {
		if (mn == -1 || mn > cnt[A[w][i]]) {
			mn = cnt[A[w][i]];
			// printf("for %c, %d: mn: %d\n", A[w][i], w, mn);
		}
	}
			// printf("final %d: mn: %d\n", w, mn);
	return mn;
}

bool solve(std::vector<char> &s) {
	int left = 0; for(char c = 'A'; c<='Z'; c++) left += cnt[c];
	if (left == 0) return true;
	REP(i, 10) {
		int k = hasWord(i);
		if (k > 0) {
			// printf("Trying %d, k:%d, left: %d\n", i, k, left);
			delWord(i,k);
			bool ans = solve(s);
			if (ans) {
				REP(j, k)
					s.push_back('0'+i);
				// printf("left: %d, s: %s\n", left, string(s.begin(), s.end()).c_str());
				return true;
			}
			addWord(i,k);
		}
	}
	return false;
}

char s[2001];

int main() {
	int T = rint();
	FORN(t, T)
	{
		scanf("%s", s);
		cnt.clear();
		int n = strlen(s);
		REP(i, n) cnt[s[i]]++;
		std::vector<char> ans;
		solve(ans);
		sort(ans.begin(), ans.end());
		string a(ans.begin(), ans.end());
		printf("Case #%d: %s\n", t, a.c_str());
	}
	return 0;
}