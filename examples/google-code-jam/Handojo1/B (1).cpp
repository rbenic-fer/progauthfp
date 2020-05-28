#include<iostream>
#include<cstring>

using namespace std;

long long banding,jawab;
long long dp[12][1<<11][12],harga[12][1<<11];
bool sudah[12][1<<11][12];
int i,j,l,kasus,ronde,sem;
int maks[12][1<<11];

long long pencarian(int nomor,int babak,int dapat)
{
     if (!babak)
     {
          if (dapat >= maks[0][nomor]) return 0;
          return banding;
     }
     if (sudah[babak][nomor][dapat]) return dp[babak][nomor][dapat];

     long long sem1,sem2;
     sudah[babak][nomor][dapat] = true;
     sem1 = harga[babak][nomor]+pencarian(nomor*2,babak-1,dapat+1)+pencarian(nomor*2+1,babak-1,dapat+1);
     sem2 = pencarian(nomor*2,babak-1,dapat)+pencarian(nomor*2+1,babak-1,dapat);

     if (sem1 < sem2) dp[babak][nomor][dapat] = sem1;
     else dp[babak][nomor][dapat] = sem2;
     if (dp[babak][nomor][dapat] > banding) dp[babak][nomor][dapat] = banding;
     return dp[babak][nomor][dapat];
}

int main()
{
     memset(&banding,1,sizeof(banding));
     scanf("%d",&kasus);
     for (l=1;l<=kasus;l++)
     {
          scanf("%d",&ronde);
          for (i=0;i<(1<<ronde);i++)
          {
               scanf("%d",&sem);
               maks[0][i] = ronde-sem;
          }

          for (i=1;i<=ronde;i++)
          {
               for (j=0;j<(1<<(ronde-i));j++) scanf("%I64d",&harga[i][j]);
          }

          for (i=1;i<=ronde;i++)
          {
               for (j=0;j<(1<<(ronde-i));j++)
               maks[i][j] = max(maks[i-1][2*j],maks[i-1][2*j+1]); 
          }

          memset(sudah,0,sizeof(sudah));
          memset(dp,1,sizeof(dp));
          jawab = pencarian(0,ronde,0);
          printf("Case #%d: %I64d\n",l,jawab);
     }
     //printf("haha %I64d\n",banding);
     //system("PAUSE");
     return 0;
}
