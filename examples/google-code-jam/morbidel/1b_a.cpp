/*
 * Google Code Jam 2011
 * Round 1B - Problem A - RPI
 */

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAXN	1024
#define INPUT	"A-large.in"
#define OUTPUT	"A-large.out"

int T, N;
char A[101][101];
std::vector<double> RPI, WP, OWP;


void ReadData()
{
	int i;

	memset(A, 0, sizeof(A));

	scanf("%d ", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s\n", &A[i]);
	}
}

double compute_wp(int team, int dif)
{
	int i, c = 0;
	double res = 0;

	for (i = 0; i < N; i++)
		if (A[team][i] != '.' && (i != dif || i == -1))
		{
			c++;
			res += A[team][i] - '0';
		};
	if (c == 0) 
		return 0;
	else
		return res / (double) c;
}

double compute_owp(int team)
{
	int i, c = 0;
	double res = 0;

	for (i = 0; i < N; i++)
		if (i != team && A[team][i] != '.')
		{
			res += compute_wp(i, team);
			c++;
		};

	if (c == 0) 
		return 0;
	else
		return res / (double) c;
}

double compute_oowp(int team)
{
	int i, c = 0;
	double res = 0;

	for (i = 0; i < N; i++)
		if (A[team][i] != '.')
		{
			res += OWP[i];
			c++;
		};

	if (c == 0) 
		return 0;
	else
		return res / (double) c; 
}

void Solve()
{
	int i, j, c;
	double oowp, rpi;


	RPI.clear();
	WP.clear();
	OWP.clear();

	for (i = 0; i < N; i++)
	{
		WP.push_back(compute_wp(i, -1));
		OWP.push_back(compute_owp(i));
	}
	for (i = 0; i < N; i++)
	{
		oowp = compute_oowp(i);
		rpi = 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * oowp;
		RPI.push_back(rpi);
	}

	for (i = 0; i < N; i++) 
		printf("%.12lf\n", RPI[i]);
}


int main()
{
	int i, sol;

	freopen(INPUT, "rt", stdin);
	scanf("%d\n", &T);

	freopen(OUTPUT, "wt", stdout);
	for (i = 1; i <= T; i++)
	{
		ReadData();

		printf("Case #%d: \n", i);
		
		Solve();
	}

	return 0;
}