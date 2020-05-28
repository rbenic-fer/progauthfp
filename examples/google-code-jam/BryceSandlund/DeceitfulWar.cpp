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
//#include <unordered_set>
//#include <unordered_map>
//#include <ctgmath>

#define INF 1000000000000000000LL

using namespace std;

typedef pair<int, pair<int, int> > iii;

int main() {
	ofstream out;
	out.open("out.out");
	ifstream in("in.in");
	int T;
	in >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		int N;
		in >> N;
		vector<double> naomi(N), ken(N);

		for (int i = 0; i < N; ++i)
		{
			in >> naomi[i];
		}

		for (int i = 0; i < N; ++i)
		{
			in >> ken[i];
		}

		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());

		int nC = 0, kC = 0;
		int optimal = 0;
		for (; nC < N; ++nC)
		{
			if (naomi[nC] > ken[kC])
			{
				++optimal;
				++kC;
			}
		}

		nC = N-1;
		kC = N-1;

		int truth = 0;
		for (; nC >= 0; --nC)
		{
			if (naomi[nC] > ken[kC])
			{
				++truth;
			}
			else
			{
				--kC;
			}
		}

		out << "Case #" << caseNum << ": " << optimal << " " << truth << endl;
	}
	out.close();
	return 0;
}
