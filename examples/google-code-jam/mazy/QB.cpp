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
#define Sort(v) sort((v).begin(), (v).end())
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "B"

char tr[256][256];
char oppo[256][256]; // bool
int c,d,n;

int main()
{
//	freopen("test.in","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        cl(tr,0);
        cl(oppo,0);

        cin>>c;
        rep(i,c){
            string tmp;
            cin>>tmp;
            char a=tmp[0];
            char b=tmp[1];
            tr[a][b]=tmp[2];
            tr[b][a]=tmp[2];
        }
        cin>>d;
        rep(i,d){
            string tmp;
            cin>>tmp;
            char a=tmp[0];
            char b=tmp[1];
            oppo[a][b]=true;
            oppo[b][a]=true;
        }
        cin>>n;
        string dt;
        cin>>dt;


        char odt[101];
        cl(odt,0);
        int q=0;
        char last=0;
        rep(i,n){
            char a=dt[i];
            if (i>0) {
                char b=dt[i-1];
                if (tr[a][last]) {
                    odt[q-1]=tr[a][last];
                    last=tr[a][last];
                } else {
                    bool tocl=false;
                    rep(j,q){
                        if (oppo[odt[j]][a]) {
                            tocl=true;
                            break;
                        }
                    }
                    if (tocl){
                        cl(odt,0);
                        q=0;
                        last=0;
                    } else {
                        odt[q++]=a;
                        last=a;
                    }
                }
            } else {
                odt[q++]=a;
                last=a;
            }
        }
        char buf[1024];
        cl(buf,0);
        char* p=buf;
        rep(i,q){
            char a=odt[i];
            p[0]=a;
            strcat(buf,", ");
            p+=3;
        }
        int l=strlen(buf);
        if (l>2) buf[l-2]=0;
        // output
        cout << "Case #"<<caseId<<": "<<"["<<buf<<"]"<<"\n";
	}
    return 0;
}