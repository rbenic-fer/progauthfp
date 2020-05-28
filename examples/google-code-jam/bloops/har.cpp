#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <map>
#include <iomanip>
using namespace std;

#define FOR0(i,n) for(int i=0;i<n;i++)
#define ALL(c) c.begin(),c.end()
#define TR(it,c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define FORE(x,c) TR(__I,c)if(bool __B=1)for(typeof(*__I) x=*__I;__B;__B=0)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define IT(c) typeof(c.begin())
#define REP(n) for(int __z=0;__z<n;__z++)

typedef long long int lli;
typedef pair<int,int> ii;
typedef long double ld;

int A[10010];
int main()
{
    int T;
    cin >> T;
    
    FOR1(q,T)
    {
	int n,l,h;
	int best = -1;
	cin >> n >> l >> h;
	FOR0(i,n) cin >> A[i];
	for(int i=l;i<=h;i++)
	{
	    bool works = true;
	    FOR0(j,n)
	    {
		if(i<A[j])
		{
		    if(A[j]%i != 0)
			works = false;
		}
		else if(i>A[j])
		{
		    if(i%A[j] != 0)
			works = false;
		}
	    }
	    if(works)
	    {
		best = i;
		break;
	    }
	}
	if(best == -1)
	    cout << "Case #"<<q<<": NO\n";
	else
	    cout << "Case #"<<q<<": " << best << "\n";
    }
    return 0;
}
