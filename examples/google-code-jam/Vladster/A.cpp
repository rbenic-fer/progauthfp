#include <iostream>
#include <cmath>
using namespace std;

#define INP_FILE "A-large.in"
#define OUT_FILE "A-large.txt"

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{	
		int n,fuel[2],place[2],curTarget,p1,p2;
		char ch;
		int r=0;
		place[0]=place[1]=1;
		fuel[0]=fuel[1]=0;		

		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>ch;
			cin>>curTarget;
			if (ch=='O')
			{
				p1=1; p2=0;
			}else{
				p1=0; p2=1;
			}
			int way = abs( curTarget - place[p1] );
			int dt  = ( way > fuel[p1] ) ? (way-fuel[p1]+1) : 1 ;
			r+=dt;
			fuel[p2]+=dt;
			fuel[p1]=0;
			place[p1]=curTarget;
		}
		printf("Case #%d: %d\n",tst,r);
	}
	return 0;
}