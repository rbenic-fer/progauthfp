
#include <cstdio>
#include <cstring>

#define MAX 110

int h[MAX][MAX],f[MAX][MAX],n,m;
bool v[MAX][MAX];
char c[MAX][MAX];

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&h[i][j]);
        }
    }
}

void pretreatment()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int lowest = h[i][j];
            f[i][j] = 0;
            if(i-1>=0 && h[i-1][j]<lowest){
                lowest = h[i-1][j];
                f[i][j] = 1;
            }
            if(j-1>=0 && h[i][j-1]<lowest){
                lowest = h[i][j-1];
                f[i][j] = 2;
            }
            if(j+1<m && h[i][j+1]<lowest){
                lowest = h[i][j+1];
                f[i][j] = 3;
            }
            if(i+1<n && h[i+1][j]<lowest){
                lowest = h[i+1][j];
                f[i][j] = 4;
            }
        }
    }
}

void search(int i,int j,char ch)
{
    v[i][j] = true;
    c[i][j] = ch;
    switch (f[i][j]){
        case 1:
            if(!v[i-1][j]){
                search(i-1,j,ch);
            }
            break;
        case 2:
            if(!v[i][j-1]){
                search(i,j-1,ch);
            }
            break;
        case 3:
            if(!v[i][j+1]){
                search(i,j+1,ch);
            }
            break;
        case 4:
            if(!v[i+1][j]){
                search(i+1,j,ch);
            }
            break;
    }
    if(i-1>=0 && f[i-1][j] == 4 && !v[i-1][j]){
        search(i-1,j,ch);
    }
    if(j-1>=0 && f[i][j-1] == 3 && !v[i][j-1]){
        search(i,j-1,ch);
    }
    if(j+1<m && f[i][j+1] == 2 && !v[i][j+1]){
        search(i,j+1,ch);
    }
    if(i+1<n && f[i+1][j] == 1 && !v[i+1][j]){
        search(i+1,j,ch);
    }
}

void make()
{
    memset(v,0,sizeof(v));
    char ch = 'a';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!v[i][j]){
                search(i,j,ch);
                ch++;
            }
        }
    }
}

void output(int t)
{
    printf("Case #%d:\n",t);
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            printf("%c ",c[i][j]);
        }
        printf("%c\n",c[i][m-1]);
    }
}

int main()
{
    int T;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for(int t = 1; t<=T;t++){
        input();
        pretreatment();
        make();
        output(t);
    }
    return 0;
}