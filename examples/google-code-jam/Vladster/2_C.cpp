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
		int n;cin>>n;
		int a[105][105];
		for(int i=0;i<105;i++)
			for(int j=0;j<105;j++)
				a[i][j]=0;
		for(int k=0;k<n;k++)
		{
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			for(int i=x1;i<=x2;i++)
				for(int j=y1;j<=y2;j++)
					a[i][j]=1;
		}
		int good=1; int r=0;
		while (good)
		{
			++r;
			good=0;
			for(int i=104;i>0;i--)
				for(int j=104;j>0;j--)
				{
					a[i][j]=(a[i][j-1]+a[i-1][j]+a[i][j] >1);
					good= good || a[i][j];
				}
		}

		printf("Case #%d: %d\n",tst,r);
	}
	return 0;
}