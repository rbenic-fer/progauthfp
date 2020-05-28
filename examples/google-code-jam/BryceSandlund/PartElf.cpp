//============================================================================
// Name        :
// Author      : Bryce Sandlund
// Version     :
// Copyright   :
// Description : Google Code Jam Code
//============================================================================
#define _USE_MATH_DEFINES

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
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <ctgmath>

using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}

	if (b > a)
	{
		return gcd(b, a);
	}

	return gcd(a%b, b);
}

int main() {
	ofstream out;
	ifstream in("in.in");
	out.open("out.out");
	int T;
	in >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		string frac;
		in >> frac;
		int P, Q;
		sscanf(frac.c_str(), "%d/%d", &P, &Q);

		int d = gcd(P, Q);
		P = P / d;
		Q = Q / d;

		bool worked = true;
		int check = Q;
		while (check != 1)
		{
			if (check % 2 != 0)
			{
				worked = false;
				break;
			}

			check /= 2;
		}


		int doubles = 0;
		if (worked)
		{
			while (P / Q < 1)
			{
				Q /= 2;
				++doubles;
			}
		}

		if (worked)
		{
			out << "Case #" << caseNum << ": " << doubles << endl;
		}
		else
		{
			out << "Case #" << caseNum << ": " << "impossible" << endl;
		}
	}
	out.close();
	return 0;
}
