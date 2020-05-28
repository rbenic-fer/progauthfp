// Google Code Jam 2016
// Qualifying Round
// Problem C - Coin Jam

#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#define INPUT_FILE "C-small-attempt2.in"
#define OUTPUT_FILE "C-small-attempt2.out"

using namespace std;

int T, N, J;

long long ConvertToBase(string& s, int base)
{
	long long ret = 0;
	long long pow = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '1')
			ret += pow;
		pow *= (long long)base;
	}

	return ret;
}

long long Prime(long long n)
{
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return i;
	return -1;
}

bool Check(int n)
{
	int bn = n, pos = N - 2;
	string s(N, '0'); // N bits of 0

	while (bn > 0)
	{
		s[pos--] = '0' + (bn % 2);
		bn /= 2;
	}
	s[0] = s[N - 1] = '1';
	//printf("%d -> %s\n", n, s.c_str());

	vector<long long> factors;
	for (int i = 2; i <= 10; ++i)
	{
		//printf("%s in base %d is %lld\n", s.c_str(), i, ConvertToBase(s, i));
		long long base_i = ConvertToBase(s, i);
		long long factor = Prime(base_i);

		if (factor == -1)
			return false;
		factors.push_back(factor);
	}

	// found one N-bit jamcoin
	printf("%s", s.c_str());
	for (int i = 0; i < factors.size(); ++i)
		printf(" %lld", factors[i]);
	printf("\n");

	return true;
}

void Solve()
{
	scanf("%d %d", &N, &J);
	
	// generate random numbers with N-bits
	int cnt = 0;
	int nmax = (1 << N - 2) - 1;
	for (int nr = 0; nr <= nmax; ++nr)
	{
		if (Check(nr))
		{
			++cnt;
			if (cnt == J) 
				break;
		}
	}
}

int main()
{
    freopen(INPUT_FILE, "rt", stdin);
    freopen(OUTPUT_FILE, "wt", stdout);
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        printf("Case #%d:\n", i);
        Solve();
    }
   
   return 0;
}

