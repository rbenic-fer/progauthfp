#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int panjang,tahu,tanya,i,j,k,total,indeks;
bool bisa[15][26];
bool ada;
string kamus[5001];
string pola;

int main()
{
	scanf("%d %d %d",&panjang,&tahu,&tanya);
	for (i=1;i<=tahu;i++) cin>>kamus[i];

	for (i=1;i<=tanya;i++)
	{
		total = 0;
		indeks = 0;
		cin>>pola;
		memset(bisa,0,sizeof(bisa));
		for (j=0;j<panjang;j++)
		{
			if (pola[indeks] == '(')
			{
				indeks++;
				while (pola[indeks] != ')')
				{
					bisa[j][pola[indeks]-97] = true;
					indeks++;
				}
				indeks++;
			}
			else
			{
				bisa[j][pola[indeks]-97] = true;
				indeks++;
			}
		}

		for (j=1;j<=tahu;j++)
		{
			ada = true;
			for (k=0;k<panjang;k++) ada = ada && bisa[k][kamus[j][k]-97];
			if (ada) total++;
		}
		printf("Case #%d: %d\n",i,total);
	}
	return 0;
}