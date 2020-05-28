#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

long long sem,a,b,c;
long long total[10];
int i,j,l,kasus,banyak;
double waktu,jarak;

int main()
{
	scanf("%d",&kasus);
	for (l=1;l<=kasus;l++)
	{
		scanf("%d",&banyak);
		memset(total,0,sizeof(total));

		for (i=1;i<=banyak;i++)
		{
			for (j=1;j<=6;j++)
			{
				scanf("%lld",&sem);
				total[j] += sem;
			}
		}

		//for (i=1;i<=6;i++) printf("%d ",total[i]);
		//printf("\n");

		c = (total[1]*total[1]) + (total[2]*total[2]) + (total[3]*total[3]);
		b = 2 * (total[1]*total[4] + total[2]*total[5] + total[3]*total[6]);
		a = (total[4]*total[4]) + (total[5]*total[5]) + (total[6]*total[6]);

		//printf("%lld %lld %lld\n",a,b,c);

		if (a == 0)
		{
			waktu = 0;
			jarak = sqrt((double)c / (double)(banyak*banyak));
			printf("Case #%d: %.6lf %.6lf\n",l,jarak,waktu);
			continue;
		}

		if (((b >= 0)&&(a > 0))||((b <= 0)&&(a < 0)))
		{
			waktu = 0;
			jarak = sqrt((double)c / (double)(banyak*banyak));
			printf("Case #%d: %.6lf %.6lf\n",l,jarak,waktu);
			continue;
		}

		waktu = -(double)b / (2*(double)a);

		if ((waktu*waktu*(double)a+(double)b*waktu+(double)c) < 0) jarak = 0;
		else jarak = sqrt((waktu*waktu*(double)a+b*(double)waktu+(double)c) / (double)(banyak*banyak));

		//printf("%.5lf\n",(waktu*waktu*(double)a+(double)b*waktu+(double)c));
		printf("Case #%d: %.6lf %.6lf\n",l,jarak,waktu);
	}
	return 0;
}