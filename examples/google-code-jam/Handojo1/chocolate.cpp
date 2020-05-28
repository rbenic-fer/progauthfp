#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX(a,b) a = max(a,b)

using namespace std;

int dp3[105][105],dp4[105][105][105];
bool sudah3[105][105],sudah4[105][105][105];
int banyak[5];

int proses3(int j1,int j2) {
    if (j1 == 0 && j2 == 0) return 0;
    if (sudah3[j1][j2]) return dp3[j1][j2];
    sudah3[j1][j2] = true;
    
    dp3[j1][j2] = 1;
    if (j1 >= 3) MAX(dp3[j1][j2],proses3(j1-3,j2)+1);
    if (j2 >= 3) MAX(dp3[j1][j2],proses3(j1,j2-3)+1);
    if (j1 >= 1 && j2 >= 1) MAX(dp3[j1][j2],proses3(j1-1,j2-1)+1);
    
    return dp3[j1][j2];
}

int proses4(int j1,int j2,int j3) {
    if (j1 == 0 && j2 == 0 && j3 == 0) return 0;
    if (sudah4[j1][j2][j3]) return dp4[j1][j2][j3];
    sudah4[j1][j2][j3] = true;

    dp4[j1][j2][j3] = 1;
    if (j1 >= 4) MAX(dp4[j1][j2][j3], proses4(j1-4,j2,j3)+1);
    if (j2 >= 2) MAX(dp4[j1][j2][j3], proses4(j1,j2-2,j3)+1);
    if (j3 >= 4) MAX(dp4[j1][j2][j3], proses4(j1,j2,j3-4)+1);
    if (j1 >= 1 && j3 >= 1) MAX(dp4[j1][j2][j3], proses4(j1-1,j2,j3-1)+1);
    if (j1 >= 2 && j2 >= 1) MAX(dp4[j1][j2][j3], proses4(j1-2,j2-1,j3)+1);
    if (j2 >= 1 && j3 >= 2) MAX(dp4[j1][j2][j3], proses4(j1,j2-1,j3-2)+1);
    
    return dp4[j1][j2][j3];
}

int main() {
    int T,N,P;
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d %d",&N,&P);
        memset(banyak,0,sizeof(banyak));
        for (int i=1,j;i<=N;++i) {
            scanf("%d",&j);
            ++banyak[j % P];
        }
        
        int jawab;
        if (P == 2) {
            jawab = banyak[0] + (banyak[1]+1) / 2;
        } else if (P == 3) {
            jawab = banyak[0] + proses3(banyak[1],banyak[2]);
        } else if (P == 4) {
            jawab = banyak[0] + proses4(banyak[1],banyak[2],banyak[3]);
        }
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
