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

int m,n;
vector<int> P;
vector<string> S;
int maxi,poc;

int sprav(vector<string> A) {
    vector<vector<pair<char,int> > > T;
    T.resize(1);
    For(i,A.size()) {
        int kde=0;
        For(j,A[i].length()) {
            bool t=false;
            For(k,T[kde].size()) {
                if(A[i][j]==T[kde][k].first) {kde=T[kde][k].second; t=true; break;}
            }
            if(t) continue;
            T[kde].push_back(mp(A[i][j],T.size()));
            vector<pair<char,int> > pom;
            kde=T.size();
            T.push_back(pom);
        }
    }
    return T.size();
}

void zrataj() {
    vector<vector<string> > O; O.resize(n);
    For(i,m) O[P[i]].push_back(S[i]);
    For(i,n) if(O[i].size()==0) return;
    int pocet=0;
    For(i,n) pocet+=sprav(O[i]);
    if(maxi<pocet) {maxi=pocet; poc=1;}
    else if(maxi==pocet) poc++;
}

void prirad(int k) {
    if(k==m) {
        zrataj();
        return;
    }
    For(i,n) {
        P[k]=i;
        prirad(k+1);
    }
}

void solve(int num) {
    maxi=-1; poc=0;
    scanf("%d %d",&m,&n);
    char C[15];
    S.clear(); S.resize(m); P.resize(m);
    For(i,m) {scanf(" %s",C); S[i]=C;}
    prirad(0);
    printf("Case #%d: %d %d\n",num,maxi,poc%1000000007);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
