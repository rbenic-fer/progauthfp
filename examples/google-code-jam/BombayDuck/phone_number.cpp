#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		string input;
		cin >> input;

		int alphabet[26];
		for(int j = 0; j < 26; j++)
		{
			alphabet[j] = 0;
		}
		for(int j = 0; j < input.length(); j++)
		{
			alphabet[input[j]-'A']++;
		}

		int digit[10];
		for(int j = 0; j < 10; j++)
		{
			digit[j] = 0;
		}
		if(alphabet[25] > 0)
		{
			digit[0] = alphabet[25];
			alphabet[4] -= alphabet[25];
			alphabet[17] -= alphabet[25];
			alphabet[14] -= alphabet[25];
			alphabet[25] = 0;
		}
		if(alphabet[22] > 0)
		{
			digit[2] = alphabet[22];
			alphabet[19] -= alphabet[22];
			alphabet[14] -= alphabet[22];
			alphabet[22] = 0;
		}
		if(alphabet[23] > 0)
		{
			digit[6] = alphabet[23];
			alphabet[18] -= alphabet[23];
			alphabet[8] -= alphabet[23];
			alphabet[23] = 0;
		}
		if(alphabet[6] > 0)
		{
			digit[8] = alphabet[6];
			alphabet[4] -= alphabet[6];
			alphabet[8] -= alphabet[6];
			alphabet[7] -= alphabet[6];
			alphabet[19] -= alphabet[6];
			alphabet[6] = 0;
		}
		if(alphabet[18] > 0)
		{
			digit[7] = alphabet[18];
			alphabet[4] -= (2 * alphabet[18]);
			alphabet[21] -= alphabet[18];
			alphabet[13] -= alphabet[18];
			alphabet[18] = 0;
		}
		if(alphabet[21] > 0)
		{
			digit[5] = alphabet[21];
			alphabet[5] -= alphabet[21];
			alphabet[8] -= alphabet[21];
			alphabet[4] -= alphabet[21];
			alphabet[21] = 0;
		}
		if(alphabet[5] > 0)
		{
			digit[4] = alphabet[5];
			alphabet[14] -= alphabet[5];
			alphabet[20] -= alphabet[5];
			alphabet[17] -= alphabet[5];
			alphabet[5] = 0;
		}
		if(alphabet[14] > 0)
		{
			digit[1] = alphabet[14];
			alphabet[13] -= alphabet[14];
			alphabet[4] -= alphabet[14];
			alphabet[14] = 0;
		}
		if(alphabet[19] > 0)
		{
			digit[3] = alphabet[19];
			alphabet[7] -= alphabet[19];
			alphabet[17] -= alphabet[19];
			alphabet[4] -= 2 * alphabet[19];
			alphabet[19] = 0;
		}
		if(alphabet[8] > 0)
		{
			digit[9] = alphabet[8];
		}

		cout << "Case #" << (i + 1) << ": ";
		for(int j = 0; j < 10; j++)
		{
//			cout << digit[j] << " ";
			for(int k = 0; k < digit[j]; k++)
			{
				cout << j;
			}
		}
		cout << endl;
	}

	return 0;
}
