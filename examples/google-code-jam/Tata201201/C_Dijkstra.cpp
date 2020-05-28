#include<stdio.h>
int tab[5][5] = {
    {0,0,0,0,0},
    {0,1,2,3,4},
    {0,2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};
char encode[10]="01ijk";
int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n,rep;
        char x[10005];
        scanf("%d%d",&n,&rep);
        scanf("%s",x);
        bool cani=false,canj=false,cank=false;
        int temp = 1,run = 0, runouter=0,cur;
        bool neg=false;
        while(true){
            cur = x[run]-'i'+2;
            temp = tab[temp][cur];
            if(temp<0){
                temp *= -1;
                neg ^= true;
            }
            //printf(">> cur : %c  + temp : %c%c\n",encode[cur],(neg?'-':' '),encode[temp]);
            run++;
            if(run==n){
                run = 0;
                runouter++;
            }
            if(temp == 2 && !neg){
                cani = true;
                break;
            }
            if(runouter>rep) break;
        }
        int runb = n-1, runouterb = 0;
        bool negb = false;
        temp = 1;
        while(true){
            cur = x[runb]-'i'+2;
            temp = tab[cur][temp];
            if(temp<0){
                temp *= -1;
                negb ^= true;
            }
            //printf("<< cur : %c  + temp : %c%c\n",encode[cur],(negb?'-':' '),encode[temp]);
            runb--;
            if(runb<0){
                runb = n-1;
                runouterb++;
            }
            if(temp == 4 && !negb){
                cank = true;
                break;
            }
            if(runouterb>rep) break;
        }
        //printf("> %d %d %d %d\n",runouter,run,runouterb,runb);
        temp = 1;
        while(runouter<rep-runouterb-1 || (runouter==rep-runouterb-1 && run<=runb)){
            cur = x[run]-'i'+2;
            temp = tab[temp][cur];
            //printf(">>> %d %d %c\n", runouter,run,encode[cur]);
            if(temp<0){
                temp *= -1;
                neg ^= true;
            }
            run ++;
            if(run == n){
                run = 0;
                runouter++;
                break;
            }
        }
        int tempall = 1;
        bool negall = false;
        for(int i=0;i<n;i++){
            cur = x[i]-'i'+2;
            tempall = tab[tempall][cur];
            if(tempall<0){
                tempall *= -1;
                negall ^= true;
            }
        }
        while(runouter<rep-runouterb-1){
            temp = tab[temp][tempall];
            neg = neg^negall;
            if(temp<0){
                temp *= -1;
                neg ^= true;
            }
            runouter++;
        }
        while(runouter<rep-runouterb-1 || (runouter==rep-runouterb-1 && run<=runb)){
            cur = x[run]-'i'+2;
            temp = tab[temp][cur];
            //printf(">>> %d %d %c\n", runouter,run,encode[cur]);
            if(temp<0){
                temp *= -1;
                neg ^= true;
            }
            run ++;
            if(run == n){
                run = 0;
                runouter++;
            }
        }
        if(temp == 3 && !neg) canj = true;
        printf("Case #%d: ",t);
        if(cani && canj && cank) printf("YES\n");
        else printf("NO\n");
    }
}
