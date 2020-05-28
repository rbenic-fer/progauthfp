#include<stdio.h>
#include<queue>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> II;
typedef pair<long long,II > III;
bool cmp(III a,III b){
    if(a.second.first < b.second.first) return true;
    else if(a.second.first == b.second.first){
        return a.first < b.first;
    }
    return false;
}
III temp;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm (int a,int b){
    int g = gcd(a,b);
    long long x = a/g*b;
    if(x>1500000000 || x <= 0) return 1000000000;
    return a/g * b;
}
int interval[1005];
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt = 1;tt<=T;tt++){
        int b,n;
        scanf("%d%d",&b,&n);
        priority_queue<III,vector<III>,greater<III> > use;
        int l = 1;
        for(int i=1;i<=b;i++){
            int x;
            scanf("%d",&x);
            use.push(III(x,II(i,x)));
            l = lcm(l,x);
            interval[i] = x;
        }
        if(n<=b){
            temp.second.first = n;
        }else{
            int xx = 0;
            for(int i=1;i<=b;i++){
                xx += l/interval[i];
            }
            n = (n-b-1)%xx;
            /*
            for(int i=0;i<b;i++){
                printf("%d %d %d\n",use.top().first, use.top().second.first, use.top().second.second);
                use.pop();
            }
            */
            //printf("%d\n",n);
            for(int i=0;i<=n;i++){
                //if(i%10000000 == 0) printf("> %d\n",i);
                temp = use.top();
                temp.first += temp.second.second;
                use.pop();
                use.push(temp);
            }
        }
        printf("Case #%d: %d\n",tt,temp.second.first);
    }

}
