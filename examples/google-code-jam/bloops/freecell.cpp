#include <iostream>
using namespace std;
typedef long long int lli;

int main()
{
    int t; 
    cin >> t;
    for(int q = 1; q<=t;q++)
    {
	lli n, pd, pg;
	bool poss = true;
	cin >> n >> pd >> pg;
	lli d = 1;
	if( pd % 4 != 0)
	{
	    if(pd%2 == 0)
		d *= 2;
	    else
		d *= 4;
	}
	if( pd %25 != 0)
	{
	    if (pd % 5 == 0)
		d *= 5;
	    else d *= 25;
	}
	if (d > n) 
	    poss = false;
	if (pd < 100 and pg == 100)
	    poss = false;
	if (pd > 0 and pg == 0)
	    poss = false;
	
	cout << "Case #" << q << ": " << (poss?"Possible":"Broken") << '\n';

    }
}
