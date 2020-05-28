#include <iostream>
#include <stdio.h>

using namespace std;
int T, r,c;
char x[100][100];
int main() {
    scanf("%d",&T);
    for(int TC=1; TC<=T;TC++){

        printf("Case #%d:\n",TC);
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++){
            scanf("%s",x[i]);
        }

        //FWD
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                if(x[i][j-1]!='?' && x[i][j]=='?'){
                    x[i][j] = x[i][j-1];
                }
            }
        }

        //BACK
        for(int i=0;i<r;i++){
            for(int j=c-2;j>=0;j--){
                if(x[i][j+1]!='?' && x[i][j]=='?'){
                    x[i][j] = x[i][j+1];
                }
            }
        }

        //UPPER
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(x[i-1][j]!='?' && x[i][j]=='?'){
                    x[i][j] = x[i-1][j];
                }
            }
        }

        //LOWER
        for(int i=r-2;i>=0;i--){
            for(int j=0;j<c;j++){
                if(x[i+1][j]!='?' && x[i][j]=='?'){
                    x[i][j] = x[i+1][j];
                }
            }
        }

        for(int i=0;i<r;i++){
            printf("%s\n",x[i]);
        }
    }

    return 0;
}