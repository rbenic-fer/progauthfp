//============================================================================
// Name        : Lawnmower.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int> > grid(N, vector<int>(M));
		vector<vector<int> > gridInv(M, vector<int>(N));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				int n;
				cin >> n;
				grid[i][j] = n;
				gridInv[j][i] = n;
			}
		}

		vector<int> maxRow(N, 0);
		vector<int> maxCol(M, 0);
		for (int i = 0; i < N; ++i)
			maxRow[i] = *max_element(grid[i].begin(), grid[i].end());
		for (int i = 0; i < M; ++i)
			maxCol[i] = *max_element(gridInv[i].begin(), gridInv[i].end());

		//for (int i = 0; i < N; ++i)
		//	cout << maxRow[i] << endl;
		//for (int i = 0; i < M; ++i)
		//	cout << maxCol[i] << endl;


		bool works = true;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (grid[i][j] < maxRow[i] && grid[i][j] < maxCol[j])
					works = false;
			}
		}

		if (works)
			cout << "Case #" << caseNum << ": YES" << endl;
		else
			cout << "Case #" << caseNum << ": NO" << endl;
	}
}
