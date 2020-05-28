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
#include <assert.h>

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

#define QX "D"

double f[1001];
double e[1001];
double p[1001];
int n;

double calc(int k) {
    if (f[k]>=0) return f[k];
    double tmp = 1;
    For(i,1,k-2+1){
        tmp+=(e[k-i]*p[i]*calc(k-i));
    }
    f[k]=tmp/(1-e[k]);

    return f[k];
}

bool flag=false;
double worker(int m) {
    assert(m!=1);
    if (m<=1) return 0;
    else if (m==2) {flag=true;return 0;}
    int a[100];
    char used[100];
    cl(a,0);
    cl(used,0);
    rep(i,m) {
        int tmp = rand() % (m-i);
        int p=0;
        do {
            p++;
            while(used[p]) p++;
            a[i]=p;
        }while(tmp--);
        used[p]=true;
    }
    int ans=0;
    rep(i,m) {
        if (a[i] != i+1) ans++;
    }
    return 1+worker(ans);
}

double simu(int m) {
    double ct=0;
    const double sc=100000;
    rep(i,sc) {
        double tt=worker(m/2);
        if (flag){
            flag=false;
            ct+=tt*2+4;
        } else {
            ct+=tt*2;
        }
    }
    return ct/sc;
}

int main()
{
//	freopen("test.in","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt2.in","r",stdin);freopen("" QX "-small-attempt2.out","w",stdout);
	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

/*    string str("123456");
    int cc[10];
    cl(cc,0);
    cc[0]=1;
    while (next_permutation(str.begin(), str.end()))
    {
        //cout << str << endl;
        int ct=0;
        rep(i,str.length()){ if (str[i]!='0'+i+1) ct++;}
        cc[ct]++;
    }
    rep(i,str.length()+1){
        cout<<i<<": "<<cc[i]<<endl;
    }*/

//  srand(time(NULL));
    //cout<<simu(8)<<endl;

    cl(f,-1);
    f[0]=0;
    f[1]=0;
    f[2]=2.0;
    cl(e,0);
    e[2]=0.5;
    cl(p,0);
    p[0]=1;
    p[1]=1;
    For(i,2,1001){
        p[i]=p[i-1]/(double)i;
    }
    For(i,3,1001){
        double tmp=p[i];
        For(j,1,i-2+1){
            tmp+=e[i-j]*p[j];
        }
        e[i]=1-tmp;
    }
    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        cin>>n;
        int ct=0;
        rep(i,n){
            int tmp;
            cin>>tmp;
            if (tmp!=i+1)
                ct++;
        }

        // output
        //cout << "Case #"<<caseId<<": "<<calc(ct)<<"\n";
        printf("Case #%d: %.6f\n",caseId,calc(ct));
	}
    //rep(i,1001) {printf("Case #%d: %.6f\n",i,calc(i));}
    return 0;
}