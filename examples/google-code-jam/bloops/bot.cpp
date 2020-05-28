#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 

using namespace std;

int find_next(int s, char c, const vector< pair<char,int> > &A)
{
    for(int i=s;i<A.size();i++)
	if(A[i].first == c)
	    return A[i].second;
    return -1;
}


int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
	int n;
	cin >> n;
	vector< pair<char,int> > V(n);
	char c;
	int a;
	for (int i = 0; i < n; i++)
	{
	    cin >> c >> a;
	    V[i] = make_pair(c,a);
	}

	int next = 0; // which button should be pushed next
	int o = 1, b = 1, on = 0, bn = 0; // next destinations for O and B

	int steps = 0;
	while(next < n)
	{
	    on = find_next(next,'O',V);
	    bn = find_next(next,'B',V);
	    
	    if(V[next].first == 'O')
	    {
		if (on==o) // O pushes button
		    next++;
		else if(on>o)
		    o++; // O moves forward
		else if(on<o)
		    o--; // O moves backward
		// B cannot push, so it either moves or stays put
		if(bn>b) // bn could be -1 so forget about it
		    b++;
		else if(bn<b)
		    b--;
	    }
	    else if(V[next].first == 'B')
	    {
		if (bn==b) // O pushes button
		    next++;
		else if(bn>b)
		    b++; // O moves forward
		else if(bn<b)
		    b--; // O moves backward
		// B cannot push, so it either moves or stays put
		if(on>o) // bn could be -1 so forget about it
		    o++;
		else if(on<o)
		    o--;
	    }
	    //cout << o << ':' << on << '\t' << b << ':' << bn <<'\t' << next << '\n';
	    steps++;	    
	}
	cout << "Case #"<<t<<": "<<steps <<'\n';
    }
    return 0;
}

