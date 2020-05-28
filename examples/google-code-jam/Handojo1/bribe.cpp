#include<iostream>
#include<cstring>

using namespace std;

int dp[102][102];
bool sudah[102][102];
int isi[102];
int i,l,kasus,batas,banyak,jawab;

int pencarian(int kiri,int kanan)
{
	if (sudah[kiri][kanan]) return dp[kiri][kanan];

	sudah[kiri][kanan] = true;
	for (int i=kiri+1;i<kanan;i++)
	{
		dp[kiri][kanan] = min(dp[kiri][kanan],pencarian(kiri,i) + pencarian(i,kanan));
		//if ((!kiri)&&(kanan == banyak+1)) printf("%d %d\n",i,dp[kiri][kanan]);
	}
	dp[kiri][kanan] += (isi[kanan]-isi[kiri]-2);

	return dp[kiri][kanan];
}

int main()
{
	scanf("%d",&kasus);
	for (l=1;l<=kasus;l++)
	{
		scanf("%d %d",&batas,&banyak);
		isi[0] = 0;
		for (i=1;i<=banyak;i++) scanf("%d",&isi[i]);
		isi[banyak+1] = batas+1;

		memset(dp,127,sizeof(dp));
		memset(sudah,0,sizeof(sudah));
		for (i=0;i<=banyak;i++)
		{
			sudah[i][i+1] = true;
			dp[i][i+1] = 0;
		}

		jawab = pencarian(0,banyak+1);
		printf("Case #%d: %d\n",l,jawab);
	}
	return 0;
}