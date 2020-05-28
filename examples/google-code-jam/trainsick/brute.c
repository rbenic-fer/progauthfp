
#include <stdio.h>

char cake[13][13];
int WD,HT;
int alphabet;
int solved;

void calcalphabet(void) {
    int x,y;
    for (y=0;y<HT;y++) {
        for (x=0;x<WD;x++) {
            alphabet |= 1<<(cake[y][x] & 31);
        }
    }
}

void printsolution(void) {
    int x,y;
    for (y=0;y<HT;y++) {
        for (x=0;x<WD;x++) {
            printf("%c", cake[y][x]);
        }
        printf("\n");
    }
}

void issolved(void) {
    int y,x,ch;
    int minx[27],miny[27];
    int maxx[27],maxy[27];
    for (ch=1;ch<=26;ch++) {
        minx[ch]=miny[ch]=100;
        maxx[ch]=maxy[ch]=-1;
    }
    for (y=0;y<HT;y++) {
        for (x=0;x<WD;x++) {
            ch=(cake[y][x] & 31);
            if (x<minx[ch]) minx[ch]=x;
            if (y<miny[ch]) miny[ch]=y;
            if (x>maxx[ch]) maxx[ch]=x;
            if (y>maxy[ch]) maxy[ch]=y;
        }
    }
    for (ch=1;ch<=26;ch++) {
        if (maxx[ch]==-1) continue;
        for (y=miny[ch]; y<=maxy[ch];y++) {
            for (x=minx[ch]; x<=maxx[ch]; x++) {
                if (cake[y][x]!=64+ch) {solved=0; return;}
            }
        }
    }
    solved=1;
    printsolution();
}

void permute(int x, int y) {
    int ch;
    if (x==WD) {x=0; y++; }
    if (y==HT) {issolved(); return; }
    if (cake[y][x]!='?') {permute(x+1,y); return; }
    for (ch=1;ch<=26;ch++) {
        if ((alphabet & (1<<ch))==0) continue;
        cake[y][x]=64+ch;
        permute(x+1,y);
        if (solved) return;
    }
    cake[y][x]='?';
}

void problem(void) {
    int i;
    alphabet=0;
    solved=0;
    scanf("%d %d", &HT, &WD);
    for (i=0;i<HT;i++) {
        scanf("%s", &(cake[i][0]));
    }
    calcalphabet();
    permute(0,0);
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d", &tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d:\n",i);
        problem();
    }
    return 0;
}
