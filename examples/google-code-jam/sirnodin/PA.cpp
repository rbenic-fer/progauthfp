#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<list>
#include<stdio.h>
#include<sstream>
#include<set>
#include<deque>
#include<cmath>
#include<numeric>
#include<fstream>

using namespace std;

typedef long long LInt;
typedef vector<int> intvec;
typedef vector<intvec> intvec2;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)
#define FORIT(i,c) for (decltype((c).begin())i=(c).begin();i!=(c).end();++i)

/////////////////////////
//#define fin cin
//#define fout cout
////////////////////////

int main()
{
	ifstream fin("E:\\Buid\\Algorithm\\GoogleJam\\2011Qualification\\A-large.in");
	ofstream fout("E:\\Buid\\Algorithm\\GoogleJam\\2011Qualification\\A-large.out");
	
	int T;
	int N,P;
	char R;
	int Case = 0;
	int ans = 0;

	int oc,bc;
	int pn = 0,pl = 0;
	char rl;

	fin>>T;
	while(Case<T)
	{
		fin>>N;

		ans=0;
		oc = bc = 1;
		pn = pl = 0;

		REP(i,N)
		{
			fin>>R>>P;

			if(R == 'O')
			{
				if(i == 0||rl=='O')
				{
					pn+=abs(P-oc)+1;
					oc=P;
				}
				else
				{
					pl = pn;
					ans+=pl;
					if(abs(P-oc)+1>pl)
					{
						pn=abs(P-oc)+1-pl;
					}
					else
						pn=1;
					oc=P;
				}
				rl='O';
			}

			if(R == 'B')
			{
				if(i == 0||rl=='B')
				{
					pn+=abs(P-bc)+1;
					bc=P;
				}
				else
				{
					pl = pn;
					ans+=pl;
					if(abs(P-bc)+1>pl)
					{
						pn=abs(P-bc)+1-pl;
					}
					else
						pn=1;
					bc=P;
				}
				rl='B';
			}
		}
		ans+=pn;
		
		Case++;
		fout<<"Case #"<<Case<<": "<<ans<<endl;
	}

	system("pause");
	return 0;
}