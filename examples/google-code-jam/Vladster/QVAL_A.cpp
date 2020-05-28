#include <iostream>
using namespace std;

#define INP_FILE "A-large.in"
#define OUT_FILE "output.txt"

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	int n,k;
	unsigned long int x,d, dn[40];
	dn[0]=1;
	for(int i=1;i<=31;i++)
		dn[i]=2*dn[i-1];
	cin>>tstCnt;
	for(int tst=1;tst<=tstCnt;tst++)
	{		
		scanf("%d %d",&n,&k);
		x=k+1;
		d=dn[n];
		if( (x<d) || (x%d!=0) )
			printf("Case #%d: OFF\n",tst);
		else
			printf("Case #%d: ON\n",tst);
	}
	return 0;
}