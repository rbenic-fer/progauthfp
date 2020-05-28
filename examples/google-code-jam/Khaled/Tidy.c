#include<stdio.h>
#include<string.h>


int check(long long n){

    char s[30];

    sprintf(s,"%lld",n);

    int len = strlen(s);

    if(len==1) return 1;
    int i;
    for(i=1;i<len;i++){
        if(s[i-1]>s[i]) return 0;
    }

    return 1;
}

long long process(long long n){
    char s[30];

    sprintf(s,"%lld",n);

    int len = strlen(s);
    int i,j;
    for(i=0;i<len-1;i++){
        if(s[i]>s[i+1]){
            for(j=i+1;j<len;j++) s[j]='0';
            break;
        }
    }

    sscanf(s,"%lld",&n);
    return n;
}

int main(){

    int T,k=0;
    long long n;
    scanf("%d",&T);

    while(T--){
        scanf("%lld",&n);


        while(n){
            n = process(n);
            //printf("%lld\n",n);

            if(check(n)){
                 printf("Case #%d: %lld\n",++k,n);
                 break;
            }
             n--;
        }

    }

    return 0;
}
