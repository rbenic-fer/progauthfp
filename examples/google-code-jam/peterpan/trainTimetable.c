#include <stdio.h>

char items[15][101];

void quickSort(int a[],int l,int r);
int partition(int a[],int l,int r);

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int N,n,NA,NB,T,i,j,trainsAd[100],trainsAa[100],trainsBd[100],trainsBa[100],tra,trb;
    char ch;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("trainTimetable.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("trainTimetable.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
       }
    fscanf(fin,"%d\n",&N);
    for (n=1;n<=N;n++){
       fscanf(fin,"%d",&T);
       fscanf(fin,"%d",&NA);
       fscanf(fin,"%d",&NB);
       /***************
       printf("T: %d\nNA: %d\nNB: %d\n",T,NA,NB);
       getchar();
       ***************/
       for (i=0;i<NA;i++){
          fscanf(fin,"%d",&j);
          trainsAd[i]=60*j;
          fscanf(fin,"%c",&ch);
          fscanf(fin,"%d",&j);
          trainsAd[i]+=j;
          fscanf(fin,"%d",&j);
          trainsAa[i]=60*j;
          fscanf(fin,"%c",&ch);
          fscanf(fin,"%d",&j);
          trainsAa[i]+=j+T;
          }
       for (i=0;i<NB;i++){
          fscanf(fin,"%d",&j);
          trainsBd[i]=60*j;
          fscanf(fin,"%c",&ch);
          fscanf(fin,"%d",&j);
          trainsBd[i]+=j;
          fscanf(fin,"%d",&j);
          trainsBa[i]=60*j;
          fscanf(fin,"%c",&ch);
          fscanf(fin,"%d",&j);
          trainsBa[i]+=j+T;
          }
       quickSort(trainsAd,0,NA-1);
       quickSort(trainsAa,0,NA-1);
       quickSort(trainsBd,0,NB-1);
       quickSort(trainsBa,0,NB-1);
       /***************
       printf("A dep\n");
       for (i=0;i<NA;i++)
           printf("%d:%d\n",trainsAd[i]/60,trainsAd[i]%60);
       printf("A ar\n");
       for (i=0;i<NA;i++)
           printf("%d:%d\n",(trainsAa[i]-T)/60,(trainsAa[i]-T)%60);
       printf("B dep\n");
       for (i=0;i<NB;i++)
           printf("%d:%d\n",trainsBd[i]/60,trainsBd[i]%60);
       printf("B ar\n");
       for (i=0;i<NB;i++)
           printf("%d:%d\n",(trainsBa[i]-T)/60,(trainsBa[i]-T)%60);
       getchar();
       /***************/
       tra=0;
       trb=0;
       for (i=0,j=0;i<NA;i++){
          while(j<NB && trainsBd[j]<trainsAa[i]){
             trb++;
             j++;
             }
          if (j==NB)
             break;
          j++;
          }
       trb+=NB-j;
       for (i=0,j=0;i<NB;i++){
          while(j<NA && trainsAd[j]<trainsBa[i]){
             tra++;
             j++;
             }
          if (j==NA)
             break;
          j++;
          }
       tra+=NA-j;
       if (NA==0)
          trb=NB;
       if (NB==0)
          tra=NA;
       fprintf(fout,"Case #%d: %d %d\n",n,tra,trb);
       }
       fclose(fin);
       fclose(fout);
    return 0;
}



void quickSort(int a[],int l,int r){
   int j;

   if(l<r){
      j = partition( a, l, r);
      quickSort( a, l, j-1);
      quickSort( a, j+1, r);
      }
}



int partition(int a[],int l,int r){
   int pivot,i,j,t;
   
   pivot=a[l];
   i=l;
   j=r+1;	
   while(1){
   	  do
         ++i; 
      while(a[i]<=pivot && i<=r);
   	  do
         --j;
      while(a[j]>pivot);
   	  if( i >= j ) break;
   	  t=a[i];
      a[i]=a[j];
      a[j]=t;
   }
   t=a[l];
   a[l]=a[j];
   a[j]=t;
   return j;
}
