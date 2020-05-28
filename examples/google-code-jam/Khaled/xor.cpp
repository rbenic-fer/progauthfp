#include<stdio.h>
int main(){
    int k=0,i,max,t,n,m,add,co=0;
    freopen("C-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        add=0;
        co=0;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            add=add^a[i];
            co+=a[i];
        }
        if(add!=0) printf("Case #%d: NO\n",++k);
        else{
        max=a[0];
        for(i=1;i<n;i++)
            if(a[i]<max) max=a[i];
        printf("Case #%d: %d\n",++k,co-max);
        }
    }
    return 0;
}
