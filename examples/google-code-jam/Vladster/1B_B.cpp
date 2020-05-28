#include <iostream>
using namespace std;

#define INP_FILE "A-large.in"
#define OUT_FILE "output.txt"


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{	
		int n,m;
		char s[300][101];
		int total=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=n;i<n+m;i++)
		{
			cin>>s[i];
			int mn=0;
			for(int j=0 ; s[i][j] ; j++) 
					mn+=(s[i][j]=='/')?1:0;
			for(int k=0;k<i;k++)
			{
				int j=0;
				for(; s[i][j] && s[i][j]==s[k][j] ; j++)
					;
				if (s[i][j]!=0 || (s[i][j]==0 && s[k][j]!=0 &&s[k][j]!='/') ) while(s[i][j]!='/') --j;
				int cnt=0; 
				for(; s[i][j] ; j++) 
					cnt+=(s[i][j]=='/')?1:0;
				mn=min(mn,cnt);
			}
			total+=mn;
		}

		printf("Case #%d: %d\n",tst,total);
	}
	return 0;
}