#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>


std::vector<std::pair<char, int> > convert(const std::string &_word)
{
	std::vector<std::pair<char, int> > result;
	for (int i = 0; i < _word.size(); ++i) {
		if (result.empty()) {
			result.emplace_back(std::make_pair(_word[i], 0));
		} else {
			if (result.back().first == _word[i]) {
				++result.back().second;
			} else {
				result.emplace_back(std::make_pair(_word[i], 0));
			}
		}
	}
	return result;
}


int main()
{
	int T, N;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> N;
		std::vector<std::string> words(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> words[i];
		}
		std::vector<char> order;
		std::vector<std::vector<int> > conv;
		std::vector<int> last(N, 0);
		int result = 0;
		while (last[N-1] < words[N-1].size() && result >= 0) {
			order.push_back(words[0][last[0]]);
			conv.push_back(std::vector<int>());
			for (int i = 0; i < N; ++i) {
				int tmp = last[i];
				while (last[i] < words[i].size() && words[i][last[i]] == order.back()) {
					++last[i];
				}
				if (last[i] - tmp == 0) {
					result = -1;
					break;
				}
				conv.back().push_back(last[i] - tmp);
			}
		}
		if (result == 0) {
			for (auto &vec : conv) {
				std::sort(std::begin(vec), std::end(vec));
				int median = (N % 2 ? vec[(N-1)/2] : (vec[(N-1)/2] + vec[(N-1)/2+1]) / 2);
				for (int elem : vec) {
					result += std::abs(elem - median);
				}
			}			
			std::cout << "Case #" << cases << ": " << result << '\n';
		} else {
			std::cout << "Case #" << cases << ": Fegla Won\n";
		}
	}

	return 0;
}