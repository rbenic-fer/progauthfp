#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
    for(int c=1;c<=t;c++){
        int r1,r2;
        int mat1[5][5],mat2[5][5];
        cin >> r1;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                cin >> mat1[i][j];
            }
        }
        cin >> r2;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                cin >> mat2[i][j];
            }
        }
        int count=0,ans;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                if(mat1[r1][i]==mat2[r2][j]){
                    count++;
                    ans = mat1[r1][i];
                }
            }
        }
        cout << "Case #" << c << ": ";
        if(count==1) cout << ans << endl;
        else if(count==0) cout << "Volunteer cheated!" << endl;
        else cout << "Bad magician!" << endl;
    }
}
