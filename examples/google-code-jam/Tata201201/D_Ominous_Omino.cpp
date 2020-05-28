#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++){
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        bool can = true;
        if(x>=7) can = false;
        if((r*c)%x>0) can =false;
        if(x>c && x>r) can = false;
        if(r+c-1 < x) can = false;
        if((x+1)/2 > min(r,c)) can = false;
        if(x==4 && !(min(r,c)>=3 && max(r,c)>=4)) can = false;
        if(x==5 && !(min(r,c)>=4 && max(r,c)>=5)) can = false;
        if(x==6 && !(min(r,c)>=5 && max(r,c)>=6)) can = false;

        printf("Case #%d: ",t);
        if(can) printf("GABRIEL\n");
        else    printf("RICHARD\n");
    }
}
