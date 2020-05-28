#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

double D,X[1005],S[1005];
int N,T;

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%lf %d",&D,&N);
        double waktu = 0;
        for (int i=0;i<N;++i) {
            scanf("%lf %lf",&X[i],&S[i]);
            waktu = max(waktu,(D-X[i])/S[i]);
        }
        
        printf("Case #%d: %.6lf\n",l,D / waktu);
    }
    return 0;
}
