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

void solve(int num) {
    int n;
    scanf("%d",&n);
    vector<int> A1; A1.resize(n);
    For(i,n) scanf(" %d",&A1[i]);
    int p=0;
    int res=1000000000;
    int bin;
    For(i,n) if(A1[p]<A1[i]) p=i;
    For(k,1<<n) {
        //k=968;
        vector<pii> P1,P2;
        For(j,n) {
            if(j==p) continue;
            if(k&(1<<j)) P2.push_back(mp(A1[j],j));
            else P1.push_back(mp(A1[j],j));
        }
        sort(P1.begin(),P1.end());
        sort(P2.begin(),P2.end());
        reverse(P2.begin(),P2.end());
        vector<int> V; V.resize(n);
        int poc=0;
        For(i,P1.size()) V[P1[i].second]=poc++;
        V[p]=poc++;
        For(i,P2.size()) V[P2[i].second]=poc++;
        //For(i,n) printf("%d ",V[i]); printf("\n");
        int suc=0;
        For(i,n) For(j,n-1) {
            if(V[j]>V[j+1]) {suc++; swap(V[j],V[j+1]);}
        }
        if(res>suc) {res=suc; bin=k;}
        //break;
    }
    //For(i,n) if(bin&(1<<i)) printf("1"); else printf("0"); printf("\n");
    printf("Case #%d: %d\n",num,res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
