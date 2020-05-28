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


int DM[1024];
int p;

int solve(int f,int n)
{
    bool need=false;
    For(i,f,f+n){
        if (DM[i]>0){
            need=true;
            break;
        }
    }
    if (!need)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        For(i,f,f+n){
            if (DM[i]>0){
                DM[i]--;
            }
        }
        return 1+solve(f,n/2)+solve(f+n/2,n/2);
    }
}

int main()
{
//	freopen("test.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        memset(DM,0,sizeof(DM));
	    scanf("%d",&p);
        int mc=1<<p;
        rep(i,mc){
            cin>>DM[i];
            DM[i] = p-DM[i];
        }
        rep(i,mc-1){
            int tmp;
            cin>>tmp;
        }
        cout << "Case #"<<caseId<<": "<<solve(0,mc)<<"\n";

	}
    return 0;
}