#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i;

	int l, d, n;

	cin >> l >> d >> n;

	string words[d];

	for( int i = 0; i < d; i++ )
	{
		cin >> words[i];
	}

#if 0
	for( int i = 0; i < d; i++ )
	{
		cout << words[i] << endl;
	}
#endif

	for( int a = 0; a < n; a++ )
	{
		bool map[d][l];

		for( int i = 0; i < d; i++ )
		{
			for( int j = 0; j < l; j++ )
			{
				map[i][j] = false;
			}
		}

		string pattern;
		cin >> pattern;
//		cout << "pattern : " << pattern << endl;
		bool flag = false;
		for( int i = 0, j = 0; i < pattern.length() && j < l; i++ )
		{
			switch( pattern[i] )
			{
				case '(':
					flag = true;
					break;
				case ')':
					flag = false;
					break;
				default:
					for( int k = 0; k < d; k++ )
					{
						if( words[k][j] == pattern[i] )
						{
							map[k][j] = true;
						}
					}
					break;
			}

			if( flag == false )
			{
				j++;
			}
		}

		int count = 0;
		for( int i = 0; i < d; i++ )
		{
			bool isThere = true;
			for( int j = 0; j < l; j++ )
			{
				if( map[i][j] == false )
				{
					isThere = false;
					break;
				}
			}

			if(isThere)
			{
				count++;
			}
		}

		cout << "Case #" << a+1 << ": " << count << endl;


	}

	return 0;
}
