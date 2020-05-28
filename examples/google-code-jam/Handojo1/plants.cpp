#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int x[5],y[5],r[5],i,banyak,l,kasus;
double sem1,sem2,sem3;

int main()
{
	scanf("%d",&kasus);
	for (l=1;l<=kasus;l++)
	{
		scanf("%d",&banyak);
		for (i=1;i<=banyak;i++) scanf("%d %d %d",&x[i],&y[i],&r[i]);
		printf("Case #%d: ",l);

		if (banyak == 1) printf("%.5lf\n",(double)r[1]);
		else if (banyak == 2) printf("%.5lf\n",(double)max(r[1],r[2]));
		else
		{
			sem1 = (sqrt((double)((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]))) +(double)(r[1]+r[2]) )/ 2.0;
			sem1 = max(sem1,(double)r[3]);

			sem2 = (sqrt((double)((x[1]-x[3])*(x[1]-x[3])+(y[1]-y[3])*(y[1]-y[3]))) +(double)(r[1]+r[3]) )/ 2.0;
			sem2 = max(sem2,(double)r[2]);

			sem3 = (sqrt((double)((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]))) +(double)(r[3]+r[2]) )/ 2.0;
			sem3 = max(sem3,(double)r[1]);

			sem1 = min(sem1,sem2);
			sem1 = min(sem1,sem3);
			printf("%.5lf\n",sem1);
		}
	}
	return 0;
}