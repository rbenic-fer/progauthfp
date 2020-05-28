#include <iostream>
using namespace std;

#define INP_FILE "C-small-attempt0.in"
#define OUT_FILE "output.txt"


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{	
		int n;
		cin>>n;
		n=n-2;
		int a=1,b=1,c;
		for(int i=0;i<n;i++) 
		{
			c=b;
			b=(a+b)%100003;
			a=c;
		}
		printf("Case #%d: %d\n",tst,b);
	}
	return 0;
}