#include<stdio.h>
int seq[1005],i,n,t,a=0,b=0,vala=0,valb=0,maxx;
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
void dfs(int depth){
    //printf("> %d %d %d %d %d\n",depth,a,b,vala,valb);
    if(a==b&&vala>0&&valb>0){
        if(max(vala,valb)>maxx)maxx= max(vala,valb);
    }
    if(depth>=n){
        return;
    }
    int tm;
    vala+=seq[depth];
    valb-=seq[depth];
    a=a^seq[depth];
    b=b^seq[depth];
    dfs(depth+1);
    vala-=seq[depth];
    valb+=seq[depth];
    a=a^seq[depth];
    b=b^seq[depth];
    
    dfs(depth+1);
}
int main(){
    freopen("C-small-attempt5.in","r",stdin);
    freopen("C-small-attempt5.out","w",stdout);
    scanf("%d",&t);
    int j,x;
    for(i=0;i<t;i++){
        maxx=0;
        a=0;
        b=0;
        vala=0;
        valb=0;
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&seq[j]);
            valb+=seq[j];
            b=b^seq[j];
            //printf("%d %d %d\n",j,valb,b);
        }
        dfs(0);
        printf("Case #%d: ",i+1);
        if(maxx>0) printf("%d\n",maxx);
        else printf("NO\n");
    }
    
    
    
    
    
    scanf(" ");
    return 0;
}
