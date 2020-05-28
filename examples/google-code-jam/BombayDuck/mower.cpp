#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n;
		cin >> m;
		
		int *array = new int[n * m];

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> array[j * m + k];
//				cout << array[j * m + k] << " ";
			}
//			cout << endl;
		}

		bool flag = true;
		if (n > 1 && m > 1)
		{
			int *column = new int[n];
			int *row = new int[m];

			for (int j = 0; j < n; j++)
			{
				column[j] = array[j * m];
			}
			
			for (int k = 0; k < m; k++)
			{
				row[k] = array[k];
			}
			
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (array[j * m + k] > column[j])
					{
						column[j] = array[j * m + k];
					}
					if (array[j * m + k] > row[k])
					{
						row[k] = array[j * m + k];
					}
				}
			}

			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (array[j * m + k] < column[j] &&
							array[j * m + k] < row[k])
					{
						flag = false;
						break;
					}
				}
				if (!flag)
				{
					break;
				}
			}
			delete[] row;
			delete[] column;
		}
		cout << "Case #" << (i + 1) << ": ";
		if (flag)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
		delete[] array;
		
	}

	return 0;
}
