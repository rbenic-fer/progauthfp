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

char cel[105][105];
const int n=100;
bool move()
{
    char celn[105][105];
    memset(celn,0,sizeof(celn));
    For(a,1,n+1){
        For(b,1,n+1){
            if (cel[a-1][b]&&cel[a][b-1])
                celn[a][b]=1;
        }
    }
    For(a,1,n+1){
        For(b,1,n+1){
            if (!cel[a-1][b]&&!cel[a][b-1])
                celn[a][b]=-1;
        }
    }
    For(a,1,n+1){
        For(b,1,n+1){
            if (celn[a][b]==1)
                cel[a][b]=1;
            else if (celn[a][b]==-1)
                cel[a][b]=0;
        }
    }
    For(a,1,n+1){
        For(b,1,n+1){
            if (cel[a][b])
                return true;
        }
    }
    return false;
}

int main()
{
//	freopen("test.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        memset(cel,0,sizeof(cel));
        int R=0;
	    scanf("%d",&R);
        rep(i,R){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            For(a,x1,x2+1){
                For(b,y1,y2+1){
                    cel[a][b]=1;
                }
            }
        }
        int cc=1;
        while(move()){
            cc++;
        }
       
        cout << "Case #"<<caseId<<": "<<cc<<"\n";


	}
    return 0;
}