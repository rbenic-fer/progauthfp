#include <iostream>
#include <map>

using namespace std;

int neighbour( int **geomap, int i, int j );


int main()
{
	int n;
	cin >> n;

	for( int a = 0; a < n; a++ )
	{
		int height, width;
		cin >> height >> width;

		int **geomap;
		geomap = new int*[height+2];
		for( int i = 0; i < height+2; i++ )
		{
			geomap[i] = new int[width+2];
		}
		

		for( int i = 1; i <= height; i++ )
		{
			for( int j = 1; j <= width; j++ )
			{
				cin >> geomap[i][j];
			}
		}

		for(int i = 1; i <= height; i++ )
		{
			geomap[i][0] = geomap[i][1];
			geomap[i][width+1] = geomap[i][width];
		}
		
		for(int j = 1; j <= width; j++ )
		{
			geomap[0][j] = geomap[1][j];
			geomap[height+1][j] = geomap[height][j];
		}

#if 0
		cout << "Extended Map:" << endl;
		for( int i = 0; i < height+2; i++ )
		{
			for( int j = 0; j < width+2; j++ )
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
#endif
		
		
		int **dirmap;
		dirmap = new int*[height];
		for( int i = 0; i < height; i++ )
		{
			dirmap[i] = new int[width];
		}

		for( int i = 1; i <= height; i++ )
		{
			for( int j = 1; j <= width; j++ )
			{
				dirmap[i-1][j-1] = neighbour( geomap, i, j );
			}
		}

#if 0
		cout << "Direction Map:" << endl;
		for( int i = 0; i < height; i++ )
		{
			for( int j = 0; j < width; j++ )
			{
				cout << dirmap[i][j] << " ";
			}
			cout << endl;
		}
#endif

		char **answer;
		answer = new char*[height];
		for( int i = 0; i < height; i++ )
		{
			answer[i] = new char[width];
			for( int j = 0; j < width; j++ )
			{
				answer[i][j] = '0';
			}
		}

		char fillchar = 'A';
		for( int i = 0; i < height; i++ )
		{
			for( int j = 0; j < width; j++ )
			{
				if( dirmap[i][j] == 0 )
				{
					answer[i][j] = fillchar;
					fillchar++;
				}
				else if( dirmap[i][j] == 1 )
				{
					answer[i][j] = answer[i-1][j];
				}
				else if( dirmap[i][j] == 2 )
				{
					answer[i][j] = answer[i][j-1];
				}
			}
		}
		
		bool flag = true;
		while(flag)
		{
			flag = false;
			for( int i = height - 1; i >= 0 ; i-- )
			{
				for( int j = width - 1; j >= 0; j-- )
				{
					if( answer[i][j] == '0' )
					{
						flag = true;
						if( dirmap[i][j] == 3 )
						{
							answer[i][j] = answer[i+1][j];
						}
						else if( dirmap[i][j] == 4 )
						{
							answer[i][j] = answer[i][j+1];
						}
					}
				}
			}

			for( int i = 0; i < height; i++ )
			{
				for( int j = 0; j < width; j++ )
				{
					if( answer[i][j] == '0' )
					{
						flag = true;
						if( dirmap[i][j] == 1 )
						{
							answer[i][j] = answer[i-1][j];
						}
						else if( dirmap[i][j] == 2 )
						{
							answer[i][j] = answer[i][j-1];
						}
					}
				}
			}
		}

		fillchar = 'a';
		map<char, char> mapping;
		for( int i = 0; i < height; i++ )
		{
			for( int j = 0; j < width; j++)
			{
				if( mapping.count(answer[i][j]) == 0 )
				{
					mapping[answer[i][j]] = fillchar;
					answer[i][j] = fillchar;
					fillchar++;	
				}
				else
				{
					answer[i][j] = mapping[answer[i][j]];
				}
			}
		}


		cout << "Case #" << a+1 << ":" << endl;
		for( int i = 0; i < height; i++ )
		{
			for( int j = 0; j < width; j++ )
			{
				cout << answer[i][j] << " ";
			}
			cout << endl;
		}


	}

	return 0;
}

void fill( int **a, int height, int width, int fillchar, int findchar )
{
	for( int i = 0; i < height; i++ )
	{
		for( int j = 0; j < width; j++ )
		{
			if( a[i][j] == findchar )
			{
				a[i][j] = fillchar;
			}
		}
	}
	return;
}

int neighbour( int **geomap, int x, int y )
{
	int direction;
	int min = geomap[x][y], posx = 0, posy = 0;
	int i, j;
	
	i = -1; 
	if( min > geomap[x+i][y] )
	{
		min = geomap[x+i][y];
		posx = i;
		posy = 0;
	}

	for( int j = -1; j <= 1; j++ )
	{
		if( min > geomap[x][y+j] )
		{
			min = geomap[x][y+j];
			posx = 0;
			posy = j;
		}
	}
	
	i = 1; 
	if( min > geomap[x+i][y] )
	{
		min = geomap[x+i][y];
		posx = i;
		posy = 0;
	}

	if( posx == -1 && posy == 0 )
	{
		direction = 1;
	}
	else if( posx == 1 && posy == 0 )
	{
		direction = 3;
	}
	else if( posx == 0 && posy == -1 )
	{
		direction = 2;
	}
	else if( posx == 0 && posy == 1 )
	{
		direction = 4;
	}
	else
	{
		direction = 0;
	}

	return direction;
}

