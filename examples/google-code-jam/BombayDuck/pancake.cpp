#include <iostream>
#include <cmath>

using namespace std;

int reqtime(int n)
{
	cout << "n = " << n << endl;
	switch(n)
	{
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
	}

	int remain = n % int(ceil(sqrt(n)));
	int factor = n / int(ceil(sqrt(n)));
	int retvalue;
	if(remain > 0)
	{
		retvalue = ceil(sqrt(n)) + factor;
	}
	else
	{
		retvalue = ceil(sqrt(n)) + (factor - 1);
	}

	if( n <= retvalue)
	{
		return n;
	}

	return retvalue;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int d;
		cin >> d;
		int *pcake =  new int[d];
		int sum = 0;
		int initmax = 0;
		for(int j = 0; j < d; j++)
		{
			cin >> pcake[j];
			sum += pcake[j];
			if(pcake[j] > initmax)
			{
				initmax = pcake[j];
			}
//			cout << pcake[j] << " ";
		}

//		cout << endl;

		int reqavg = int(ceil(sqrt(sum)));
//		cout << "reqavg = " << reqavg << endl;

		int split = 0;
		for(int j = 0; j < d; j++)
		{
			if(pcake[j] > reqavg)
			{
				int remain = pcake[j] % reqavg;
				int factor = pcake[j] / reqavg;
				if(remain > 0)
				{
					pcake[j] = int(ceil((pcake[j] / (factor + 1.0))));
//					cout << pcake[j] << endl;
					split += factor;

				}
				else
				{
					pcake[j] = reqavg;
					split += (factor - 1);
				}
			}
		}

		int max = pcake[0];
		for(int j = 1; j < d; j++)
		{
			if(pcake[j] > max)
			{
				max = pcake[j];
			}
		}

//		cout << "max = " << max << "\tsplit = " << split << endl;
		cout << "Case #" << (i + 1) << ": ";
		if((max + split) > initmax)
		{
			cout << initmax << endl;
		}
		else
		{
			cout << (max + split) << endl;
		}
		delete[] pcake;
	}

	return 0;
}
