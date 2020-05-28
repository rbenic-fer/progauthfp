#include<stdio.h>
#include<set>
#include<string.h>

int l,d,n;
char s[10000][20];
bool T[20][255];

void get(bool T[255])
{
	char c[100];
	memset(T,0,255);
	scanf("%1s",&c);
	if(*c=='(')
	{
		while(1)
		{
			scanf("%1s",&c);
			if(*c==')') break;
			T[*c] = true;
		}
	}
	else T[*c] = true;
}

int main()
{
	scanf("%d%d%d",&l,&d,&n);
	for(int i=0;i<d;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++)
	{
		int ans = 0;
		for(int j=0;j<l;j++)
			get(T[j]);
		for(int j=0;j<d;j++)
		{
			bool ok = true;
			for(int k=0;k<l && ok;k++)
				if(T[k][s[j][k]]);
				else ok = false;
			if(ok) ans++;
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}

