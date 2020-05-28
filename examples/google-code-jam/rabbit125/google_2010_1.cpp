#include<stdio.h>
#include<stdlib.h>
int test_light(int,int);
int main()
{
   int T,i;
   scanf("%d",&T);
   int N[T],K[T];
   FILE *file=fopen("output.txt","w");
   for(i=0;i<T;i++)
      scanf("%d %d",&N[i],&K[i]);
   for(i=0;i<T;i++)
   {
      fprintf(file,"Case #%d:",i+1);
      if(test_light(N[i],K[i])==1)
         fprintf(file," ON\n");
      else
         fprintf(file," OFF\n");
   }    
   fclose(file);
   return 0;
}
int test_light(int a,int b)
{
   int j,c=0,ans;
   for(j=1;j<=a;j++)
   {
      c=(b>>(j-1));
      if(c%2==1)
         ans=1;
      else
      {
         ans=0;
         break; 
      }
   }
   if(ans==1)
      return 1;
   else
      return 0;
}
