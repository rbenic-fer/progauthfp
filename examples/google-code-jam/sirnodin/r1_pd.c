/*=============================================================================
#     FileName: r1_pd.c
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-04-12 15:12:25
#   LastChange: 2014-04-12 15:44:02
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1011
#define DEBUG(m) printf(m)
double w_Naomi[MAX_N];
double w_Ken[MAX_N];
int CASE,T;
int i;
int score_d_w,score_w;
int N;
int p1,p2;
int compar_double(const void * a,const void * b){
    double a_v=*(double *)(a);
    double b_v=*(double *)(b);
    if(a_v>b_v) return 1;
    else if(a_v<b_v) return -1;
    return 0;
}
int main() {
    scanf("%d",&T);
    for(CASE=0;CASE<T;++CASE) {
        scanf("%d",&N);
        for(i=0;i<N;++i){
            scanf("%lf",w_Naomi+i);
        }
        for(i=0;i<N;++i){
            scanf("%lf",w_Ken+i);
        }
        qsort(w_Naomi,N,sizeof(double),compar_double);
        qsort(w_Ken,N,sizeof(double),compar_double);
        p1=p2=0;
        score_w=score_d_w=0;
        while(p1<N && p2<N) {
            if(w_Naomi[p1]>w_Ken[p2]) {
                p2++;score_w++;
            }
            else {
                p1++;p2++;
            }
        }
        p1=p2=0;
        while(p1<N && p2<N){
            if(w_Naomi[p1]>w_Ken[p2]) {
                p1++;p2++;score_d_w++;
            }
            else {
                p1++;
            }
        }
        printf("Case #%d: %d %d\n",CASE+1,score_d_w,score_w);
    }
    return 0;
}
