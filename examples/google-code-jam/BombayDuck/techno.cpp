#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		int number;
		cin >> number;
		string *first = new string[number];
		string *second = new string[number];

		for(int j = 0; j < number; j++)
		{
			cin >> first[j];
			cin >> second[j];
			//cout << first[j] << " " << second[j] << endl;
		}

		int repeat = 0;
		for(int j = 0; j < number; j++)
		{
			bool first_found = false, second_found = false;
			for(int k = 0; k < number; k++)
			{
				if(j == k || first[k].compare("") == 0)
				{
					continue;
				}
				if(first[j].compare(first[k]) == 0)
				{
					first_found = true;
					break;
				}
			}
			for(int k = 0; k < number; k++)
			{
				if(j == k || second[k].compare("") == 0)
				{
					continue;
				}
				if(second[j].compare(second[k]) == 0)
				{
					second_found = true;
					break;
				}
			}
			if(first_found && second_found)
			{
				repeat++;
				first[j] = "";
				second[j] = "";
			}
		}

		cout << "Case #" << (i + 1) << ": " << repeat << endl;
			
	}

	return 0;
}
