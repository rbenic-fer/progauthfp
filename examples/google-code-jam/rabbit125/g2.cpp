#include <iostream> 
#include <cstdlib> 
#include<math.h>
using namespace std;
int main()
{
   int t,l,p,c,i,a,b,d;
   scanf("%d",&t);
   d=1;
   FILE *file=fopen("output2.txt","w");
   while(t--)
   {
      scanf("%d%d%d",&l,&p,&c);
      a=l;
      for(i=1;;i++)
      {
         b=(int)pow(c,i);
         if(a*b>=p &&i==1)
         {
            fprintf(file,"Case #%d: 0\n",d++);
            break; 
         }
         a*=b;
         if(a*b>=p)
         {
            fprintf(file,"Case #%d: %d\n",d++,i);
            break;
         }
      
      }
   }
   fclose(file);
   return 0;
} 
