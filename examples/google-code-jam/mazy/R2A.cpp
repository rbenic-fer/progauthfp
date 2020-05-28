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
typedef map<string, int> simp;
#define sz(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define rep(i,b) for(int i=0;i<b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
template<class T> inline void Swap(T &a,T &b){T c=a;a=b;b=c;}
const int oo=1000000;

#pragma warning(disable:4996)

const int maxk=51+3;
int dia[maxk*2][maxk];

#define elc(l,k) (l<k?l+1:((l>2*k-2)?0:2*k-l-1))
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        int k=0;
        scanf("%d",&k);
        memset(dia,0,sizeof(dia));
        For(i,1,k+1){
            bool odd=k%2?(i%2?true:false):(i%2?false:true);
            For(j,1,2*k){
                if (odd)
                {
                    if (!(j%2))
                        dia[i][j]=-1;
                    else if (j<=k-i || j>=k+i)
                        dia[i][j]=-1;
                    else
                        cin>>dia[i][j];
                }
                else
                {
                    if (j%2)
                        dia[i][j]=-1;
                    else if (j<=k-i || j>=k+i)
                        dia[i][j]=-1;
                    else
                        cin>>dia[i][j];
                }
            }
        }
        For(i,k+1,2*k){
            bool odd=k%2?(i%2?true:false):(i%2?false:true);
            For(j,1,2*k){
                int i1=2*k-i;
                if (odd)
                {
                    if (!(j%2))
                        dia[i][j]=-1;
                    else if (j<=k-i1 || j>=k+i1)
                        dia[i][j]=-1;
                    else
                        cin>>dia[i][j];
                }
                else
                {
                    if (j%2)
                        dia[i][j]=-1;
                    else if (j<=k-i1 || j>=k+i1)
                        dia[i][j]=-1;
                    else
                        cin>>dia[i][j];
                }
            }
        }
        int vl1=2*k-1;
        For(i,k,2*k-1){
            bool ok=true;
            For(j,1,i){
                int j1=i+(i-j);
                if (j1<2*k){
                For(p,1,2*k){
                    if (dia[j][p]!=dia[j1][p] && dia[j1][p]>=0 && dia[j][p]>=0){
                        ok=false;
                        break;
                    }
                }}
                if (!ok)
                    break;
            }
            if (ok){
                vl1=i;
                break;
            }
        }
        vl1-=k;
        int vl2=1;
        for (int i=k-1;i>1;i--){
            bool ok=true;
            For(j,1,i){
                int j1=i+(i-j);
                if (j1<2*k){
                For(p,1,2*k){
                    if (dia[j][p]!=dia[j1][p] && dia[j1][p]>=0 && dia[j][p]>=0){
                        ok=false;
                        break;
                    }
                }}
                if (!ok)
                    break;
            }
            if (ok){
                vl2=i;
                break;
            }
        }
        vl2=k-vl2;
        int vl=min(vl1,vl2);

        int ll1=2*k-1;
        For(i,k,2*k-1){
            bool ok=true;
            For(j,1,i){
                int j1=i+(i-j);
                if (j1<2*k){
                For(p,1,2*k){
                    if (dia[p][j]!=dia[p][j1] && dia[p][j1]>=0 && dia[p][j]>=0){
                        ok=false;
                        break;
                    }
                }}
                if (!ok)
                    break;
            }
            if (ok){
                ll1=i;
                break;
            }
        }
        ll1-=k;

        int ll2=1;
        for (int i=k-1;i>1;i--){
            bool ok=true;
            For(j,1,i){
                int j1=i+(i-j);
                if (j1<2*k){
                For(p,1,2*k){
                    if (dia[p][j]!=dia[p][j1] && dia[p][j1]>=0 && dia[p][j]>=0){
                        ok=false;
                        break;
                    }
                }}
                if (!ok)
                    break;
            }
            if (ok){
                ll2=i;
                break;
            }
        }
        ll2=k-ll2;
        int ll=min(ll1,ll2);

        int kk=k;
        int cc=0;
        For(i,0,vl){
            cc+=kk;
            kk++;
            cc+=kk;
        }
        For(i,0,ll){
            cc+=kk;
            kk++;
            cc+=kk;
        }
        // input
        /*
        cin>>n>>k;
        rep(i,n){
            rep(j,n){
                i_file>>V[i][j];
            }
        }
        string line;
        getline(stdin, line, ' ');
        */


        // output
        /*
        char buf[100];
        bool rr=checkLine('R') || checkRow('R') || checkDia('R') || checkDia2('R');
        bool bb=checkLine('B') || checkRow('B') || checkDia('B') || checkDia2('B');
        if (rr&&bb)
            strcpy(buf,"Both");
        else if (rr&&!bb)
            strcpy(buf,"Red");
        else if (!rr&&bb)
            strcpy(buf,"Blue");
        else
            strcpy(buf,"Neither");
        */
        cout << "Case #"<<caseId<<": "<<cc<<"\n";


	}
    return 0;
}