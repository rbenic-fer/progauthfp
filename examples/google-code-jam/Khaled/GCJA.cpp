#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int t[2];
int p[2];
char s[5];
void callO(int a){
    t[0]=max(t[0]+abs(a-p[0])+1,t[1]+1);
    p[0]=a;
}
void callB(int a){
    t[1]=max(t[1]+abs(a-p[1])+1,t[0]+1);
    p[1]=a;
}
int main(){
    int k=0,x,n,i,a;
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&x);
    while(x--){
        scanf("%d",&n);
        t[0]=t[1]=0;
        p[0]=p[1]=1;
        for(i=0;i<n;i++){
            scanf("%s%d",&s,&a);
            if(s[0]=='O') callO(a);
            else callB(a);
        }
        printf("Case #%d: %d\n",++k,max(t[0],t[1]));
    }
    return 0;
}
