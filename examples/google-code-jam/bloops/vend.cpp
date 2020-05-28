#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <map>
#include <iomanip>
using namespace std;

#define FOR0(i, n) for(int i=0;i<n;i++)
#define ALL(c) c.begin(),c.end()
#define TR(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define FORE(x,c) TR(__I,c)if(bool __B=1)for(typeof(*__I) x=*__I;__B;
#define FOR1(i, n) for(int i=1;i<=n;i++)
#define IT(c) typeof(c.begin())
#define REP(n) for(int __z=0;__z<n;__z++)

typedef long long int lli;
typedef pair<int,int> ii;
typedef long double ld;

double pos[1000010], npos[1000010]; // position of ith vendor
int nv = 0;
ld eps = 1e-8;

ld abs(ld x)
{
    return x<0 ? -x : x;
}

bool valid(ld k, int d) // valid vendors by moving at most k
{
    npos[0] = pos[0]-k;
    FOR1(i,nv-1)
    {
	ld des = npos[i-1] + d;
	if(des - pos[i] > k)
	    return false;
	npos[i] = max(des,pos[i]-k);
//	cout << "Moved " << i << " to " << npos[i] << endl;
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    FOR1(q,T)
    {
    int d,c;
    cin >> c >> d;
    nv = 0;
    FOR0(j,c)
    {
	int p,v;
	cin >> p >> v;
	while(v--)
	    pos[nv++] = p;
    }
    //cout << nv << endl;
    // FOR0(i,nv)
    // 	cout << pos[i] << ' ';
    // cout << endl;
    
    ld ans;
    ld hi = 1e10, lo = 0.0;
    int iter = 0;
    while(1)
    {
	iter++;
	ld mid = 0.500000 * (hi + lo);
	//cout << mid << endl;
	bool v = valid(mid,d);
	if (hi-lo < eps or iter > 1000)
	{
	    ans = mid;
	    break;
	}
	if(v and !valid(mid-eps,d))
	{
	    ans = mid; 
	    break;
	}
	if(v)
	    hi = mid;
	else
	    lo = mid;
    }
    cout << setprecision(12) << "Case #" << q << ": "<<ans << '\n';
/*    while(1)
    {
	ld k;
	cin >> k;
	cout << valid(k,d) << endl;
	}*/
    }
    return 0;
}
