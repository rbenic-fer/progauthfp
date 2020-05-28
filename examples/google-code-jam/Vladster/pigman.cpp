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

#define INP_FILE "A-large.in"
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
        int ans = 0; bool fail=false;
        vector<string> a; 
        int n,m; cin>>n>>m;
        vector<bool> g(n);
        vector<bool> v(m);
        int xxx=0;
        rp(i,n) {
            string s; cin>>s; a.pb(s); 
            int t=0,f=1,l=0; rp(j,s.size()) {
                t +=(s[j]=='.');
                if(f && s[j]=='<') {++ans;f=0;} f&=(s[j]=='.');
                if (s[j]=='>') l=1; else l &=(s[j]=='.');
            }
            ans+=l;
            g[i]=(t==m-1);
        }
        int yyy=0;
        rp(j,m) {
            int t=0,f=1,l=0; rp(i,n) {
                t+=(a[i][j]=='.');
                if(f && a[i][j]=='^') {++ans;} f&=(a[i][j]=='.');
                if (a[i][j]=='v') l=1; else l &=(a[i][j]=='.');
            }
            ans+=l;
            v[j]=(t==n-1);
        }
        rp(i,n) rp(j,m) if (a[i][j]!='.' && g[i] && v[j]) {
            fail=true; break;
        }


        if(fail) printf("Case #%d: IMPOSSIBLE\n",tst);
        else printf("Case #%d: %d\n",tst, ans);

	}
	
	return 0;
}