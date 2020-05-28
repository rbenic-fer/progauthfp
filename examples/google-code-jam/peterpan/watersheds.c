#include <stdio.h>
#define MAXH 100
#define MAXW 100
#define MAXPATH 10000

typedef struct
{
   int i;
   int j;
} point;

int H,W,terrain[MAXH][MAXW];

point findFlow(int i, int j);

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int i,j,k,mapid,T,toBeColored;
    point p,newp,colorUs[MAXPATH];
    char basin[MAXH][MAXW],curBasin,color;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("watersheds.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("watersheds.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
       }
    fscanf(fin,"%d",&T);
       /***************
       printf("Cases: %d\n",N);
       //getchar();
       ***************/
    for (mapid=1;mapid<=T;mapid++)
    {
       fscanf(fin,"%d",&H);
       fscanf(fin,"%d",&W);
       /***************
       printf("dimensions: %dx%d\n",H,W);
       //getchar();
       ***************/
       for(i=0;i<H;i++)
       for(j=0;j<W;j++)
       {
          fscanf(fin,"%d",&(terrain[i][j]));
          /***************
          printf("terrain(%d,%d): %d\n",i,j,terrain[i][j]);
          //getchar();
          ***************/
          basin[i][j]=0;
       }
       curBasin='a'-1;
       for(i=0;i<H;i++)
       for(j=0;j<W;j++)
       if(basin[i][j]==0)
       {
          toBeColored=0;
          curBasin++;
          newp.i=i;
          newp.j=j;
          do
          {
             colorUs[toBeColored++]=p=newp;
             basin[p.i][p.j]=curBasin;
             newp=findFlow(p.i,p.j);
          }
          while(basin[newp.i][newp.j]==0);
          if(p.i!=newp.i || p.j!=newp.j)
          {
             curBasin--;
             color=basin[newp.i][newp.j];
             for(k=0;k<toBeColored;k++)
                basin[colorUs[k].i][colorUs[k].j]=color;
          }          
       }
       fprintf(fout,"Case #%d:\n",mapid);
       for(i=0;i<H;i++)
       {
          for(j=0;j<W;j++)
             fprintf(fout,"%c ",basin[i][j]);
          putc('\n',fout);
       }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

point findFlow(int i, int j)
{
    int minAlt;
    point res;
    
    res.i=i;
    res.j=j;
    minAlt=terrain[i][j];
    if(i>0)
       if(terrain[i-1][j]<minAlt)
       {
          minAlt=terrain[i-1][j];
          res.i=i-1;
          //res.j=j;
       }
    if(j>0)
       if(terrain[i][j-1]<minAlt)
       {
          minAlt=terrain[i][j-1];
          res.i=i;
          res.j=j-1;
       }
    if(j<W-1)
       if(terrain[i][j+1]<minAlt)
       {
          minAlt=terrain[i][j+1];
          res.i=i;
          res.j=j+1;
       }
    if(i<H-1)
       if(terrain[i+1][j]<minAlt)
       {
          minAlt=terrain[i+1][j];
          res.i=i+1;
          res.j=j;
       }
    return res;
}
