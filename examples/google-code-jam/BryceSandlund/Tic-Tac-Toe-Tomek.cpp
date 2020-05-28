//============================================================================
// Name        : Tic-Tac-Toe-Tomek.cpp
// Author      : 
// Version     :
// Copyright   : Oour copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		char grid[4][4];
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				cin >> grid[j][k];
			}
		}

		bool Xwon = false, Owon = false;
		for (int j = 0; j < 4; ++j)
		{
			int Xcount = 0;
			int Ocount = 0;
			for (int k = 0; k < 4; ++k)
			{
				if (grid[j][k] == 'X' || grid[j][k] == 'T')
				{
					++Xcount;
				}
				else if (grid[j][k] == 'O' || grid[j][k] == 'T')
				{
					++Ocount;
				}
			}
			if (Xcount >= 4)
			{
				Xwon = true;
			}
			if (Ocount >= 4)
			{
				Owon = true;
			}
		}

		for (int j = 0; j < 4; ++j)
		{
			int Xcount = 0;
			int Ocount = 0;
			for (int k = 0; k < 4; ++k)
			{
				if (grid[k][j] == 'X' || grid[k][j] == 'T')
				{
					++Xcount;
				}
				else if (grid[k][j] == 'O' || grid[k][j] == 'T')
				{
					++Ocount;
				}
			}
			if (Xcount >= 4)
			{
				Xwon = true;
			}
			if (Ocount >= 4)
			{
				Owon = true;
			}
		}

		int Xcount = 0;
		int Ocount = 0;
		for (int row = 0, col = 0; row < 4 && col < 4; ++row, ++col)
		{
			if (grid[row][col] == 'T')
			{
				++Xcount;
				++Ocount;
			}
			else if (grid[row][col] == 'X')
			{
				++Xcount;
			}
			else if (grid[row][col] == 'O')
				++Ocount;
		}
		if (Xcount >= 4)
		{
			Xwon = true;
		}
		if (Ocount >= 4)
		{
			Owon = true;
		}

		Xcount = 0;
		Ocount = 0;
		for (int row = 0, col = 3; row < 4 && col >= 0; ++row, --col)
		{
			if (grid[row][col] == 'T')
			{
				++Xcount;
				++Ocount;
			}
			else if (grid[row][col] == 'X')
			{
				++Xcount;
			}
			else if (grid[row][col] == 'O')
				++Ocount;
		}
		if (Xcount >= 4)
		{
			Xwon = true;
		}
		if (Ocount >= 4)
		{
			Owon = true;
		}

		bool completed = true;
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (grid[j][k] == '.')
					completed = false;
			}
		}

		if (Xwon)
		{
			cout << "Case #" << (i + 1) << ": X won" << endl;
		}
		else if (Owon)
		{
			cout << "Case #" << (i + 1) << ": O won" << endl;
		}
		else if (!completed)
		{
			cout << "Case #" << (i + 1) << ": Game has not completed" << endl;
		}
		else
		{
			cout << "Case #" << (i + 1) << ": Draw" << endl;
		}
	}
}
