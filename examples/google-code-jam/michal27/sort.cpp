//Fruit of Light
//FoL CC
//pineapple strawberry
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

bool T[1047];

int main()
{
	int t;
	scanf("%d",&t);
	for(int i1=0; i1<t; i1++)
	{
		int n;
		scanf("%d",&n);
		vector<int> A; A.resize(n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&A[i]);
		}
	for(int i=0; i<n; i++) T[i]=false;
	int vys=0;
	for(int i=0; i<n; i++)
	{
		if(!T[i])
		{
		int vel=1;
		int pom=A[i]-1;
		T[i]=true;
		while(!T[pom])
		{
			vel++;
			pom=A[pom]-1;
		}
		vys+=(vel-1)*2;
		}
	}
	printf("Case #%d: ",i1+1);
	printf("%d",vys);
	printf(".000000\n");
	}
return 0;
}