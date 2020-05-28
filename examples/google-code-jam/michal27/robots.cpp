//Fruit of Light
//FoL CC
//pineapple strawberry
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000000047
int A[147][147]; //ktore spracuvam, druhy robot

int abs(int a)
{
	if(a<0) return -a;
	else return a;
}

int maxi(int a, int b, int c)
{
	return max(max(a,b),c);
}

int main()
{
int t1;
scanf("%d",&t1);
for(int i1=0; i1<t1; i1++)
{
	int n;
	scanf("%d ",&n);
	vector<pair<char,int> > B;
	for(int i=0; i<=100; i++)
		for(int j=0; j<=100; j++) A[i][j]=MAX;
	A[0][1]=0;
	B.push_back(make_pair('C',1));
	for(int i=0; i<n; i++)
	{
		char c=getchar();
		int x; scanf("%d ",&x);
		B.push_back(make_pair(c,x));
		//B.push_back(make_pair(c,x));
	}
	for(int i=1; i<B.size(); i++)
	{
		char kto1=B[i-1].first;
		int kde1=B[i-1].second;
		char kto2=B[i].first;
		int kde2=B[i].second;
		for(int j=1; j<=100; j++)
			for(int k=1; k<=100; k++)
			{
				if(kto1==kto2) A[i][j]=min(A[i][j],A[i-1][k]+maxi(abs(kde2-kde1)+1,abs(k-j),1));
				else A[i][j]=min(A[i][j],A[i-1][k]+maxi(abs(kde2-k)+1,abs(kde1-j),1));
			}
	
	}
	int mini=A[B.size()-1][1];
	for(int i=1; i<=100; i++) mini=min(mini,A[B.size()-1][i]);
	printf("Case #%d: ",i1+1);
	printf("%d\n",mini);
}
return 0;
}