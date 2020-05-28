#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int osmos(long long, int, int, vector<long long>);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long a;
		int n;
		cin >> a;
		cin >> n;
		vector<long long> arr;
		for (int j = 0; j < n; j++)
		{
			long long temp;
			cin >> temp;
			arr.push_back(temp);
		}

		int count = 0;
		if (a == 1)
		{
			count = n;
		}
		else
		{
			sort(arr.begin(), arr.end());
//			for (int j = 0; j < n; j++)
//			{
//				cout << "arr[" << j << "] = " << arr[j] << endl;
//			}
			count = osmos(a, n, 0, arr);
		}

		cout << "Case #" << (i + 1) << ": " << count << endl;

	}
	return 0;
}

int osmos(long long sum, int n, int loc, vector<long long> arr)
{
	if (loc >= n)
	{
		return 0;
	}

	if (sum > arr[loc])
	{
		sum += arr[loc];
		return osmos(sum, n, loc + 1, arr); 
	}

	if ((2 * sum - 1) > arr[loc])
	{
		sum += ((sum - 1) + arr[loc]);
		return (1 + osmos(sum, n, loc + 1, arr));
	}

	int count; 
	for(count = 0; sum <= arr[loc]; sum += (sum - 1), count++);
	sum += arr[loc];
	int remain = osmos(sum, n, loc + 1, arr);
	if ((count + remain) < (n - loc))
	{
		return (count + remain);
	}

	return (n - loc);
}
