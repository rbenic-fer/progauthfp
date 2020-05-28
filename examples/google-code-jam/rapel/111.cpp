#include<bits/stdc++.h>
using namespace std;

char in[10000];
int arr[30];
int temp[10];
char cmp[10][10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int main()
{
	int test;
	scanf("%d",&test); getchar();
	for(int a=1;a<=test;a++)
	{
		int k=0;
		scanf("%s",in); getchar();
		memset(arr,0,sizeof(arr));
		memset(temp,0,sizeof(temp));
		int len=strlen(in);
		for(int b=0;b<len;b++)
		{
			arr[in[b]-'A']++;
		}
		printf("Case #%d: ",a);
		if(arr['X'-'A']>0)
		{
			int mi=arr['X'-'A'];
			temp[6]=mi;
			for(int b=0;b<3;b++)
			{
				arr[cmp[6][b]-'A']-=mi;
			}
		}
		if(arr['S'-'A']>0)
		{
			int mi=arr['S'-'A'];
			temp[7]=mi;
			for(int b=0;b<5;b++)
			{
				arr[cmp[7][b]-'A']-=mi;
			}
		}
		if(arr['Z'-'A']>0)
		{
			int mi=arr['Z'-'A'];
			temp[0]=mi;
			for(int b=0;b<4;b++)
			{
				arr[cmp[0][b]-'A']-=mi;
			}
		}
		if(arr['W'-'A']>0)
		{
			int mi=arr['W'-'A'];
			temp[2]=mi;
			for(int b=0;b<3;b++)
			{
				arr[cmp[2][b]-'A']-=mi;
			}
		}
		if(arr['V'-'A']>0)
		{
			int mi=arr['V'-'A'];
			temp[5]=mi;
			for(int b=0;b<4;b++)
			{
				arr[cmp[5][b]-'A']-=mi;
			}
		}
		if(arr['F'-'A']>0)
		{
			int mi=arr['F'-'A'];
			temp[4]=mi;
			for(int b=0;b<4;b++)
			{
				arr[cmp[4][b]-'A']-=mi;
			}
		}
		if(arr['G'-'A']>0)
		{
			int mi=arr['G'-'A'];
			temp[8]=mi;
			for(int b=0;b<5;b++)
			{
				arr[cmp[8][b]-'A']-=mi;
			}
		}
		if(arr['I'-'A']>0)
		{
			int mi=arr['I'-'A'];
			temp[9]=mi;
			for(int b=0;b<4;b++)
			{
				arr[cmp[9][b]-'A']-=mi;
			}
		}
		if(arr['R'-'A']>0)
		{
			int mi=arr['R'-'A'];
			temp[3]=mi;
			for(int b=0;b<5;b++)
			{
				arr[cmp[3][b]-'A']-=mi;
			}
		}
		if(arr['N'-'A']>0)
		{
			int mi=arr['N'-'A'];
			temp[1]=mi;
			for(int b=0;b<3;b++)
			{
				arr[cmp[1][b]-'A']-=mi;
			}
		}
		for(int b=0;b<10;b++)
		{
			for(int c=0;c<temp[b];c++)
			printf("%d",b);
		}
		printf("\n");
	}
}
