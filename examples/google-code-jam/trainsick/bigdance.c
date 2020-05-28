
#include <stdio.h>

#define MAXN 1000

int N,S,P;
int score[MAXN];



void readstuff(void) {
    int i;
    scanf("%d %d %d",&N,&S,&P);
    for (i=0;i<N;i++) scanf("%d",score+i);
}

int normscore(int score) {
    if (score % 3==0) return score/3;
    else return score/3+1;
}

int surprisescore(int score) {
    if (score==0) return 0;
    if (score % 3==2) return score/3+2;
    else return score/3+1;
}

int min(int a, int b) {
    return a<b ? a : b;
}

int dance(void) {
    int maybe=0;
    int surething=0;
    int noway=0;
    int i,surprise,norm;
    readstuff();
    for (i=0;i<N;i++) {
        surprise=surprisescore(score[i]);
        norm=normscore(score[i]);
        if (norm>=P) surething++;
        else if (surprise<P) noway++;
        else maybe++;
    }
    return surething+min(maybe,S);
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=0;i<tc;i++) {
        printf("Case #%d: ",i+1);
        printf("%d\n",dance());
    }
    return 0;
}
