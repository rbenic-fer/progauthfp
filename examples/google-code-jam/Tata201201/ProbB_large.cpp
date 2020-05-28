#include<stdio.h>
int t,x[1000][1000],y[1000][1000],r,c;
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    int i,j,k,c1,c2,a;
    for(k=1;k<=t;k++){
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%d",&x[i][j]);
                y[i][j]=100;
            }
        }
        for(a=99;a>0;a--){
            for(i=0;i<r;i++){
                c1=0; c2=0;
                for(j=0;j<c;j++){
                    if(x[i][j]<=a) c1++;
                    else c2++;
                }
                //printf("> A %d %d %d %d\n",i,j,c1,c2);
                if(c2==0){
                    for(j=0;j<c;j++){
                        y[i][j]=a;
                    }
                }
            }
            
            for(j=0;j<c;j++){
                c1=0; c2=0;
                for(i=0;i<r;i++){
                    if(x[i][j]<=a) c1++;
                    else c2++;
                }
                //printf("> B %d %d %d %d\n",i,j,c1,c2);
                if(c2==0){
                    for(i=0;i<r;i++){
                        y[i][j]=a;
                    }
                }
            }
        }
        
        c1=0;c2=0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                //printf("%d ",y[i][j]);
                if(y[i][j]==x[i][j]) c2++;
                else c1++;
            }
            //printf("\n");
        }
        //printf("==== %d %d \n",c1,c2);
        printf("Case #%d: ",k);
        if(c1!=0) printf("NO\n");
        else printf("YES\n");
        
    }
    
    
    
    
    scanf(" ");
    return 0;
}
