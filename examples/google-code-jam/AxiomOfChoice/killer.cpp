#include <list>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin(); i!=(c).end(); i++ )
#define MAX 10000

int T, n, m, cost[MAX];
string d[MAX], blank[11], strat;
map< string, list<int> > coset[27];
bool contains[MAX][26];

int main()
{
	cin >> T;
	blank[0] = "";
	for( int i = 1; i <= 10; i++ ) blank[i] = blank[i-1] + " ";
	for( int t = 1; t <= T; t++ )
	{
		cin >> n >> m;
		coset[0].clear();
		for( int i = 0; i < n; i++ )
		{
			cin >> d[i];
			int len = d[i].size();
			coset[0][blank[len]].push_back(i);
			for( int j = 0; j < 26; j++ ) contains[i][j] = false;
			for( int j = 0; j < len; j++ ) contains[i][d[i][j]-'a'] = true;
		}
		cout << "Case #" << t << ":";
		for( int i = 0; i < m; i++ )
		{
			cin >> strat;
			for( int j = 0; j < n; j++ ) cost[j] = 0;
			for( int j = 0; j < 26; j++ )
			{
				coset[j+1].clear();
				foreach(c,coset[j])
				{
					bool has = false;
					foreach(s,c->second) if( contains[*s][strat[j]-'a'] ) has = true;
					if(has) foreach(s,c->second)
					{
						if( contains[*s][strat[j]-'a'] )
						{
							string cnext(c->first);
							for( int k = 0; k < d[*s].size(); k++ ) if( d[*s][k] == strat[j] ) cnext[k] = strat[j];
							coset[j+1][cnext].push_back(*s);
						}
						else
						{
							cost[*s]++;
							coset[j+1][c->first].push_back(*s);
						}
					}
					else foreach(s,c->second) coset[j+1][c->first].push_back(*s);
				}
			}
			int best = 0;
			for( int j = 0; j < n; j++ ) if( cost[j] > cost[best] ) best = j;
			cout << " " << d[best];
		}
		cout << endl;
	}
	return 0;
}
