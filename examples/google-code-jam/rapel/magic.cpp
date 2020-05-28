#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int trick[4][4],trick2[4][4];
    int kanan,bawah,baris,baris2;
    int t,test;
    int k,a,b,c[4];
    scanf("%i",&test);
    t=0;
    while(t<test)
    {
                 t++;
                 scanf("%i",&baris);
                 kanan=0;
                 while(kanan!=4)
                 {
                                kanan++;
                                bawah=0;
                                while(bawah!=4)
                                {
                                               bawah++;
                                               scanf("%i",&trick[kanan][bawah]);
                                }
                 }
                 scanf("%i",&baris2);
                 kanan=0;
                 while(kanan!=4)
                 {
                                kanan++;
                                bawah=0;
                                while(bawah!=4)
                                {
                                               bawah++;
                                               scanf("%i",&trick2[kanan][bawah]);
                                }
                 }
                 a=0;
                 k=0;
                 while (a!=4)
                 {
                       a++;
                       b=0;
                       while (b!=4)
                       {
                             b++;
                             if(trick[baris][a]==trick2[baris2][b])
                             {
                                                                   k++;
                                                                   c[k]=trick[baris][a];
                             }
                       }
                 }
                 if(k==1) printf("Case #%i: %i\n",t,c[1]);
                 else if(k==0) printf("Case #%i: Volunteer cheated!\n",t);
                 else printf("Case #%i: Bad magician!\n",t);
    }
    return 0;
}
