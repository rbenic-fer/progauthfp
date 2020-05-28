#include <iostream>
using namespace std;

#define INP_FILE "C-large.in"
#define OUT_FILE "output.txt"


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	int r,n,k;
	int a[1010],nxt[1010],money[1010];
	cin>>tstCnt;
	for(int tst=1;tst<=tstCnt;tst++)
	{		
		cin>>r>>k>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			int sum=a[i];
			int cur=(i+1)%n;
			while( sum+a[cur]<=k && cur!=i )
			{
				sum+=a[cur];
				cur=(cur+1)%n;
			}
			money[i]=sum;
			nxt[i]=cur;
		}
		int f1=0,f2=nxt[f1],p=0; 
		long long int m1=0;
		while(f1!=f2) {
			++p;
			m1+=money[f1];
			f1=nxt[f1]; 
			f2=nxt[nxt[f2]]; 
		}
		int f3=nxt[f1],l=1;
		long long int m2=money[f1];
		while(f3!=f1){
			++l;
			m2+=money[f3];
			f3=nxt[f3];
		}
		long long int rez=0;
		int now=0;
		if (r>=p)
		{
			r-=p;
			rez+=m1;
			now=f1;
		}
		if( r>=l && now==f1 )
		{
			rez+=m2*(r/l);
			r=r%l;
		}
		while(r>0)
		{
			--r;
			rez+=money[now];
			now=nxt[now];
		}
		printf("Case #%d: %ld",tst);cout<<rez;printf("\n");
	}
	return 0;
}