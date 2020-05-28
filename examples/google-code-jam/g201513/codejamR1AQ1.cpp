#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

int n,k;
char s[100][100];
bool win[256];

int main()
{
	freopen("A-large.in","r",stdin);
//	freopen("A-large.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d%d",&n,&k);
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++) scanf("%s",&s[i]);
		for(int i=0;i<n;i++)
		{
			int k=n-1;
			for(int j=n-1;j>=0;j--)
				if(s[i][j]!='.')
				{
					char t = s[i][j];
					s[i][j] = '.';
					s[i][k--] = t;
				}
		}
		memset(win,0,sizeof(win));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(s[i][j]=='R' || s[i][j]=='B')
				{
					int p=0;
					while(i+p<n && j-p>=0 && s[i][j]==s[i+p][j-p]) p++;
					if(p >= k) win[s[i][j]] = true;
					p=0;
					while(i+p<n && j+p<n && s[i][j]==s[i+p][j+p]) p++;
					if(p >= k) win[s[i][j]] = true;
					p=0;
					while(i+p<n && s[i][j]==s[i+p][j]) p++;
					if(p >= k) win[s[i][j]] = true;
					p=0;
					while(j+p<n && s[i][j]==s[i][j+p]) p++;
					if(p >= k) win[s[i][j]] = true;
				}

		printf("Case #%d: ",test);
		if(win['R'] && win['B']) printf("Both\n");
		else if(win['R']) printf("Red\n");
		else if(win['B']) printf("Blue\n");
		else printf("Neither\n");
	}
	return 0;
}
