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

#define INP_FILE "B-large.in"
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


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int n; cin>>n;
        vi a;
        rp(i, n) { int t; cin>>t; a.pb(t);}
        int best = 2015, used=0;
        for(int i = 1;i<=1000;++i) {
            int c = i;
            rp(j, n) {
                c += (a[j]-1) / i;
            }
            best = min(best, c);
        }
        printf("Case #%d: %d\n",tst, best);
		//printf("Case #%d: ",tst);
	}
	
	return 0;
}