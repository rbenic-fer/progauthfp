#include <stdio.h>

int main(){
    int cas,ic;
    scanf("%d",&cas);
    for(ic=1;ic<=cas;ic++){
        int n=0;
        scanf("%d",&n);
        int xsum=0;
        int sum=0;
        int min=10000000;
        for(int i=0;i<n;i++){
            int c=0;
            scanf("%d",&c);
            sum+=c;
            xsum^=c;
            if(c<min) min=c;
        }
        if(xsum==0){
            printf("Case #%d: %d\n",ic,sum-min);
        }else{
            printf("Case #%d: NO\n",ic);
        }
    }
    return 0;
}
