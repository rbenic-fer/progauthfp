#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int T,M,N,ans;
char peta[1005];
bool isi[1005];

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%s %d",&peta,&M);
        N = strlen(peta);
        for (int i=0;i<N;++i) isi[i] = (peta[i] == '+');
        
        ans = 0;
        for (int i=0;i<=N-M;++i) if (!isi[i]) {
            ++ans;
            for (int j=0;j<M;++j) isi[i+j] = !isi[i+j];
        }
        
        bool flag = true;
        for (int i=0;i<N && flag;++i) if (!isi[i]) flag = false;

        if (flag) printf("Case #%d: %d\n",l,ans);
        else printf("Case #%d: IMPOSSIBLE\n",l);
    }
    return 0;
}
