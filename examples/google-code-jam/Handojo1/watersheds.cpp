#include<iostream>
#include<cstring>

using namespace std;

int ubahy[4] = {-1,0,0,1};
int ubahx[4] = {0,-1,1,0};
int tinggi[102][102];
int nomor[102][102];
bool sudah[102][102];
char jawab[102][102],ada[27];
int i,j,k,l,kasus,baris,kolom,temu,banyak;

int pencarian(int baris,int kolom)
{
	if (sudah[baris][kolom]) return nomor[baris][kolom];

	sudah[baris][kolom] = true;
	int pilih = 0;
	for (int i=1;i<4;i++)
	{
		if (tinggi[baris+ubahy[i]][kolom+ubahx[i]] < tinggi[baris+ubahy[pilih]][kolom+ubahx[pilih]]) pilih = i;
	}

	if (tinggi[baris+ubahy[pilih]][kolom+ubahx[pilih]] >= tinggi[baris][kolom])
	{
		banyak++;
		nomor[baris][kolom] = banyak;
	}
	else nomor[baris][kolom] = pencarian(baris+ubahy[pilih],kolom+ubahx[pilih]);

	return nomor[baris][kolom];
}

int main()
{
	scanf("%d",&kasus);
	for (l=1;l<=kasus;l++)
	{
		scanf("%d %d",&baris,&kolom);
		for (i=1;i<=baris;i++)
		{
			for (j=1;j<=kolom;j++) scanf("%d",&tinggi[i][j]);
		}

		for (i=0;i<=baris+1;i++) tinggi[i][0] = tinggi[i][kolom+1] = 10001;
		for (i=1;i<=kolom;i++) tinggi[0][i] = tinggi[baris+1][i] = 10001;
		memset(sudah,0,sizeof(sudah));

		banyak = 0;
		for (i=1;i<=baris;i++)
		{
			for (j=1;j<=kolom;j++)
			{
				if (!sudah[i][j]) pencarian(i,j);
			}
		}

		memset(ada,0,sizeof(ada));
		temu = 0;
		for (i=1;i<=baris;i++)
		{
			for (j=1;j<=kolom;j++)
			{
				if (!ada[nomor[i][j]])
				{
					temu++;
					ada[nomor[i][j]] = temu+96;
				}
				jawab[i][j] = ada[nomor[i][j]];
			}
		}

		printf("Case #%d:\n",l);
		for (i=1;i<=baris;i++)
		{
			for (j=1;j<kolom;j++) printf("%c ",jawab[i][j]);
			printf("%c\n",jawab[i][kolom]);
		}
	}
	return 0;
}