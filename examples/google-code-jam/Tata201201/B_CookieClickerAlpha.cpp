#include<stdio.h>


int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int x=1;x<=t;x++){
        double cost,addfarm,target;
        double totaltime=0, lasttime=0, cookiepersec;
        int count=0;
        scanf("%lf%lf%lf", &cost, &addfarm, &target);

        cookiepersec = 2;
        totaltime = target/cookiepersec;

        while(true){
            //printf("%f %f\n", lasttime, totaltime);
            cookiepersec = 2 + addfarm*count;
            double temp = lasttime + cost/cookiepersec + target/(cookiepersec+addfarm);
            if(temp<totaltime){
                totaltime = temp;
                lasttime += cost/cookiepersec;
                count++;
            }else break;
        }

        printf("Case #%d: %.7f\n",x, totaltime);

    }
}
