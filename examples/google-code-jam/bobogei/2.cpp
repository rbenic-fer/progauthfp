#include<bits/stdc++.h>

using namespace std;

int T;
double X,C,F;

int main()
{
	cin >> T;
	for(int _t = 1 ; _t<= T ; _t++)
	{
		cin >> C >> F >> X ;
		int q = max( int( (F*X-2*C) / (C*F) ) , 0 );
		double ans=X/(2.0+q*F);
		for(int i=0;i<q;i++)
		{
			ans+=C/(2.0+i*F);
		}
		cout << "Case #" << _t << ": " << setprecision(9) << ans << endl;
	}
}
