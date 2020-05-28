#include <iostream>
#include <vector>


int T, S, p, N;
std::vector<int> t;


int main()
{
	std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		std::cin >> N >> S >> p;
		t.clear(); t.resize (N);
		for (int i = 0; i < N; ++i) {
			std::cin >> t[i];
		}
		// --- --- --- --- --- ---

		int res = 0;
		for (int i = 0; i < t.size(); ++i) {
			int tmp = t[i] - p;
			if (t[i] == 0) {
				if (p == 0) ++res;
			} else if (t[i] >= p * 3) {
				++res;
			} else if (tmp >= p * 2 - 2) {
				++res;
			} else if (S > 0 && tmp >= p * 2 - 4) {
				--S; ++res;
			}
			//std::cout << "Googler #" << i + 1 << ": S == " << S << " | Res = " << res << '\n';
		}

		std::cout << "Case #" << c << ": " << res << '\n';
		// --- --- --- --- --- ---
	}

	return 0;
}