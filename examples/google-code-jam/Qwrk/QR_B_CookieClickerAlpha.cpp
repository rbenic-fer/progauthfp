#include <iostream>


int main()
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(7);

	int T;
	std::cin >> T;
	double C, F, X;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> C >> F >> X;
		double current = 2.0, cookies = 0;
		double bestTime = X / current;
		double farmTime = C / current;
		double tillWin = X / (current + F);
		while (farmTime + tillWin < bestTime) {
			bestTime = farmTime + tillWin;
			current += F;
			farmTime = farmTime + C / current;
			tillWin = X / (current + F);
		}
		std::cout << "Case #" << cases << ": " << bestTime << '\n';
	}
	return 0;
}
