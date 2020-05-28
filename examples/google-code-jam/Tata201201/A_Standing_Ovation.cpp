#include<stdio.h>
int T,n;
char x[2000];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        scanf("%s",x);
        int sum = 0,cur,add=0;
        for(int i=0;i<=n;i++){
            cur = x[i]-'0';
            if(cur>0){
                if(sum<i){
                    add += i-sum;
                    sum = i;
                }
                sum+=cur;
            }
        }
        printf("Case #%d: %d\n",t,add);
    }
}
