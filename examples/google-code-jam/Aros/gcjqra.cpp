#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, cnt;
char mat[10][10];
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int flag = 3;
		for (int i = 0; i < 4; i++)
			scanf("%s", mat[i]);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) if (mat[i][j] == '.')
				flag = 4;
		for (int i = 0; i < 4; i++)
		{
			cnt = 0;
			for (int j = 0; j < 4; j++) if (mat[i][j] == 'X' || mat[i][j] == 'T')
				cnt++;
			if (cnt == 4)
				flag = 1;
			cnt = 0;
			for (int j = 0; j < 4; j++) if (mat[i][j] == 'O' || mat[i][j] == 'T')
				cnt++;
			if (cnt == 4)
				flag = 2;
		}
		for (int j = 0; j < 4; j++)
		{
			cnt = 0;
			for (int i = 0; i < 4; i++) if (mat[i][j] == 'X' || mat[i][j] == 'T')
				cnt++;
			if (cnt == 4)
				flag = 1;
			cnt = 0;
			for (int i = 0; i < 4; i++) if (mat[i][j] == 'O' || mat[i][j] == 'T')
				cnt++;
			if (cnt == 4)
				flag = 2;
		}
		cnt = 0;
		for (int i = 0; i < 4; i++) if (mat[i][i] == 'X' || mat[i][i] == 'T')
			cnt++;
		if (cnt == 4)
			flag = 1;
		cnt = 0;
		for (int i = 0; i < 4; i++) if (mat[i][i] == 'O' || mat[i][i] == 'T')
			cnt++;
		if (cnt == 4)
			flag = 2;
		cnt = 0;
		for (int i = 0; i < 4; i++) if (mat[i][3-i] == 'X' || mat[i][3-i] == 'T')
			cnt++;
		if (cnt == 4)
			flag = 1;
		cnt = 0;
		for (int i = 0; i < 4; i++) if (mat[i][3-i] == 'O' || mat[i][3-i] == 'T')
			cnt++;
		if (cnt == 4)
			flag = 2;
		if (flag == 1)
			printf("Case #%d: X won\n", cas);
		else if (flag == 2)
			printf("Case #%d: O won\n", cas);
		else if (flag == 3)
			printf("Case #%d: Draw\n", cas);
		else
			printf("Case #%d: Game has not completed\n", cas);
	}
	return 0;
}
