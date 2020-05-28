#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int kasus,banyak,isi[1001],letak[1001],sem;
bool sudah[1001];

int main()
{
	scanf("%d",&kasus);
	for (int l=1;l<=kasus;l++)
	{
		memset(sudah,0,sizeof(sudah));
		scanf("%d",&banyak);

		for (int i=1;i<=banyak;i++)
		{
			scanf("%d",&sem);
			letak[sem] = i;
		}
		
		double jawab = 0.000;
		int last = 0;
		for (int i=1;i<=banyak;i++)
		{
			if (letak[i] > last)
			{
				if (letak[i] > last+1) jawab += (double)(letak[i]-i+1);
				last = letak[i];
			}
			else
			{
				jawab += (double)(last-i+2)/2.0;
				jawab -= 1.0/(double)(last-i+1);
			}
		}
		
		printf("Case #%d: %.6lf\n",l,jawab);
	}
	return 0;
}
