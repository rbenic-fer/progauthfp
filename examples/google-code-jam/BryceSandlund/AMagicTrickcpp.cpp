//============================================================================
// Name        :
// Author      : Bryce Sandlund
// Version     :
// Copyright   :
// Description : Google Code Jam Code
//============================================================================

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <list>
#include <map>
#include <fstream>
#include <string>
#include <time.h>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
//#include <ctgmath>

#define INF 1000000000000000000LL

using namespace std;

typedef pair<int, pair<int, int> > iii;

int main() {
	ofstream out;
	out.open("A-small-attempt1.out");
	ifstream in("A-small-attempt1.in");
	int T;
	in >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		int firstGuess, secondGuess;
		in >> firstGuess;

		vector<vector<int> > gridOne(4, vector<int>(4)), gridTwo(4, vector<int>(4));
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				in >> gridOne[i][j];
			}
		}

		in >> secondGuess;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				in >> gridTwo[i][j];
			}
		}

		unordered_set<int> firstRow;

		for (int i = 0; i < 4; ++i)
		{
			firstRow.insert(gridOne[firstGuess-1][i]);
		}

		vector<int> intersection;
		for (int i = 0; i < 4; ++i)
		{
			if (firstRow.count(gridTwo[secondGuess - 1][i]))
			{
				intersection.push_back(gridTwo[secondGuess - 1][i]);
			}
		}

		out << "Case #" << caseNum << ": ";
		if (intersection.size() == 1)
		{
			out << intersection[0] << endl;
		}
		else if (intersection.size() == 0)
		{
			out << "Volunteer cheated!" << endl;
		}
		else
		{
			out << "Bad magician!" << endl;
		}
	}
	out.close();
	return 0;
}
