#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 

using namespace std;

int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
	int n;
	cin >> n;
	int a;
	cin >> a;
	int m = a, x = a, s = a;
	for (int i = 0; i < n-1; i++)
	{
	    cin >> a;
	    m = min(a,m);
	    x = x^a;
	    s = s + a;
	}
	if(x!=0)
	    cout << "Case #"<<t<<": NO\n";
	else
	    cout << "Case #"<<t<<": "<<(s-m)<<"\n";
    }
    return 0;
}
