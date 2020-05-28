#include <iostream>
using namespace std;

#define INP_FILE "B-large.in"
#define OUT_FILE "output.txt"

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{	
		double l,p,c;
		cin>>l>>p>>c;
		int k=1;
		while(l<p) { 
			l*=c; ++k; 
		}
		int r=0;
		while(k>2) { k=k/2+1; ++r; }
		printf("Case #%d: %d\n",tst,r);
	}
	return 0;
}