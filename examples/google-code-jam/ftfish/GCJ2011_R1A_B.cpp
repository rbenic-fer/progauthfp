#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define debuging

#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif

#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif

#define rep(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,n) rep(i,0,(n))
#define SZ(x) (int)((x).size())
#define CLR(a) memset((a),0,sizeof (a))
#define all(c) (c).begin(), (c).end() 
#define iter(c) __typeof((c).begin())
#define contains(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef set<int> sint;
typedef pair<int, int> pint;

const int maxint = -1u >> 2;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int mn = 10005, ml = 15, alpha = 26;

int n;
char s[mn][ml];
int len[mn];
bool has[mn][alpha];
char perm[alpha + 1];

int calc() {
    int maxdec = -1, maxidx = 0;
    static bool flg[mn];
    rep(i, 0, n) {
        memset(flg, 0, n);
        REP(j,n)
            if (len[i] != len[j]) flg[j] = 1;
        int curdec = 0;

        REP(j,alpha) {
            int c = perm[j] - 'a';
            bool t = 0;
            REP(k, n) {
                if (!flg[k]) {
                    if (has[k][c]) {
                        t = 1;
                        break;
                    }
                }
            }
            if (t) {
                if (!has[i][c]) {
                    ++curdec;
                    REP(k,n)
                        if (has[k][c]) flg[k] = 1;
                } else {
                    int lst[ml], lstn = 0;
                    REP(k,len[i])
                        if (s[i][k] == perm[j]) lst[lstn++] = k;
                    REP(k,n)
                        if (!flg[k]) {
                            REP(l,lstn)
                                if (s[k][lst[l]] != perm[j]) flg[k] = 1;
                            REP(l,len[k])
                                if (s[k][l] == perm[j] && s[i][l] != perm[j]) flg[k]
                                        = 1;
                        }
                }
            }
        }
        if (maxdec == -1 || curdec > maxdec) maxdec = curdec, maxidx = i;
    }
//    printf("(%d pt)", maxdec);
    return maxidx;
}

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    int Tn;
    scanf("%d", &Tn);
    for (int Tc = 1; Tc <= Tn; ++Tc) {
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        CLR(has);
        REP(i,n) {
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            REP(j,len[i])
                has[i][s[i][j] - 'a'] = 1;
        }

        printf("Case #%d:", Tc);
        REP(cn, m) {
            scanf("%s", perm);
            printf(" %s", s[calc()]);
        }
        putchar('\n');
    }

    return 0;
}
