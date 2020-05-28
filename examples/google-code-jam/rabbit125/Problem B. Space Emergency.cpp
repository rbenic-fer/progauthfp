#include <cstdio>
#include <cstring>
#include <cstring>

using namespace std;

int dis[1000001], cir[1000001], tol[1000001];

int main(){

    freopen("test.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, j, cas, c=0, most, n, t, cycle, ans, tmp2, tmp;
    scanf("%d", &cas) ;
    while( cas-- )
	{
        scanf("%d %d %d %d", &most, &t, &n, &cycle);
        for( i=0; i<cycle; ++i )
            scanf("%d", &cir[i]);
        for( i = 0, j = 0 ; i < n ; i++ , j++ )
		{
            if( j == cycle )  
				j = 0 ;  
            dis[i] = cir[j] ;
        }
        tol[0] = 0 ;
        
        for( i=1; i<=n; ++i )
            tol[i] = tol[i-1] + dis[i-1] ;
        ans = tol[n]*2 ;
        if( most == 2 )
		{
            for( i = 0 ; i < n ; i++ )
			{
                tmp = tol[i] * 2 ;
                if( tmp < t )
				{
                    if( tmp + dis[i]*2 <= t )   
						tmp = tmp + dis[i] * 2 ;
                    else                        
						tmp = t + ( dis[i] - ( t - tmp ) / 2 ) ;
                }
                else    
					tmp += dis[i] ;
                for( j=i+1; j<n; ++j )
				{
                    tmp2 = tmp + ((tol[j]-tol[i+1])*2) ;
                    if( tmp2 < t )
					{
                        if( tmp2 + dis[j]*2 <= t )   
							tmp2 = tmp2 + dis[j]*2;
                        else
							tmp2 = t +(dis[j]-(t-tmp2)/2) ;
                    }
                    else    
						tmp2 += dis[j] ;
                    tmp2 += ((tol[n]-tol[j+1])*2);
                    if( tmp2 < ans ) 
						ans = tmp2 ;
                }
            }
        }
        else if( most==1 ){
            for( i=0; i<n; ++i ){

                tmp = tol[i]*2;
                if( tmp < t )
				{
					if( tmp + dis[i]*2 <= t )   
						tmp = tmp + dis[i]*2;
                    else                        
						tmp = t + (dis[i]-(t-tmp)/2);
                }
                else    tmp += dis[i];
                tmp += ((tol[n]-tol[i+1])*2);
                if( tmp < ans ) ans = tmp;
            }
        }
        printf("Case #%d: %d\n", ++c, ans);
    }
    return 0;
}
