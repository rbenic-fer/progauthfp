// --- BBG v2.1b ---
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<map>
#include<set>
#include<string.h>
#include<string>
//
using namespace std;
//
//#define ONLINE_JUDGE BOBOGEI
#ifdef ONLINE_JUDGE
#define PP ;
#else
#define PP system("pause");
#endif
#define REP(n,i) for(int (i)=0;(i)<(n);(i)++)
#define CDREP(n,i) for(int (i)=((n)-1);(i)>=0;(i)--)
#define FOR(s,e,i) for(int (i)=(s);(i)<(e);(i)++)
#define _SZ(n) memset((n),0,sizeof(n))
#define _SMO(n) memset((n),-1,sizeof(n))
#define _MC(n,m) memcpy((n),(m),sizeof(n))
#define _F first
#define _S second
#define _MP(a,b) make_pair((a),(b))
#define _PB(a) push_back((a))
//
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef vector<int> vint;
typedef pair<int,int> pii;
const int INF = 1029384756;
const double PI = acos(-1);
const double EPS = 0.0000000304;
//
typedef pair<i64,i64> pll;
const int MAX = 12312;
//
int T;
int N;
i64 D;
pll ip[MAX];
deque<pll> dq;
//
void aozora()
{
    dq.clear();
}
//
int main()
{
    freopen("cj/A.in","r",stdin);
    freopen("cj/A.out","w",stdout);
    scanf("%d",&T);
    REP(T,chiisanatenohira)
    {
        aozora();
        scanf("%d",&N);
        bool ok=0;
        i64 kd;
        REP(N,i)
        {
            i64 d,l;
            scanf("%I64d%I64d",&d,&l);
            if(!i)
            {
                kd=d*2;
            }
            ip[i]=_MP(d,l);
        }
        scanf("%I64d",&D);
        dq._PB(_MP(ip[0]._F,ip[0]._F));

        sort(ip,ip+N);
        REP(N,i)
        {
            if(kd>=D)
            {
                ok=1;
                break;
            }
            while(dq.size())
            {
                pll nw=dq.front();
                if(nw._F+nw._S>=ip[i]._F)
                {
                    break;
                }else
                {
                    dq.pop_front();
                }
            }
            if(!dq.size())
            {
                break;
            }
            i64 nd=min(ip[i]._S,ip[i]._F-dq.front()._F);
            //printf("%I64d,",ip[i]._F-dq.front()._F);
            if(nd+ip[i]._F>=D)
            {
                ok=1;
                break;
            }
            if(nd+ip[i]._F>dq.back()._F+dq.back()._S)
            {
                dq._PB(_MP(ip[i]._F,nd));
            }
        }
        printf("Case #%d: ",chiisanatenohira+1);
        if(ok)
        {
            puts("YES");
        }else
        {
            puts("NO");
        }
    }

}
