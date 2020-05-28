#include <iostream>


int main()
{
	int A, B, K, T;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> A >> B >> K;
		int result = 0;
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				if ((i & j) < K) {
					++result;
				}
			}
		}
		std::cout << "Case #" << cases << ": " << result << '\n';
	}


	return 0;
}