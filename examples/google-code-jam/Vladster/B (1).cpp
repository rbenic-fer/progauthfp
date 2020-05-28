#include <iostream>
#include <cmath>
using namespace std;

#define INP_FILE "B-large.in"
#define OUT_FILE "B-large.in.txt"

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{	
		int comboHash[900],aniHash[900];
		int n;
		for(int i=0; i<900; i++)
			comboHash[i]=aniHash[i]=0;
		
		cin>>n;
		for(int i=0;i<n;i++)
		{
			char x,y,t;
			cin>>x>>y>>t;
			comboHash[26*(x-'A')+(y-'A')]=t;
			comboHash[26*(y-'A')+(x-'A')]=t;
		}

		cin>>n;
		for(int i=0;i<n;i++)
		{
			char x,y;
			cin>>x>>y;
			aniHash[26*(x-'A')+(y-'A')]=1;
			aniHash[26*(y-'A')+(x-'A')]=1;
		}

		cin>>n; 
		int top=1;
		char line[200];
		line[0]='Z'+1;
		for(int i=0;i<n;i++)
		{
			char t;
			cin>>t;
			if ( comboHash[26*(line[top-1]-'A')+(t-'A')] > 0 )
			{
				line[top-1]=comboHash[26*(line[top-1]-'A')+(t-'A')];
			}else{
				char anig=false;
				for(int j=top-1;j>=0;j--)
					if ( aniHash[26*(line[j]-'A')+(t-'A')] == 1)
					{
						top=1;
						anig=true;
						break;
					}
				if (!anig)
				{
					line[top]=t;
					top++;
				}
			}
		}

		printf("Case #%d: [",tst);
		if (top>1) cout<<line[1];
		for(int i=2;i<top;i++)
			printf(", %c",line[i]);
		printf("]\n");
	}
	return 0;
}