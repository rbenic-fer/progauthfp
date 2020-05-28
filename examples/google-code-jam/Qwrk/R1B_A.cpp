#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>


int op_needed (int _sA, int _sE, int _sN)
{
	int result = 0; int pow = 1;
	int cv = (_sN - _sA + _sE) / _sE;
	while (pow <= cv) {
		pow *= 2; ++result;
	}
	return result;
}

int solve (int _sA, std::vector<int> &_rest, int _iS, int _iE, int _op)
{
	while (_iS < _iE && _sA > _rest[_iS]) {
		_sA += _rest[_iS++];
	}
	if (_iS >= _iE) {
		return _op;
	} else if (_sA <= _rest[_iS]) {
		//int opn = op_needed (_sA, _rest[_iS], _rest[_iE]);
		if (_sA == 1) {
			return _iE - _iS;
		}
		int r1 = solve (_sA + _sA - 1, _rest, _iS, _iE, _op + 1);
		int r2 = solve (_sA, _rest, _iS + 1, _iE, _op + 1);
		return std::min (r1, r2);
	}
	return _op;
}


int main()
{
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int A, N;
		std::cin >> A >> N;
		std::vector<int> s (N);
		for (int i = 0; i < N; ++i) {
			std::cin >> s[i];
		}
		std::sort (s.begin(), s.end());
		int result = solve (A, s, 0, s.size(), 0);
		std::cout << "Case #" << t << ": " << result << '\n';
	}

	return 0;
}