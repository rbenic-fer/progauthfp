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

void solve() {
    int n;
    double v,x;
    scanf("%d %lf %lf",&n,&v,&x);
    vector<pair<double,double> > A; A.resize(n);
    For(i,n) scanf(" %lf %lf",&A[i].first,&A[i].second);
    //jedno
    if(n==1 && A[0].second!=x) {printf("IMPOSSIBLE\n"); return;}
    if(n==1) {printf("%0.9lf\n",v/A[0].first); return;}
    //dve
    double res=2000000000;
    if(x==A[0].second) res=v/A[0].first;
    if(x==A[1].second) res=min(res,v/A[1].first);
    if(A[0].second==A[1].second && x==A[0].second) res=min(res,v/(A[0].first+A[1].first));
    if(x<A[0].second && x<A[1].second) {printf("IMPOSSIBLE\n"); return;}
    if(x>A[0].second && x>A[1].second) {printf("IMPOSSIBLE\n"); return;}
    double v1=v*(x-A[0].second)/(A[1].second-A[0].second);
    double v0=v-v1;
    res=min(res,max(v0/A[0].first,v1/A[1].first));
    printf("%0.9lf\n",res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) {
        printf("Case #%d: ",i+1);
        solve();
    }
}
