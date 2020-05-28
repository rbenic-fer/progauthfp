#include <stdio.h>
#include <stdint.h>

int32_t gcd(int32_t a, int32_t b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int32_t main(){
    int32_t cas, ic;
    scanf("%d",&cas);
    for(int32_t ic=1;ic<=cas;ic++){
        int32_t pd, pg;
        int64_t n;
        scanf("%lld%d%d", &n, &pd, &pg);
        bool ok=0;
        if(pg==100){
            if(pd==100) ok=1;
        }else if(pg==0){
            if(pd==0) ok=1;
        }else{
            int32_t g=gcd(pd, 100);
            int32_t d=100/g;
            //printf("g=%d, d=%d\n", g, d);
            if(d<=n) ok=1;
        }
        if(ok){
            printf("Case #%d: Possible\n", ic);
        }else{
            printf("Case #%d: Broken\n", ic);
        }
    }
    return 0;
}
