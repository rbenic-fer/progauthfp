#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int first_non_tidy(const string& s) {
	for (unsigned int i = 1; i < s.size(); i++) {
		if (s[i] < s[i - 1])
			return i;
	}
	return s.size();
}

int count_leading(const string& s, char c) {
	for (unsigned i = 0; i < s.size(); i+=1) {
		if (s[i] != c) {
			return i;
		}
	}
	return s.size();
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1){
		long long x;
		cin >> x;
		string digits = to_string(x);
		int longest_tidy_prefix = first_non_tidy(digits);
		while (longest_tidy_prefix != digits.size()) {
			digits[longest_tidy_prefix - 1] -= 1;
			for (unsigned j = longest_tidy_prefix; j < digits.size(); j += 1) {
				digits[j] = '9';
			}
			longest_tidy_prefix = first_non_tidy(digits);
		}
		int leading_zeros = count_leading(digits, '0');
		rotate(digits.begin(), digits.begin() + leading_zeros, digits.end());
		digits.resize(digits.size() - leading_zeros);
		cout << "Case #" << t << ": " << digits << endl;
	}
	return 0;
}