#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int field[50][50];
    int baris,kolom,bomb,kosong;
    int a,b,c,d,e,t,test,k;
    scanf("%i",&test);
    t=0;
    while(t<test)
    {
                 t++;
                 scanf("%i %i %i",&baris,&kolom,&bomb);
                 kosong=(baris*kolom)-bomb;
                 k=0;
                 if(baris>=2 && kolom>=2)
                 {
                             if(kosong<4)
                             printf("Case #%i:\nImpossible\n",t);
                             else
                             {
                                 printf("Case #%i:\n",t);
                                 for(a=1;a<=baris;a++)
                                 {
                                                      for(b=1;b<=kolom;b++)
                                                      {
                                                                           field[a][b]=2;
                                                      }
                                 }
                                 field[1][1]=-1;
                                 field[1][2]=-1;
                                 field[2][1]=-1;
                                 field[2][2]=-1;
                                 kosong=kosong-4;
                                 a=1;
                                 b=1;
                                 while(kosong!=0)
                                 {
                                                 if(b==(kolom+1))
                                                 {
                                                             b=1;
                                                             a++;
                                                 }
                                                 if(field[a][b]!=-1)
                                                 {
                                                 field[a][b]=-1;
                                                 kosong--;
                                                 }
                                                 b++;
                                 }
                                 for(a=1;a<=baris;a++)
                                 {
                                                      for(b=1;b<=kolom;b++)
                                                      {
                                                                           if(field[a][b]==2)
                                                                           {
                                                                                             if(field[a][b-1]<field[a][b]) field[a][b-1]=3;
                                                                                             if(field[a][b+1]<field[a][b]) field[a][b+1]=3;
                                                                                             if(field[a-1][b]<field[a][b]) field[a-1][b]=3;
                                                                                             if(field[a+1][b]<field[a][b]) field[a+1][b]=3;
                                                                                             if(field[a-1][b-1]<field[a][b]) field[a-1][b+1]=3;
                                                                                             if(field[a-1][b+1]<field[a][b]) field[a-1][b+1]=3;
                                                                                             if(field[a+1][b-1]<field[a][b]) field[a+1][b-1]=3;
                                                                                             if(field[a+1][b+1]<field[a][b]) field[a+1][b+1]=3;
                                                                           }
                                                      }
                                 }
                                 for(a=1;a<=baris;a++)
                                 {
                                                      for(b=1;b<=kolom;b++)
                                                      {
                                                      if(k==0)
                                                      {
                                                              if(field[a][b]==-1) printf("c");   
                                                        k=1;
                                                      }
                                                      else if (field[a][b]!=2) printf(".");
                                                      else printf("*");               
                                                      }
                                                      printf("\n");
                                 }
                             }
                 }
                 else if(baris==1 || kolom==1)
                 {
                      if(kosong<2)
                      printf("Case #%i:\nImpossible\n",t);
                      else
                      {
                          printf("Case #%i:\n",t);
                          kosong--;
                      for(a=1;a<=baris;a++)
                      {
                                           for(b=1;b<=kolom;b++)
                                           {
                                                        if(k==0)
                                                        {
                                                        printf("c");   
                                                        k=1;
                                                        }
                                                        else if(kosong!=0)
                                                        {
                                                             printf(".");
                                                             kosong--;
                                                        }
                                                        else printf("*");
                                           }
                                           printf("\n");
                      }
                      }
                 }
    }
    return 0;
}
