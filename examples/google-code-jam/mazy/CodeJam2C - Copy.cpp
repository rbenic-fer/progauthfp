#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef long long ll;
const double pi=acos(-1.0);
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define sz(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define rep(i,b) for(int i=0;i<b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
const int oo=1000000;

int vv[105][26];
int ban[105];
int co[105][105];
int f[105];
int bi[105];

int main()
{
    //const char flnm_in[] = "input.txt";const char flnm_out[] = "out.txt";
    const char flnm_in[] = "C-small-attempt0.in";const char flnm_out[] = "C-small-0.out";
    //const char flnm_in[] = "A-large.in";const char flnm_out[] = "A-large.out";
    ifstream i_file;
    i_file.open(flnm_in);
    ofstream o_file;
    o_file.open(flnm_out);
    if (!i_file.is_open())
        return 0;
    if (!o_file.is_open())
        return 0;
    int T=0;
    i_file>>T;
	for (int caseId=1;caseId<=T;caseId++)
	{
        int n,k;
        i_file>>n>>k;
        memset(vv,0,sizeof(vv));
        memset(ban,0,sizeof(ban));
        memset(co,0,sizeof(co));
        memset(f,0,sizeof(f));
        memset(bi,0,sizeof(bi));
        rep(i,n)
            rep(j,k){
                i_file>>vv[i][j];
        }
        rep(i,n){
            rep(j,n){
                if (i==j)
                    continue;
                bool big=(vv[i][0]>vv[j][0]);
                bool ok=true;
                For(kk,1,k){
                    if ((vv[i][kk]==vv[j][kk]) || (vv[i][kk]>vv[j][kk] && !big) || (vv[i][kk]<vv[j][kk] && big))
                    {
                        ok=false;
                        break;
                    }
                }
                if (ok)
                {
                    co[i][j]=big?1:-1;
                    co[j][i]=-co[i][j];
                }
            }
        }
        int count = 0;
        rep(i,n)
        {
            bool ok=true;
            rep (j,n){
                if (co[i][j]<0)
                {
                    ok=false;
                    break;
                }
            }
            if (ok){
                ban[count] = i;
                bi[i]=count;
                f[i]=1;
                count++;
            }
        }
        bool handled=true;
        while(handled){
            handled=false;
            int min=n,mini=-1,minto=-1;
            rep(i,n){
                if (f[i]==1)
                    continue;
                handled=true;
                int ccc=0;
                rep(j,n){
                    if (co[i][j]==-1)
                    {
                        ccc++;
                        minto=j;
                    }
                }
                if (ccc<min){
                    min=ccc;
                    mini=i;
                }
            }
            if (handled){
                f[mini]=1;
                if (min==0){
                    ban[count] = mini;
                    bi[mini]=count;
                    count++;
                }
                else{
                    bi[mini]=bi[minto];
                    int old=ban[bi[minto]];
                    ban[bi[minto]]=mini;
                    rep(i,n){
                        co[i][old]=0;
                    }
                }
            }
        }
        cout << "Case #"<<caseId<<": "<<count<<"\n";
        o_file << "Case #"<<caseId<<": "<<count<<"\n";
	}
    i_file.close();
    o_file.close();
    return 0;
}