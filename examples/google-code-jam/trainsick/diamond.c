
#include <stdio.h>

typedef struct node {
    struct node *next;
    struct node *head;
    int ptcnt;
    int linkcnt;
} node;

node class[1010];
int N;
node *join(node *a, node *b) {
    node *t;
    node *an,*bn,*q;
    if (b->ptcnt > a->ptcnt) {
        t=a;a=b;b=t;
    }
    a->ptcnt+=b->ptcnt;
    a->linkcnt+=b->linkcnt;
    q=b;
    do {
        q->head=a;
        q=q->next;
    } while (q!=b);
    an=a->next;
    bn=b->next;
    a->next=bn;
    b->next=an;
    return a;
}

void diamond(void) {
    int i;
    int M,j,k;
    node *ih,*jh;
    scanf("%d",&N);
    for (i=1;i<=N;i++) {
        class[i].next=class+i;
        class[i].head=class+i;
        class[i].ptcnt=1;
        class[i].linkcnt=0;
    }
    for (i=1;i<=N;i++) {
        scanf("%d",&M);
        ih=class[i].head;
        ih->linkcnt += M;
        for (j=0;j<M;j++) {
            scanf("%d",&k);
            jh=class[k].head;
            if (jh!=ih) {
                ih=join(jh,ih);
            }
        }
    }
    for (i=1;i<=N;i++) {
        if (class[i].head!=class+i) continue;
        if (class[i].ptcnt!=class[i].linkcnt+1) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main(int argc, char **argv) {
    int tc,i;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        diamond();
    }
    return 0;
}
