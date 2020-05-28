#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[15][15];

bool over(int x, int y, int v)
{
     int vx=0,vy=0;
     for(int i=-v; i<=v; i++)
     for(int j=-v; j<=v; j++)
     {
             if(i==-v && (j==v || j==-v)) continue;
             else if(i==v && (j==v || j==-v)) continue;
             else
             {
             vx+=j*A[y+i][x+j];
             vy+=i*A[y+i][x+j];}
             }
     if(vx==0 && vy==0) return true;
     else return false;
}

int main()
{
    int t1;
    scanf("%d ",&t1);
    for(int i1=0; i1<t1; i1++)
    {
            int r,s,d;
            scanf("%d %d %d ",&r,&s,&d);
            for(int i=0; i<r; i++){
            for(int j=0; j<s; j++)
            {
            char c=getchar();
            A[i][j]=d+c-'0';}
            getchar();
            }
            int maxi=1;
            for(int i=0; i<r; i++)
            for(int j=0; j<s; j++)
            {
                    int kam=min(i,j);
                    kam=min(kam,r-i-1);
                    kam=min(kam,s-j-1);
            for(int k=1; k<=kam; k++)
            {
                    if(over(j,i,k)) maxi=max(maxi,2*k+1);
                    }
            }
            if(maxi==1) printf("Case #%d: IMPOSSIBLE\n",i1+1);
            else printf("Case #%d: %d\n",i1+1,maxi);
            }
    return 0;
}
