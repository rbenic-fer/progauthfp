#include<cstdio>
#include<cstring>
#define M 110
struct stock{
    int p[26];
}s[M];

bool g[M][M],flag[M];
int my[M];

bool isUp(stock a,stock b,int k)
{
    for(int i=0;i<k;i++)
        if(a.p[i]<=b.p[i])
            return false;
    return true;
}

bool path(int s,int n)
{
    for(int i=0;i<n;i++){
        if(!flag[i]&&g[s][i]){
            flag[i]=1;
            if(my[i]==-1||path(my[i],n)){
                my[i]=s;
                return true;
            }
        }
    }
    return false;
}

int maxMatch(int n)
{
    int ans=0;
    memset(my,-1,sizeof(my));
    for(int i=0;i<n;i++){
        memset(flag,0,sizeof(flag));
        if(!path(i,n))ans++;
    }
    return ans;
}

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("c.out","w",stdout);

    int T,k,n;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                scanf("%d",&s[i].p[j]);
            }
        }
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]= isUp(s[i],s[j],k);
            }
        }
        printf("Case #%d: %d\n",t,maxMatch(n));
    }
    return 0;
}