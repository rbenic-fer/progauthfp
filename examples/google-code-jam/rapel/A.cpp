#include<bits/stdc++.h>
using namespace std;

char in[30][30];
bool mark[30][30];

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int r,c;
		scanf("%d %d",&r,&c);
		memset(mark,false,sizeof(mark));
		for(int a=0;a<r;a++) 
		{
			scanf("%s",in[a]);
			for(int b=0;b<c;b++) if(in[a][b]!='?') mark[a][b] = true;
		}
		
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++)
			{
				if(mark[a][b]==true)
				{
					int rl=-1,rr =-1,ll=-1,lr=-1;
					for(int d=1;d<=r*c;d++)
					{
						for(int e=1;e<=d;e++)
						{
							if(d%e!=0) continue;
							int f = d/e;
							for(int g=a-e+1;g<=a;g++)
							{
								if(g < 0 || g + e >r ) continue;
								for(int h=b-f+1;h<=b;h++)
								{
									if(h <0 || h + f > c) continue;
									int tot = 0;
									for(int i=g;i<=g+e-1;i++)
									{
										for(int j=h;j<=h+f-1;j++)
										{
											if(in[i][j]!='?') tot++;	
										}
									}
									if(tot==1)
									{
										rl = g;
										rr = g + e-1;
										ll = h;
										lr = h + f - 1;
									}
								}
							}
						}
					}
					for(int d=rl;d<=rr;d++)
					{
						for(int e=ll;e<=lr;e++) in[d][e] = in[a][b];
					}
				}
			}
		}
		printf("Case #%d:\n",tc);
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++) printf("%c",in[a][b]);
			printf("\n");
		}
	}
}
