#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int dp[501][19];
bool sudah[501][19];
int i,panjang,banyak,jawab;
string cari,s;

int pencarian(int liat,int sampai)
{
	if (sampai == 19) return 1;
	if (liat == panjang) return 0;
	if (sudah[liat][sampai]) return dp[liat][sampai];

	sudah[liat][sampai] = true;

	dp[liat][sampai] += pencarian(liat+1,sampai);
	if (s[liat] == cari[sampai]) dp[liat][sampai] += pencarian(liat+1,sampai+1);
	dp[liat][sampai] %= 10000;

	return dp[liat][sampai];
}

int main()
{
	cari = "welcome to code jam";
	scanf("%d\n",&banyak);

	for (i=1;i<=banyak;i++)
	{
		getline(cin,s);
		memset(dp,0,sizeof(dp));
		memset(sudah,0,sizeof(sudah));
		panjang = s.length();

		jawab = pencarian(0,0);
		printf("Case #%d: ",i);
		if (jawab < 10) printf("000");
		else if (jawab < 100) printf("00");
		else if (jawab < 1000) printf("0");
		printf("%d\n",jawab);
	}
	return 0;
}