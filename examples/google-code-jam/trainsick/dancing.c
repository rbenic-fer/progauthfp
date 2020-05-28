
#include <stdio.h>

#define MAXN 6

int N,S,P;
int score[MAXN];

void readstuff(void) {
    int i;
    scanf("%d %d %d",&N,&S,&P);
    for (i=0;i<N;i++) scanf("%d",score+i);
}

int bitcount(int b) {
    int count=0;
    while (b) {
        count +=(b & 1);
        b>>=1;
    }
    return count;
}

int dance(void) {
    int S_state;
    int i;
    int max_gt_P=0;
    int gt_P;
    int cur_s=0;
    readstuff();
    //printf("\n");
    for (S_state=0;S_state<(1<<N);S_state++) {
        if (bitcount(S_state)!=S) continue;
        //printf("State=%d\n",S_state);
        gt_P=0;
        for (i=0;i<N;i++) {
            if (S_state & (1<<i)) { //surprised
                if (score[i]==0)  gt_P=-100; //cant' happen ignore state (without goto)
                else 
                if (score[i] % 3==2) cur_s=score[i]/3+2;
                else cur_s=score[i]/3+1;
            } else {
                if (score[i] % 3==0) cur_s=score[i]/3;
                else cur_s=score[i]/3+1;
            }
            //printf("%d ",cur_s);
            if (cur_s>=P) gt_P++;
        }
        //printf("\n");
        if (gt_P > max_gt_P) max_gt_P=gt_P;
    }
    //printf("answer=");
    return max_gt_P;
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
