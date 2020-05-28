#include <iostream>
#include <vector>

bool Solve (int **_m, int _N, int _M)
{
	bool *bm = new bool[_N*_M];
	for (int i = 0; i < _N * _M; ++i) {
		bm[i] = false;
	}

	for (int i = 0; i < _N; ++i){
		if (_m[i][0] != 1) {
			continue;
		}
		bool end = true;
		for (int j = 1; j < _M; ++j) {
			if (_m[i][j-1] != _m[i][j]) {
				end = false;
				break;
			}
		}
		for (int j = 0; end && j < _M; ++j) {
			bm[i*_M+j] = true;
		}
	}

	for (int i = 0; i < _M; ++i){
		if (_m[0][i] != 1) {
			continue;
		}
		bool end = true;
		for (int j = 1; j < _N; ++j) {
			if (_m[j-1][i] != _m[j][i]) {
				end = false;
				break;
			}
		}
		for (int j = 0; end && j < _N; ++j) {
			bm[j*_M+i] = true;
		}
	}
	
	for (int i = 0; i < _N * _M; ++i) {
		if (bm[i] == false && _m[i/_M][i%_M] == 1) {
			return false;
		}
	}

	delete[] bm;
	
	return true;
}


int main()
{
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		int N, M;
		std::cin >> N >> M;
		int **map = new int*[N];
		for (int j = 0; j < N; ++j) {
			map[j] = new int[M];
		}
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				std::cin >> map[j][k];
			}
		}
		std::cout << "Case #" << i << ": " << (Solve (map, N, M) ? "YES\n" : "NO\n");

		for (int j = 0; j < N; ++j) {
			delete[] map[j];
		}
		delete[] map;
	}

	return 0;
}