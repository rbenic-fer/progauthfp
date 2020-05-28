#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	const string text = "welcome to code jam";
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cin.ignore(10000, '\n');
	for (int t=1; t<=n; t++) {
		string s;
		getline(cin, s);
		vector<vector<int> > dp(s.size(), vector<int>(text.size()));
		dp[0][0] = s[0] == text[0];
		for (size_t end = 1; end < s.size(); end++) {
			if (s[end] == text[0])
				dp[end][0] = 1;
			for (size_t i=1; i<text.size(); i++)
				if (s[end] == text[i])
					for (size_t j=0; j<end; j++) {
						dp[end][i] += dp[j][i-1];
						dp[end][i] %= 10000;
					}
		}
		int res = 0;
		for (size_t i=0; i<s.size(); i++) {
			res += dp[i][text.size()-1];
			res %= 10000;
		}

		cout << "Case #" << t << ": ";
		cout.width(4);
		cout.fill('0');
		cout << res << "\n";
	}
	return 0;
}