#include <cstdio>
#include <cmath>
double x[30],y[30],r[30];
int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++){
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
        }
        if( n==1)  printf("Case %d: %.6lf\n",t, r[0]);
        else if( n ==2) printf("Case %d: %.6lf\n",t,(r[0] > r[1]?r[0] : r[1]));
        else {
            double d, temp ,min = 1e100;
            d = sqrt((x[1] - x[0])*(x[1] - x[0]) + (y[1] - y[0])*(y[1] - y[0]));
            temp = (d + r[0] + r[1])/2;
            if( temp < r[2]) temp = r[2];
            if(min > temp) min = temp ;
            d = sqrt((x[2] - x[0])*(x[2] - x[0]) + (y[2] - y[0])*(y[2] - y[0]));
            temp = (d + r[0] + r[2])/2;
            if( temp < r[1]) temp = r[1];
            if(min > temp) min = temp ;
            d = sqrt((x[2] - x[1])*(x[2] - x[1]) + (y[2] - y[1])*(y[2] - y[1]));
            temp = (d + r[2] + r[1])/2;
            if( temp < r[0]) temp = r[0];
            if(min > temp) min = temp ;
            printf("Case %d: %.6lf\n",t,min);
        }
    }
}