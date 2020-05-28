#include <cstdio>
char d[5000][16];

bool match(char s[],char t[])
{
    int i = 0 , j = 0;
    while(t[j]){
        bool find = false ;
        if(s[i] == '('){
            while(s[i] != ')'){
                if(s[i] ==t[j]){
                    find = true ;
                }
                i ++;
            }
        }
        else {
            if(s[i] ==t[j]){
                find = true;
            }
        }
        i++,j++;
        if(!find){
            return false ;
        }
    }
    return true;
}

int main()
{
    int L,D,N;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d%d%d",&L,&D,&N);
    for(int i=0;i<D;i++){
        scanf("%s",d[i]);
    }
    char s[10000];
    for(int T=1;T<=N;T++){
        scanf("%s",s);
        int sum = 0 ;
        for(int i=0;i<D;i++){
            if(match(s,d[i])){
                sum++;
            }
        }
        printf("Case #%d: %d\n",T,sum);
    }
    return 0;
}