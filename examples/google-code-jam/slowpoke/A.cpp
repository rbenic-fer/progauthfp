#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <array>
#include <string>
#include <deque>
#include <list>
#include <numeric>
#include <limits>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <assert.h>

using namespace std;

int R, C;
vector<string> g;

void comp(int tc){
	cin >> R >> C;
	g.resize(R);
	for (auto &s : g){
		cin >> s;
	}

	cout << "Case #" << tc << ": ";
	{
		vector<int> rows(R), cols(C);

		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				if (g[i][j] != '.'){
					rows[i]++;
					cols[j]++;
				}
			}
		}

		for (int i = 0; i < R; ++i){
			if (rows[i] == 1)
			{
				for (int j = 0; j < C; ++j){
					if (g[i][j] != '.' && cols[j] == 1){
						cout << "IMPOSSIBLE" << endl;
						return;
					}
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			int a, b;
			char c = g[i][j];
			if (c == '.')
				continue;

			if (c == 'v'){
				a = 1, b = 0;
			}
			else if (c == '<'){
				a = 0, b = -1;
			}
			else if (c == '^'){
				a = -1, b = 0;
			}
			else{
				a = 0, b = 1;
			}

			int ni = i + a, nj = j + b;
			bool found = false;
			while (ni >= 0 && nj >= 0 && ni < R && nj < C){
				if (g[ni][nj] != '.'){
					found = true;
					break;
				}
				ni += a;
				nj += b;
			}

			if (!found)
				++cnt;
		}
	}
	
	cout << cnt << endl;
	
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}