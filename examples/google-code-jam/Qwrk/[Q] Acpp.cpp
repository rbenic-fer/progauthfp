#include <iostream>

int main()
{
	int T;
	std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		int S, sum = 0, friends = 0;
		char temp;
		std::cin >> S >> temp;
		sum = static_cast<int>(temp - '0');
		for (int i = 1; i <= S; ++i) {
			char temp;
			std::cin >> temp;
			int s = static_cast<int>(temp - '0');
			if (sum < i) {
				friends += i - sum;
				sum = i;
			}
			sum += s;
		}
		std::cout << "Case #" << c << ": " << friends << '\n';
	}
	
	return 0;
}