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
		int n;cin>>n;
		int fi=1; for(int i=0;i<n;i++) fi*=2;
		long int a,b[1030][11];
		for(int i=0;i<fi;i++)
		{
			for(int j=0;j<11;j++)
				b[i][j]=0;
			cin>>a;
			for(int j=0;j<n-a;j++)b[i][j]=2000000;
		}
		while(fi>0)
		{
			fi/=2;
			for(int i=0;i<fi;i++)
			{
				int x;cin>>x;
				for(int j=0;j<n;j++)
					b[i][j]=min(
								x+b[2*i][j+1]+b[2*i+1][j+1],
								b[2*i][j]+b[2*i+1][j]);
				b[i][n]=b[2*i][n]+b[2*i+1][n];
			}
		}
		printf("Case #%d: %d\n",tst,b[0][0]);
	}
	return 0;
}
