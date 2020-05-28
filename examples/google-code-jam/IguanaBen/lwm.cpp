#include <iostream>

int tab[142][142];
using namespace std;

int maxC[142];
int maxR[142];

int main()
{
	int t;
	cin>>t;
	for (int z = 0; z < t; ++z)
	{
		int n,m;
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			maxR[i] = 0;
			for (int j = 0; j < m; ++j)
			{
				cin>>tab[i][j];
				maxR[i] = max(maxR[i], tab[i][j]);
			}
		}

		for (int i = 0; i < m; ++i)
		{
			maxC[i] = 0;
			for (int j = 0; j < n; ++j)
			{
				maxC[j] = max(maxC[i], tab[j][i]);
			}
		}

		bool val = 1;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (tab[j][i] == maxC[i] || tab[j][i] == maxR[j])
				{
				}
				else
					val = 0;
			}
		}

		cout<<"Case #"<<z+1<<": ";

		if(val == 0)
			cout<<"NO";
		else
			cout<<"YES";


		cout<<endl;

		// for (int i = 0; i < max(n,m); ++i)
		// {
		// 	cout<<maxC[i]<<" "<<maxR[i]<<endl;
		// 	cout<<endl;
		// }
	}
		

	return 0;
}