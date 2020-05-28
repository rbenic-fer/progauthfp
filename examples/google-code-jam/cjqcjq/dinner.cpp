#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int32_t N=2000000;
uint32_t primes[N];

uint32_t GetPrimeNumbers(uint32_t primes[],const uint32_t n){
    memset(primes,0,n*sizeof(primes[0]));
    uint32_t k=0;
    uint32_t i;
    for(i=2;i*i<n;i++){
        if(primes[i]==0){
            primes[k++]=i;
            for(uint32_t j=i*i;j<n;j+=i){
                primes[j]=1;
            }
        }
    }
    for(;i<n;i++){
        if(primes[i]==0) primes[k++]=i;
    }
    return k;
}

int32_t main(){
    int32_t cas, ic;
    scanf("%d",&cas);
    GetPrimeNumbers(primes, N);
    for(int32_t ic=1;ic<=cas;ic++){
        int64_t n;
        scanf("%lld", &n);
        int32_t ans=0;
        if(n!=1){
            ans++;
        }
        for(int32_t i=0;primes[i]<=n/primes[i];i++){
            int32_t j=0;
            int64_t curp = primes[i];
            while(curp<=n){
                curp*=primes[i];
                j++;
            }
            ans+=j-1;
        }
        printf("Case #%d: %d\n", ic, ans);
    }
    return 0;
}
