#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 

#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

using namespace std;

int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    for (int j = 1; j <= T; j++)
    {
	int N, a;
	int fp = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
	    cin >> a;
	    if(a==i)
		fp++;
	}
	cout << "Case #"<<j<<": "<<(N-fp) << ".000000\n";	
    }
    return 0;
}
