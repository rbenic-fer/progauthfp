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
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define all(c) (c).begin(), (c).end() 
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

using namespace std;
const int mn=101;
bool g[mn][mn],nm[mn][mn];

int n;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    
    int Tn;
    scanf("%d", &Tn);
    for (int T = 1; T <= Tn; T++) {
        scanf("%d", &n);
        memset(g,0,sizeof(g));
        rep(i,n){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for (int x = x1; x <= x2; x++ )
            	for (int y = y1; y <= y2; y++ ){
                    g[x][y]=1;
            	}
        }
        int count=0;
        while(1){
            int c=0;
            for(int i=1;i<mn;i++)
                for(int j=1;j<mn;j++)
                    c+=g[i][j];
            if(c==0)break;
       /*     for(int i=1;i<7;i++){
                for(int j=1;j<7;j++)
                    printf("%d ",g[i][j]);
                putchar('\n');
            }
            putchar('\n');*/
            memset(nm,0,sizeof(nm));
            for(int i=2;i<mn;i++){
                nm[1][i]=g[1][i];
                if(!g[1][i-1])nm[1][i]=0;
                nm[i][1]=g[i][1];
                if(!g[i-1][1])nm[i][1]=0;
            }
            nm[1][1]=0;
            for(int i=2;i<mn;i++)
                for(int j=2;j<mn;j++){
                    if(g[i][j]){
                        nm[i][j]=g[i-1][j]|g[i][j-1];
                    }else{
                        nm[i][j]=g[i-1][j]&g[i][j-1];
                    }
                }
            memcpy(g,nm,sizeof(g));
            count++;
        }
        printf("Case #%d: ", T);
        printf("%d\n",count);
    }
    return 0;
}

