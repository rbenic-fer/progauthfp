/*=============================================================================
#     FileName: r1_pa.c
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-04-12 10:12:56
#   LastChange: 2014-04-12 10:26:51
#      History:
=============================================================================*/
#include <stdio.h>

int main() {
    int T,CASE;
    int magic_c[4][4];
    int ans_c[4];
    int ans1,ans2;
    int i,j;
    enum Ans{
        none=0,only,many
    } ans;
    int ans_n;
    scanf("%d",&T);
    for(CASE=0;CASE<T;++CASE){
        ans=none;
        ans_n=-1;
        scanf("%d",&ans1);
        for(i=0;i<4;++i)for(j=0;j<4;++j){
            scanf("%d",&magic_c[i][j]);
        }
        for(i=0;i<4;++i) ans_c[i]=magic_c[ans1-1][i];
        scanf("%d",&ans2);
        for(i=0;i<4;++i)for(j=0;j<4;++j){
            scanf("%d",&magic_c[i][j]);
        }
        for(i=0;i<4;++i)for(j=0;j<4;++j){
            if(ans_c[i]==magic_c[ans2-1][j]) ans++,ans_n=ans_c[i];
        }
        printf("Case #%d: ",CASE+1);
        switch(ans){
            case none:printf("Volunteer cheated!");break;
            case only:printf("%d",ans_n);break;
            default:printf("Bad magician!");break;
        }
        printf("\n");
    }
    return 0;
}
