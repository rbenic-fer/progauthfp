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

#define INP_FILE "C-small-attempt1.in"
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

const int x1 = 0;
const int xi = 1;
const int xj = 2;
const int xk = 3;

int mull(int a, int b)
{
    int s = (a^b)&4;
    a&=3;
    b&=3;
    const int z[4][4]=
    {{x1, xi  ,xj  ,xk},
     {xi, x1|4,xk  ,xj|4},
     {xj, xk|4,x1|4,xi},
     {xk, xj  ,xi|4,x1|4}};
    int res = z[a][b];
    res ^= s;
    return res;
}

vi buildTable(int xx)
{
    vi a(25);
    rp(i, 8) {
        int t = mull(i, xx);
        a[i +  0] = 1 << (t +  0);
        a[i +  8] = 1 << (t +  8);
        a[i + 16] = 1 << (t + 16);
        if (t == xi) a[i +  0] |= 1 << (x1+8);
        if (t == xj) a[i +  8] |= 1 << (x1+16);
        if (t == xk) a[i + 16] |= 1 << (x1+24);
    }
    a[24] = 1<<24;
    return a;
}
vi idTable()
{
    vi a;
    rp(i, 25) a.pb(1<<i);
    return a;
}
vi mullTable(vi &a, vi &b)
{
    vi r(25);
    rp(i, 25) {
        int c = a[i];
        int p = 0;
        int t = 0;
        while(c>0) {
            if (c&1) t |= b[p];
            ++p;
            c >>=1;
        }
        r[i] = t;
    }
    return r;
}


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

    vi ti = buildTable(xi);
    vi tj = buildTable(xj);
    vi tk = buildTable(xk);
    vi t0 = idTable();

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int l,x; string s; cin>>l>>x>>s;
        vi t = t0;
        rp(i, s.size()) {
            switch (s[i]) {
                case 'i': t = mullTable(t, ti); break;
                case 'j': t = mullTable(t, tj); break;
                case 'k': t = mullTable(t, tk); break;
            }
        }
        vi z = t0;
        while (x>0) {
            if (x&1)
                z = mullTable(z, t);
            t = mullTable(t, t);
            x >>= 1;
        }
        rp(i, x) {
            
        }
        printf("Case #%d: %s\n",tst, (z[0] & (1<<24)) ? "YES": "NO");
        

		//printf("Case #%d: ",tst);
	}
	
	return 0;
}