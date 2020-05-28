#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

using namespace std;


bool opp(string& E, vector<string>& O)
{
    char b = E[E.length()-1];
    for(int i=0;i<E.length()-1;i++)
    {
	char a = E[i];
	tr(O,it)
	{
	    string s = *it;
	    if((a == s[0] && b == s[1]) or  (a == s[1] && b==s[0]))
		return true;
	}
    }
    return false;
}

int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
	int c, d, n;
	cin >> c;
	vector<string> combine(c);
	for (int i = 0; i < c; i++)
	    cin >> combine[i];
	
	cin >> d;
	vector<string> opposed(d);
	for (int i = 0; i < d; i++)
	    cin >> opposed[i];
	
	cin >> n;
	char ch;
	string E;
	for (int i = 0; i < n; i++)
	{
	    cin >> ch;
	    E.append(1,ch);
	    if(E.length()>=2)
	    {
		tr(combine,it)
		{
		    string lasttwo = E.substr(E.length()-2);
		    string s = it->substr(0,2);
		    if(lasttwo == s or (lasttwo[0]==s[1] and lasttwo[1]==s[0]))
		    {
			E = E.substr(0,E.length()-2);
			E.append(1,(*it)[2]);
			break;
		    }
		}
	    }
	    
	    if(opp(E,opposed))
		E.clear();
//	    cout << E << '\n';
	}
	cout << "Case #"<<t<<": [";
	for (int i = 0; i < E.size(); i++)
	{
	    if(i==E.size()-1)
		cout << E[i];
	    else
		cout << E[i] << ", ";
	}
	cout << "]\n";
	
    }
    return 0;
}
