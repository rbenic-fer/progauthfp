#include<cstdio>
using namespace std;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		if (r<c) {int t=r;r=c;c=t;}
		printf("Case #%d: ",TT);
		if (x>6) printf("RICHARD\n");
		else
		if (r*c%x>0) printf("RICHARD\n");
		else
		if (x>r||x>c+c) printf("RICHARD\n");
		else
		if (x==r&&r>=4&&c==2) printf("RICHARD\n");
		else printf("GABRIEL\n");
	}
}
