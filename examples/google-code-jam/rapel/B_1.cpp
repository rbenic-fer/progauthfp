#include<bits/stdc++.h>
using namespace std;

long long n;

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		scanf("%lld",&n);
		while(1)
		{
			stack<int> s;
			long long rem = n;
			while(rem!=0)
			{
				s.push(rem%10);
				rem/=10;
			}
			int id = -1;
			bool ada = true;
			while(!s.empty())
			{
				if(id==-1)
				{
					id = s.top();
					s.pop();
				}
				else
				{
					if(id > s.top()) ada = false;
					id = s.top();
					s.pop();
				}
			}
			if(ada==true) break;
			n--;
		}
		printf("Case #%d: %lld\n",tc,n);
	}
}
