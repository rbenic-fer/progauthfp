#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char p[55][55];

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d:\n", i+1);

		int R, C;
		scanf("%d %d", &R, &C);
		for (int y = 0; y <= R+1; y++) {
			for (int x = 0; x <= C+1; x++) {
				p[y][x] = '.';
			}
		}

		for (int j = 0; j < R; j++) {
			scanf("%s", p[j]);
		}
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (p[y][x] == '#') {
					if (p[y][x+1] == '#' && p[y+1][x] == '#' && p[y+1][x+1] == '#') {
						p[y][x] = '/';
						p[y][x+1] = '\\';
						p[y+1][x] = '\\';
						p[y+1][x+1] = '/';
					} else {
						printf("Impossible\n");
						goto NEXT;
					}
				}
			}
		}
		for (int y = 0; y < R; y++)
			printf("%s\n", p[y]);

	NEXT:;
	}
}
