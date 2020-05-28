#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define pb push_back
#define si(x) (x).size()
#define MAX 105
vector<char> vec;
int c,d,j;
char b1[40][3],b2[30][2];
void combin(){
    //printf("i am combine\n");
    if(si(vec)>=2){
        for(j=0;j<c;j++){
        if((vec[si(vec)-1]==b1[j][0] && vec[si(vec)-2]==b1[j][1]) ||(vec[si(vec)-1]==b1[j][1] && vec[si(vec)-2]==b1[j][0])){
            vec.pop_back();
            vec.pop_back();
            vec.pb(b1[j][2]);
        }
        }
    }
}
void oppos(){
    int i;
    bool fou=false;
    if(si(vec)>=2){
        for(j=0;j<d;j++){
        for(i=0;i<si(vec);i++){
            if(vec[i]==b2[j][0]){
                 fou=true;
                 break;
            }
        }
        if(fou){
            i++;
            for(;i<si(vec);i++){
                if(vec[i]==b2[j][1]){
                    vec.clear();
                    break;
                }
            }
        }
        fou=false;
        for(i=0;i<si(vec);i++){
            if(vec[i]==b2[j][1]){
                 fou=true;
                 break;
            }
        }
        if(fou){
            i++;
            for(;i<si(vec);i++){
                if(vec[i]==b2[j][0]){
                    vec.clear();
                    break;
                }
            }
        }
    }
    }
}
int main(){
    char s[MAX];
    int t,i,n,k=0;
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&c);
        for(i=0;i<c;i++){
            scanf("%s",&b1[i]);
        }
        scanf("%d",&d);
        for(i=0;i<d;i++){
            scanf("%s",&b2[i]);
        }
        scanf("%d",&n);
            scanf("%s",&s);
        for(i=0;i<n;i++){
            vec.pb(s[i]);
            if(c) combin();
            if(d) oppos();
        }
        printf("Case #%d: [",++k);
        if(si(vec)!=0) printf("%c",vec[0]);
        for(i=1;i<si(vec);i++) printf(", %c",vec[i]);
        printf("]\n");
        vec.clear();
    }
    return 0;
}
