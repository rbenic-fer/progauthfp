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

int n;
vector<pair<pii,int> > P;

pii mv(pii a, pii b) {
    return mp(a.first-b.first,a.second-b.second);
}

ll vect(pii a, pii b) {
    return (ll)a.first*b.second-(ll)a.second*b.first;
}

ll area() {
    ll res=0;
    for(int i=1; i<P.size()-1; i++)
        res+=5ll*vect(mv(P[i].first,P[0].first),mv(P[i+1].first,P[0].first));
    return res;
}

int main() {
    int t;
    scanf("%d ",&t);
    For(i1,t) {
        P.clear();
        scanf(" %d",&n);
        ll obsah=0;
        vector<pair<pii,int> > Pom;
        For(i,n) {
            int x,y;
            scanf("%d %d ",&x,&y);
            P.push_back(mp(mp(x,y),i));
        }
        sort(P.begin(),P.end());
        do {
            ll a=area();
            if(a>obsah) {
                obsah=a;
                Pom=P;
            }
        }while(next_permutation(P.begin()++,P.end()));
        printf("Case #%d:",i1+1);
    For(i,Pom.size()) printf(" %d",Pom[i].second); printf("\n");
    }
return 0;
}
