#include <iostream>

using namespace std;
int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		long long int initial, last = 0;
		cin >> initial;
		// cout << initial << endl;

		if(initial == 0)
		{
			cout << "Case #" << (i + 1) << ": INSOMNIA" << endl;
		}
		else
		{
			int count[10];
			for(int j = 0; j < 10; j++)
			{
				count[j] = 0;
			}
			while(1)
			{
				last += initial;
				// cout << last << endl;
				for(long long int number = last; number > 0; number /= 10)
				{
					count[number % 10] = 1;
				}

				int digits = 0;
				for(int j = 0; j < 10; j++)
				{
					if(count[j])
					{
						digits++;
					}
				}
				if(digits == 10)
				{
					break;
				}
			}

			cout << "Case #" << (i + 1) << ": " << last << endl;
		}
	}
	return 0;
}
