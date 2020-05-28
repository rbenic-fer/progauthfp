#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

long long int is_prime(long long int value)
{
	long long int divisor = 2;
	if(value % 2 == 0)
	{
		return 2;
	}
	for(divisor = 3; divisor <= sqrt(value); divisor += 2)
	{
		if(value % divisor == 0)
		{
			return divisor;
		}
	}
	return 1;
}

int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		int length, limit;
		cin >> length;
		cin >> limit;

		cout << "Case #" << (i + 1) << ":" << endl;

		int count = 0;
		for(long long int j = 0; count < limit; j++)
		{
			string jamcoin;
			string buffer;
			stringstream out;
			bitset<64> temp = j;
			out << temp;
			jamcoin = "1";
			buffer = out.str();
			jamcoin += buffer.substr((buffer.length() - length + 2));
			jamcoin += '1';
//			cout << jamcoin << endl;
			int non_prime_count = 0;
			long long int divisors[11];
			for(int k = 2; k <= 10; k++, non_prime_count++)
			{
				long long int value;
				value = strtol(&jamcoin[0], NULL, k); 
				divisors[k] = is_prime(value);
				if(divisors[k] == 1)
				{
					break;
				}
			}

			if(non_prime_count == 9)
			{
				cout << jamcoin;
				for(int k = 2; k <= 10; k++)
				{
//					long long int value;
//					value = strtol(&jamcoin[0], NULL, k); 
//					cout << endl;
//					cout << value << " ";
					cout << " " << divisors[k];
				}
				cout << endl;
				count++;
			}
		}
	}
	return 0;
}
