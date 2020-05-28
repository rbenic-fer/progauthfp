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

double M[21][1100000];

double rek(int n, int a) {
    if(a==(1<<n)-1) return 0;
    if(M[n][a]>-0.5) return M[n][a];
    vector<int> K; K.resize(n,0);
    For(i,n) if(a&(1<<i)) K[i]=1;
    reverse(K.begin(),K.end());
    double res=0;
    For(i,n) {
        int kolko=0;
        int kde=i;
        while(K[kde]==1) {kolko++; kde=(kde+1)%n;}
        //printf("!%d %d: %d %d\n",n,a,kolko,kde);
        //printf("%d: %d %d\n",a,kde,a^(1<<(n-kde-1)));
        res+=(n-kolko+rek(n,a^(1<<(n-kde-1))))/(double)n;
    }
    //printf("%d %d: %0.9lf\n",n,a,res);
    return M[n][a]=res;
}

int main() {
    For(i,21) For(j,1100000) M[i][j]=-1;
    int t;
    scanf("%d ",&t);
    For(i1,t) {
        string s;
        getline(cin,s);
        int cis=0;
        For(i,s.length()) {cis*=2; if(s[i]=='X') cis+=1;}
        printf("Case #%d: %0.9lf\n",i1+1,rek(s.length(),cis));
    }
return 0;
}
