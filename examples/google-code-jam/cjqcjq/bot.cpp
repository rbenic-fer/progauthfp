#include <stdio.h>
#include <vector>

using namespace std;

const int N=101;

int main(){
    int curO, curB, nextO, nextB;
    int cas,ic,n;
    scanf("%d",&cas);
    for(ic=1;ic<=cas;ic++){
        curO=curB=1;
        vector<int> So;
        vector<int> Sb;
        vector<char> Sc;
        So.clear();
        Sb.clear();
        Sc.clear();
        scanf("%d",&n);
        char str[2];
        int s;
        for(int i=0;i<n;i++){
            scanf("%s%d",str,&s);
            Sc.push_back(str[0]);
            if(str[0]=='O') So.push_back(s);
            else Sb.push_back(s);
        }
        So.push_back(100000);
        Sb.push_back(100000);
        int ib,io,in;
        in=ib=io=0;
        nextB=Sb[0];
        nextO=So[0];
        int ans=0;
        while(in<n){
            if(Sc[in]=='O'){
                if(curB!=nextB){
                    if(curB<nextB) curB++;
                    else curB--;
                }
                if(curO==nextO){
                    io++;
                    nextO=So[io];
                    in++;
                }else{
                    if(curO<nextO) curO++;
                    else curO--;
                }
            }else{
                if(curO!=nextO){
                    if(curO<nextO) curO++;
                    else curO--;
                }
                if(curB==nextB){
                    ib++;
                    nextB=Sb[ib];
                    in++;
                }else{
                    if(curB<nextB) curB++;
                    else curB--;
                }
            }
            ans++;
        }
        printf("Case #%d: %d\n",ic,ans);
    }
    return 0;
}
