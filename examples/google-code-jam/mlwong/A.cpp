#include <cstdio>
#include <cstring>

using namespace std;

char a[52][52];

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		memset(a, 0, sizeof(a));
		int r, c;
		scanf("%d %d", &r, &c);
		for (int x=1; x<=r; x++)
			for (int y=1; y<=c; y++)
				scanf("%1s", &a[x][y]);
		bool b = 0;
		for (int x=1; x<=r; x++)
			for (int y=1; y<=c; y++)
				if (a[x][y] == '#')
				{
					if (a[x+1][y] == '#' && a[x][y+1] == '#' && a[x+1][y+1] == '#')
					{
						a[x][y] = a[x+1][y+1] = '/';
						a[x][y+1] = a[x+1][y] = '\\';
					} else {
						b = 1;
						break;
					}
				}
		printf("Case #%d:\n", i);
		if (b) printf("Impossible\n");
		else {
			for (int x=1; x<=r; x++)
			{
				for (int y=1; y<=c; y++) printf("%c", a[x][y]);
				printf("\n");
			}
		}
	}
	return 0;
}
