#include<stdio.h>
#include<math.h>
int t,st,en;
char a[1000];
bool ispal(int x){
    int i,last=0;
    while(x>0){
        a[last]=x%10;
        x/=10;
        last++;
    }
    int mid=last/2;
    for(i=0;i<mid;i++){
        if(a[i]!=a[last-i-1]) return false;
    }
    return true;
}
bool isfair(int x){
    int y=(int)sqrt(x);
    if(y*y==x){
        if(ispal(y)) return true;
        return false;
    }else return false;
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    int i,j,k,count;
    bool chk;
    for(k=1;k<=t;k++){
        scanf("%d%d",&st,&en);
        count=0;
        for(i=st;i<=en;i++){
            chk=false;
            if(ispal(i)){
                if(isfair(i)){
                    chk=true;
                    //printf("> %d\n",i);
                }
            }
            if(chk) count++;
        }
        printf("Case #%d: %d\n",k,count);
    }
    
    
    
    
    scanf(" ");
    return 0;
}
