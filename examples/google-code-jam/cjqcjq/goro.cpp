#include <stdio.h>

const int N=1001;

double C[N][N];
double F[N];
double M[N];
double ans[N];
int main(){
    F[0]=1.0;
    for(int i=1;i<N;i++){
        F[i] = F[i-1]*i;
    }
    M[0]=1.0;
    M[1]=0.0;
    for(int i=2;i<N;i++){
        M[i] = (i-1)*(M[i-1]+M[i-2]);
    }
    for(int i=0;i<N;i++){
        C[i][i]=C[i][0]=1.0;
    }
    for(int i=2;i<N;i++){
        for(int j=1;j<i;j++){
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
    ans[0] = ans[1] = 0.0;
    ans[2] = 2.0;
    for(int i=3;i<N;i++){
        double c=1.0;
        for(int j=2;j<i;j++){
            c+=(C[i][j]*M[j]/F[i])*ans[j];
        }
        ans[i]=c/(1.0-(M[i]/F[i]));
    }
    int cas,ic;
    scanf("%d",&cas);
    for(ic=1;ic<=cas;ic++){
        int n=0;
        scanf("%d",&n);
        int cc=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x!=i+1) cc++;
        }
        printf("Case #%d: %lf\n", ic, cc);
    }
    return 0;
}
