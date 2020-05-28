#include<cstdio>
#include<cstring>

using namespace std;

int i,j,k,l,kasus,sisi,minimal,sem;
char peta[55][55],kar[55];
bool red,blue,bisa;

int main()
{
     scanf("%d",&kasus);
     for (l=1;l<=kasus;l++)
     {
          printf("Case #%d: ",l);
          scanf("%d %d",&sisi,&minimal);
          for (i=0;i<sisi;i++)
          {
               scanf("%s",kar);
               for (j=1;j<=sisi;j++) peta[j][sisi-i] = kar[j-1];
          }

          for (i=sisi-1;i>0;i--)
          {
               for (j=1;j<=sisi;j++)
               {
                    if (peta[i][j] == '.') continue;
                    sem = i;
                    while ((sem < sisi)&&(peta[sem+1][j] == '.'))
                    {
                         peta[sem+1][j] = peta[sem][j];
                         peta[sem][j] = '.';
                         sem++;
                    }
               }
          }

          red = blue = false;
          for (i=1;i<=sisi-minimal+1;i++)
          {
               for (j=1;j<=sisi;j++)
               {
                    if (peta[i][j] == '.') continue;
                    bisa = true;
                    for (k=2;k<=minimal;k++)
                    {
                         if (peta[i+k-2][j] != peta[i+k-1][j])
                         {
                              bisa = false;
                              break;
                         }
                    }

                    if (bisa)
                    {
                         if (peta[i][j] == 'R') red = true;
                         else blue = true;
                    }
               }

               for (j=1;j<=sisi-minimal+1;j++)
               {
                    if (peta[i][j] == '.') continue;
                    bisa = true;
                    for (k=2;k<=minimal;k++)
                    {
                         if (peta[i+k-2][j+k-2] != peta[i+k-1][j+k-1])
                         {
                              bisa = false;
                              break;
                         }
                    }

                    if (bisa)
                    {
                         if (peta[i][j] == 'R') red = true;
                         else blue = true;
                    }
               }

               for (j=minimal;j<=sisi;j++)
               {
                    if (peta[i][j] == '.') continue;
                    bisa = true;
                    for (k=2;k<=minimal;k++)
                    {
                         if (peta[i+k-2][j-k+2] != peta[i+k-1][j-k+1])
                         {
                              bisa = false;
                              break;
                         }
                    }

                    if (bisa)
                    {
                         if (peta[i][j] == 'R') red = true;
                         else blue = true;
                    }
               }

               for (j=1;j<=sisi;j++)
               {
                    if (peta[j][i] == '.') continue;
                    bisa = true;
                    for (k=2;k<=minimal;k++)
                    {
                         if (peta[j][i+k-2] != peta[j][i+k-1])
                         {
                              bisa = false;
                              break;
                         }
                    }

                    if (bisa)
                    {
                         if (peta[j][i] == 'R') red = true;
                         else blue = true;
                    }
               }
          }

          if ((red)&&(blue)) printf("Both");
          else if (red) printf("Red");
          else if (blue) printf("Blue");
          else printf("Neither");
          printf("\n");
     }
     return 0;
}
