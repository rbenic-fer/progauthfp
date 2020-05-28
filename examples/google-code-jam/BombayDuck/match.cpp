#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count;
	cin >> count;
	for(int i = 0; i < count; i++)
	{
		string coder, jammer;
		cin >> coder;
		cin >> jammer;

		int flag = 0;
		for(int j = 0; j < coder.length(); j++)
		{
			if(flag == 0)
			{
				if(coder[j] == '?')
				{
					if(jammer[j] == '?')
					{
						coder[j] = '0';
						jammer[j] = '0';
					} 
					else 
					{
						coder[j] = jammer[j];
					}
				} 
				else 
				{
					if(jammer[j] == '?')
					{
						jammer[j] = coder[j];
					}
				}
			}
			else if(flag < 0)
			{
				if(coder[j] == '?')
				{
					coder[j] = '9';
				}
				if(jammer[j] == '?')
				{
					jammer[j] = '0';
				}
			} 
			else
			{
				if(coder[j] == '?')
				{
					coder[j] = '0';
				}
				if(jammer[j] == '?')
				{
					jammer[j] = '9';
				}
			}

			flag = 10 * flag + coder[j] - jammer[j];
		}	
		cout << "Case #" << (i + 1) << ": " << coder << " " << jammer << endl;
	}
	return 0;
}
