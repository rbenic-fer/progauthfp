#include <iostream>
#include <cmath>
using namespace std;

#define INP_FILE "C-large.in"
#define OUT_FILE "C-large.in.txt"

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{	
		int n,mn,totalXor,sum,x;
		cin>>n;
		cin>>x;
		mn=totalXor=sum=x;
		for(int i=1;i<n;i++)
		{
			cin>>x; 
			if (x<mn) mn=x;
			totalXor = totalXor ^ x;
			sum     += x;
		}
		if (totalXor>0)
		{
			printf("Case #%d: NO\n",tst);
		}else{
			printf("Case #%d: %d\n",tst,sum-mn);
		}		
	}
	return 0;
}