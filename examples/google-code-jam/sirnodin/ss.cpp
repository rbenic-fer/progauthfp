#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <complex>
#include <math.h>

using namespace std;

typedef long long Int;

int main()
{
	
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");

	int T;
	fin>>T;

	Int P,L;
	int C;

	for(int TC = 1;TC<=T;++TC)
	{
		fin>>P>>L>>C;
		int n = 0;
		int k;
		while(P<L)
		{
			P*=C;
			++n;
		}
		--n;
		if(n==0)
			k = 0;
		else
		k = floor(log(n*1.0)/log(2.0))+1;

		fout<<"Case #"<<TC<<": "<<k<<endl;
	}

	return 0;
}