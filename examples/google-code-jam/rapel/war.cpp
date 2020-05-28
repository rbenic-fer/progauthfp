#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    float n[10],k[10],temp;
    int test,t,block,c,d,y,z;
    scanf("%i",&test);
    t=0;
    while(t!=test)
    {
                  t++;
                  scanf("%i",&block);
                  for(c=1;c<=block;c++)
                  {
                                       scanf("%f",&n[c]);            
                  }
                  for(c=1;c<=block;c++)
                  {
                                       scanf("%f",&k[c]);            
                  }
                  for(c=1;c<=block;c++)
                  {
                                       for(d=(c+1);d<=block;d++)
                                       {
                                                                if(n[c]>n[d]) 
                                                                {
                                                                              temp=n[c];
                                                                              n[c]=n[d];
                                                                              n[d]=temp;
                                                                }
                                                                if(k[c]>k[d])
                                                                {
                                                                             temp=k[c];
                                                                             k[c]=k[d];
                                                                             k[d]=temp;
                                                                }
                                       }
                  }
                  d=0;
                  c=0;
                  while(c<block)
                  {
                                       c++;
                                       d++;
                                       while(n[c]>=k[d])
                                       {
                                                       d++;
                                                       if(d>=block)
                                                       {
                                                                   if(d>block) d--;
                                                       if(n[c]>=k[d]) c--;
                                                       break;
                                                       }
                                       }
                                       if(d>=block) break;
                  }
                  z=block-c;
                  d=0;
                  c=0;
                  while(c<block)
                  {
                                c++;
                                d++;
                                while(n[c]<=k[d])
                                {
                                                 c++;
                                                 if(c>=block)
                                                 {
                                                             if(c>block) c--;
                                                             if(n[c]<=k[d]) d--;
                                                             break;
                                                 }
                                }
                                if(c>=block) break;
                  }
                  y=d;
                  printf("Case #%i: %i %i\n",t,y,z);
    }
    return 0;
}
