#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "D-large.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define vi vector<int>
#define vvi vector<vi >
#define ll long long
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

bool solve(int x, int r, int c)
{
    if (x >= 8) return 0;
    if (x > r && x > c) return 0;
    if ((r*c)%x) return 0;
    if (r>c) swap(r,c);
    if (x >= 2*r+1 || x >= 2*c+1) return 0;
    if (x == 2*r && r != 1) return 0;
    if (x == 2*c && c != 1) return 0;
    if (x<=r && x<=c) return 1;
    if (r==1) return 1;
    if(r==3 && c<10 && x==5) return 0;



    return 1;
}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int x,r,c; cin>>x>>r>>c;
        printf("Case #%d: %s\n",tst,(solve(x,r,c) ? "GABRIEL" : "RICHARD"));
		//printf("Case #%d: ",tst);
	}
	
	return 0;
}