#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int WarOptimalStrat(const std::set<double> &_Naomi, std::set<double> _Ken)
{
	int NaomiResult = 0;
	for (auto it = _Naomi.rbegin(); it != _Naomi.rend(); ++it) {
		auto kenBlock = _Ken.lower_bound(*it);
		if (kenBlock == _Ken.end()) {
			++NaomiResult;
			_Ken.erase(_Ken.begin());
		} else {
			_Ken.erase(kenBlock);
		}
	}
	return NaomiResult;
}

int DeceitfulWarOptimalStrat(std::set<double> _Naomi, std::set<double> _Ken)
{
	int NaomiResult = 0;
	while (!_Naomi.empty() && *_Naomi.rbegin() > *_Ken.begin()) {
		auto naomiBlock = _Naomi.lower_bound(*_Ken.begin());
		if (naomiBlock != _Naomi.end()) {
			++NaomiResult;
			_Ken.erase(_Ken.begin());
			_Naomi.erase(naomiBlock);
		}
	}
	return NaomiResult;
}


int main()
{
	int T, N;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> N;
		std::set<double> Naomi, Ken;
		for (int i = 0; i < N; ++i) {
			double w;
			std::cin >> w;
			Naomi.insert(w);
		}
		for (int i = 0; i < N; ++i) {
			double w;
			std::cin >> w;
			Ken.insert(w);
		}
		std::cout << "Case #" << cases << ": " << DeceitfulWarOptimalStrat(Naomi, Ken) << " " << WarOptimalStrat(Naomi, Ken) << '\n';
	}

	return 0;
}