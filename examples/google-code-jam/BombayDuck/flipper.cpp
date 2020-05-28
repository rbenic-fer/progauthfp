#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		string s;
		int k;
		cin >> s;
		cin >> k;
		int count = 0;

		for(int j = 0; j <= s.length() - k; j++)
		{
			if(s[j] == '-')
			{
				// flip k pancakes
				for(int a = 0; a < k; a++)
				{
					if(s[j + a] == '-')
					{
						s[j + a] = '+';
					}
					else
					{
						s[j + a] = '-';
					}
				}
				count++;
			}
		}

		bool possible = true;
		for(int j = 0; j < k; j++)
		{
			if(s[s.length() - j] == '-')
			{
				possible = false;
				break;
			}
		}

//		cout << "string: " << s << " " << k << endl;

		cout << "Case #" << (i + 1) << ": ";
		if(possible)
		{
			cout << count;
		}
		else
		{
			cout << "IMPOSSIBLE";
		}
		cout << endl;
	}

	return 0;
}
