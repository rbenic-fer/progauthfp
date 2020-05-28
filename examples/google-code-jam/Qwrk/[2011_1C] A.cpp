#include <iostream>
#include <string>

#define Odp(x) std::cout << "Case #" << x << ":\n"
int C, N, M;
std::string *map;

int main()
{
	std::cin >> C;
	for (int Cs = 1; Cs <= C; ++Cs) {
		std::cin >> N >> M;
		map = new std::string[N];
		for (int i = 0; i < N; ++i) {
			map[i].resize (M);
			for (int j = 0; j < M; ++j)
				std::cin >> map[i][j];
		}

		bool end = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (i == N - 1 || j == M - 1) continue;
				if (map[i][j] == '#' && map[i][j+1] == '#' &&
					map[i+1][j] == '#' && map[i+1][j+1] == '#') {
					map[i][j] = '/'; map[i][j+1] = '\\';
					map[i+1][j] = '\\'; map[i+1][j+1] = '/';
				}
			}
		}

		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < M; ++j) 
				if (map[i][j] == '#')
					end = true;

		Odp (Cs);
		if (end) std::cout << "Impossible\n";
		else {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j)
					std::cout << map[i][j];
				std::cout << '\n';
			}
		}
	}
}