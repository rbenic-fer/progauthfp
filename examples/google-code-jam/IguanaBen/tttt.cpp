#include <iostream>

using namespace std;

char tab[12][12];
bool check(int x, int y)
{
	char s = tab[x][y];

	bool b[4];
	for (int i = 0; i < 4; ++i)
		b[i] = 1;

	// cout<<x<<" "<<y<<endl;
	for (int i = 1; i < 4; ++i)
	{
		// cout<<b[3]<<tab[x-i][y+i]<<b[3]<<tab[x][y]<<endl;
		b[0] = b[0] && (tab[x+i][y+i] == s);
		b[1] = b[1] && (tab[x][y+i] == s);
		b[2] = b[2] && (tab[x+i][y] == s);
		b[3] = b[3] && (tab[x-i][y+i] == s);
		
	}
	// cout<<endl;

	return (b[0] || b[1] || b[2] || b[3]);
}

int main()
{

		int tx, ty;
		
		for (int i = 0; i < 12; ++i)
			for (int j = 0; j < 12; ++j)
				tab[i][j]='.';

	int t;
	cin>>t;
	for (int z = 0; z < t; ++z)
	{	
		bool is_dot = 0;
		for (int i = 4; i < 8; ++i)
			for (int j = 4; j < 8; ++j)
			{
				cin>>tab[i][j];
				if(tab[i][j] == 'T')
				{
					tx = i;
					ty = j;
				}
				if(tab[i][j] == '.')
					is_dot = 1;
			}

		bool owon = 0, xwon = 0;

		for (int i = 4; i < 8; ++i)
			for (int j = 4; j < 8; ++j)
			{ 	
				tab[tx][ty] = 'X';
				if (check(i, j))
				{
					// cout<<tx<<" "<<ty<<" "<<endl;
				 	if( tab[i][j] == 'X')
				 		xwon = 1;

				 	if( tab[i][j] == 'O')
				 		owon = 1;
				}

				tab[tx][ty] = 'O';
				if (check(i, j))
				{
					// cout<<tx<<" "<<ty<<" "<<endl;
				 	if( tab[i][j] == 'X')
				 		xwon = 1;

				 	if( tab[i][j] == 'O')
				 		owon = 1;
				}
				tab[tx][ty] = 'T'; //n
			}

		cout<<"Case #"<<z+1<<": ";
		if(owon)
			cout<< "O won";
		else
			if(xwon)
				cout<< "X won";

		if(!(xwon  || owon))
		{
			if(is_dot)
				cout<<"Game has not completed";
			else
				cout<<"Draw";
		}

		cout<<endl;

	}

	return 0;
}