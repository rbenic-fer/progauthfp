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

char m[105][105];
double WP[105];
int aw[105];
int ac[105];
double OWP[105];
double OOWP[105];

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		for (int y = 0; y < N; y++) {
			scanf("%s", m[y]);
		}
		for (int j = 0; j < N; j++) {
			int w = 0, c = 0;
			for (int k = 0; k < N; k++) {
				if (m[j][k] == '1')
					w++;
				if (m[j][k] != '.')
				    c++;
			}
			aw[j] = w;
			ac[j] = c;
			WP[j] = (double)w/c;
			//printf("WP[%d]=%f\n", j, WP[j]);
		}
		for (int j = 0; j < N; j++) {
			int c = 0;
			double s = 0.0;
			for (int k = 0; k < N; k++) {
				if (m[j][k] != '.') {
					c++;
					//s += WP[k];
					if (m[j][k] == '1')
						s += (double)aw[k]/(ac[k]-1);
					else
						s += (double)(aw[k]-1)/(ac[k]-1);
				}
			}
			OWP[j] = s/c;
			//printf("OWP[%d]=%f\n", j, OWP[j]);
		}
		for (int j = 0; j < N; j++) {
			int c = 0;
			double s = 0.0;
			for (int k = 0; k < N; k++) {
				if (m[j][k] != '.') {
					c++;
					s += OWP[k];
				}
			}
			OOWP[j] = s/c;
			//printf("OOWP[%d]=%f\n", j, OOWP[j]);
		}
		printf("Case #%d:\n", i+1);
		for (int j = 0; j < N; j++) {
			double ans = 0.25*WP[j] + 0.5*OWP[j] + 0.25*OOWP[j];
			printf("%.9f\n", ans);
		}
	}
}
