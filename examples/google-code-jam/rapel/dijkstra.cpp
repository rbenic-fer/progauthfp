#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char inputan[100005];

char res[10005];

bool ii,jj,kk;
int sym;

int inv(int a)
{
	if(a==1) return 0;
	else return 1;
}

char oper(char a,char b)
{
	if(a=='1'&&b=='1') return '1';
	if(a=='1'&&b=='i') return 'i';
	if(a=='1'&&b=='j') return 'j';
	if(a=='1'&&b=='k') return 'k';
	if(a=='i'&&b=='1') return 'i';
	if(a=='i'&&b=='i') 
	{
		sym=inv(sym);
		return '1';
	}
	if(a=='i'&&b=='j') return 'k';
	if(a=='i'&&b=='k') 
	{
		sym=inv(sym);
		return 'j';
	}
	if(a=='j'&&b=='1') return 'j';
	if(a=='j'&&b=='i') 
	{
		sym=inv(sym);
		return 'k';
	}
	if(a=='j'&&b=='j') 
	{
		sym=inv(sym);
		return '1';
	}
	if(a=='j'&&b=='k') return 'i';
	if(a=='k'&&b=='1') return 'k';
	if(a=='k'&&b=='i') return 'j';
	if(a=='k'&&b=='j') 
	{
		sym=inv(sym);
		return 'i';
	}
	if(a=='k'&&b=='k')
	{
		sym=inv(sym);
		return '1';
	}
}

int main()
{
	int test,ss,loo;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		scanf("%d %d",&ss,&loo);
		scanf("%s",inputan);
		ii=false,jj=false;
		sym=1;
		for(int b=0;b<ss;b++)
		{
			if(inputan[b]=='i') res[b]='i';
			if(inputan[b]=='j') res[b]='j';
			if(inputan[b]=='k') res[b]='k';
		}
		for(int b=1;b<loo;b++)
			for(int c=0;c<ss;c++)
				res[ss*b+c]=res[c];
		char val;
		val='1';
		for(int b=0;b<ss*loo;b++)
		{
			val=oper(val,res[b]);
			if((!ii&&(val=='i'))&&sym==1)
			{
			
				ii=true;
				val='1';
			}
			if((ii&&!jj&&(val=='j'))&&sym==1)
			{
				jj=true;
				val='1';
			}
			
		}
		if(val=='k'&&ii&&jj&&sym==1) printf("Case #%d: YES\n",a);
		else printf("Case #%d: NO\n",a);
	}
}
