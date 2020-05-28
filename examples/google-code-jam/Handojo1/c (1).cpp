#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int isi[1005],kasus,total,banyak,sem;

int main()
{
	scanf("%d",&kasus);
	for (int l=1;l<=kasus;l++)
	{
		scanf("%d",&banyak);
		sem = 0;
		total = 0;
		for (int i=1;i<=banyak;i++)
		{
			scanf("%d",&isi[i]);
			sem ^= isi[i];
			total += isi[i];
		}

		printf("Case #%d: ",l);
		if (sem)
		{
			printf("NO\n");
			continue;
		}
		
		sort(isi+1,isi+banyak+1);
		total -= isi[1];
		printf("%d\n",total);
	}
	return 0;
}
