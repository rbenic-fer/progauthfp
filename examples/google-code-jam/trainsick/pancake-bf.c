
#include <stdio.h>

int S,K,P;
char pattern[20];

void decodePattern(void) {
    char *p=pattern;
    P=0;
    S=0;
    while (*p) {
        P*=2;
        if (*p=='-') P++;
        S++;
        p++;
    }
}

int pancake(void) {
    int i,j;
    int r=100;
    int z;
    int kbits;
    int bcnt;
    scanf("%s %d",pattern,&K);
    decodePattern();
    kbits=(1<<K)-1;
    for (i=0;i< (1<<(S-K+1));i++) {
        z=P;
        bcnt=0;
        for (j=0;j<S-K+1;j++) {
            if (i & (1<<j)) {
                z ^= kbits<<j;
                bcnt++;
            }
        }
        if (!z && bcnt<r) r=bcnt;
    }
    if (r<100) return r;
    else return -1;
}

int main(int argc, char **argv) {
    int tc,i,r;
    scanf("%d", &tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        r=pancake();
        if (r>=0) printf("%d\n",r);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
