#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

bool sudah[101][300];
int dp[101][300];
int isi[101];
int i,j,l,kasus,banyak,hapus,masuk,batas,best;

int abso(int x)
{
     if (x >= 0) return x;
     return -x;
}

int pencarian(int posisi,int nilai)
{
     if (sudah[posisi][nilai]) return dp[posisi][nilai];
     
     sudah[posisi][nilai] = true;
     dp[posisi][nilai] = (banyak-posisi)*hapus;
     for (int i=posisi+1;i<=banyak;i++)
     {
          for (int j=0;j<=255;j++)
          {
               dp[posisi][nilai] = min(dp[posisi][nilai],(i-posisi-1)*hapus+pencarian(i,j)+abso(isi[i]-j)+((abso(nilai-j)-1) / batas)*masuk);
          }
     }

     return dp[posisi][nilai];
}

int main()
{
     scanf("%d",&kasus);
     for (l=1;l<=kasus;l++)
     {
          memset(sudah,0,sizeof(sudah));
          scanf("%d %d %d %d",&hapus,&masuk,&batas,&banyak);
          for (i=1;i<=banyak;i++) scanf("%d",&isi[i]);

          best = (banyak-1) * hapus;
          if (batas)
          {
               for (i=1;i<=banyak;i++)
               {
                    for (j=0;j<=255;j++)
                    {
                         best = min(best,(i-1)*hapus+pencarian(i,j)+abso(isi[i]-j));
                    }
               }
          }
          else
          {
               for (j=0;j<=255;j++)
               {
                    int total = 0;
                    for (i=1;i<=banyak;i++)
                    {
                         total += min(hapus,abso(isi[i]-j));
                    }
                    best = min(best,total);
               }
          }

          printf("Case #%d: %d\n",l,best);
     }
     return 0;
}
