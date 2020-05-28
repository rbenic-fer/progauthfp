#include<iostream>
#include<cstring>

using namespace std;

int dp[1<<17];
bool tabrak[17][17];
int titik[17][26];
int i,j,k,l,kasus,banyak,banding,awal,akhir,waktu,jawab;

int ambil(int kode,int bitmask,int akhir);
int pencarian(int bitmask);

int ambil(int kode,int bitmask,int akhir)
{
	int sem = banding;
	//if (bitmask == 3) printf("kode = %d\n",kode);
	if (kode) sem = pencarian(bitmask-kode) + 1;

	for (int i=akhir+1;i<=banyak;i++)
	{
		if (!(bitmask & (1<<(i-1)))) continue;
		bool bisa = true;
		for (int j=1;j<=akhir;j++)
		{
			if (!(kode & (1<<(j-1)))) continue;
			if (tabrak[i][j])
			{
				//if (bitmask == 3) printf("%d %d Bener kok\n",i,j);
				bisa = false;
				break;
			}
		}

		if (bisa) sem = min(sem,ambil(kode+(1<<(i-1)),bitmask,i));
	}
	return sem;
}

int pencarian(int bitmask)
{
	if (dp[bitmask] < banding) return dp[bitmask];

	dp[bitmask] = ambil(0,bitmask,0);
	//printf("%d : %d\n",bitmask,dp[bitmask]);
	return dp[bitmask];
}

int main()
{
	scanf("%d",&kasus);
	memset(&banding,127,sizeof(banding));
	for (l=1;l<=kasus;l++)
	{
		memset(tabrak,0,sizeof(tabrak));

		scanf("%d %d",&banyak,&waktu);
		for (i=1;i<=banyak;i++)
		{
			for (j=1;j<=waktu;j++) scanf("%d",&titik[i][j]);
		}

		for (i=1;i<=banyak;i++)
		{
			for (j=i+1;j<=banyak;j++)
			{
				if (titik[i][1] == titik[j][1])
				{
					tabrak[i][j] = tabrak[j][i] = true;
					//if (tabrak[i][j]) printf("%d %d ga bisa\n",i,j);
					continue;
				}

				for (k=2;k<=waktu;k++)
				{
					if (titik[i][k] == titik[j][k])
					{
						tabrak[i][j] = tabrak[j][i] = true;
						break;
					}

					if (titik[i][k] > titik[j][k]) awal = i;
					else awal = j;

					if (titik[i][k-1] > titik[j][k-1]) akhir = i;
					else akhir = j;

					tabrak[i][j] = tabrak[j][i] = (akhir != awal);
				}

				//if (tabrak[i][j]) printf("%d %d ga bisa\n",i,j);
			}
		}

		memset(dp,127,sizeof(dp));
		dp[0] = 0;
		for (i=0;i<banyak;i++) dp[1<<i] = 1;
		jawab = pencarian((1<<banyak)-1);
		printf("Case #%d: %d\n",l,jawab);
	}
	return 0;
}