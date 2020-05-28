#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

void solve(int p1) {
    printf("Case #%d: ",p1);
    int hd,ad,hk,ak,b,d;
    scanf("%d %d %d %d %d %d",&hd,&ad,&hk,&ak,&b,&d);
    int res=1000000000;
    For(deb,101) For(buff,101) {
        int sd=ad,sk=ak,zd=hd,zk=hk;
        int pocet=0;
        For(i,deb) {
            if(pocet > 500) break;
            pocet++;
            if(zd-(sk-d) <= 0) {
                i--;
                zd=hd-sk;
                continue;
            }
            sk-=d;
            zd-=sk;
        }
        For(i,buff) {
            if(pocet > 500) break;
            pocet++;
            if(zd-sk <= 0) {
                i--;
                zd=hd-sk;
                continue;
            }
            sd+=b;
            zd-=sk;
        }
        while(zk > 0) {
            if(pocet > 500) break;
            pocet++;
            if(zk-sd <= 0) {
                break;
            }
            if(zd-sk <= 0) {
                zd=hd-sk;
                continue;
            }
            zk-=sd;
            zd-=sk;
        }
        if(pocet > 500) continue;
        res=min(res,pocet);
    }
    if(res == 1000000000) printf("IMPOSSIBLE\n");
    else printf("%d\n",res);
}

int main() {
    int t1;
    scanf("%d",&t1);
    For(i,t1) solve(i+1);
}
