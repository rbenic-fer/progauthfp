#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int _t=0;_t<T;_t++)
	{
		int r1,r2;
		int m1[4][4],m2[4][4];
		cin >> r1;
		r1--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin >> m1[i][j];

		cin >> r2;
		r2--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin >> m2[i][j];

		int k[17]={};
		memset(k,0,sizeof(k));

		for(int i=0;i<4;i++)
		{
			k[m1[r1][i]]++;
			k[m2[r2][i]]++;
		}
		
		int c=0,a=0;
		for(int i=1;i<17;i++)
		{
			if(k[i]==2)
			{
				//cout << i << endl;
				c++;
				a=i;
			}
		}

		cout << "Case #" << _t+1 << ": ";
		if( c == 0 ) cout << "Volunteer cheated!";
		else if( c >= 2 ) cout << "Bad magician!";
		else cout << a;

		cout << endl;
	}
}
