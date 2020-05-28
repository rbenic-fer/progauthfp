#include<bits/stdc++.h>
#define ff first
#define mp make_pair
#define ss second
using namespace std;

priority_queue<pair<int,pair<int,int> > > pq;

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		while(!pq.empty()) pq.pop();
		pq.push(mp(n+1-0-1,mp(-0,-n-1)));
		int al,ar;
		for(int b=1;b<=k;b++)
		{
			int dist = pq.top().ff;
			int le = -pq.top().ss.ff;
			int ri = -pq.top().ss.ss;
			int ins = (le + ri)/2;
			al = min(ins-le-1,ri-ins-1);
			ar = max(ins-le-1,ri-ins-1);
			pq.pop();
			pq.push(mp(ins-le-1,mp(-le,-ins)));
			pq.push(mp(ri-ins-1,mp(-ins,-ri)));
		}
		printf("Case #%d: %d %d\n",tc,ar,al);
	}
}
