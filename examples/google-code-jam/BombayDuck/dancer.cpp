#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int n = 0;
		int s = 0;
		int p = 0;
		int count = 0;

		cin >> n;
//		cout << "n = " << n << endl;
		cin >> s;
//		cout << "s = " << s << endl;
		cin >> p;
//		cout << "p = " << p << endl;

		for(int j = 0; j < n; j++)
		{
			int data = 0;
			cin >> data;
			if(((3*p - data) == 2 && data >= 1) || ((3*p - data) == 1 && data >= 2) || ((3*p - data) <= 0))
			{
				count++;
			}
			else if(((3*p - data) == 3 || (3*p - data) == 4) && (s > 0) && (data >= 2))
			{
				s--;
				count++;
			}
		}
		cout << "Case #" << (i + 1) << ": " << count << endl;
	}

	return 0;
}
