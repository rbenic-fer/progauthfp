#include<stdio.h>
#include<map>
#include<algorithm>

using namespace std;


map<int,int> mp;

int main(){

	int n,t,add,mx,sum,k,i,j,x,y;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	for(scanf("%d",&t),k=1;k<=t;k++){
	
		
		scanf("%d",&n);
		mp.clear();
		mx = 0;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			mp[-x]++;
			if(x>mx) mx = x;
		}
		j=0;
		add = mx;
		map<int,int> :: iterator it;
		sum=0;
		while(mp.size()){
		
			it = mp.begin();
			x = it->first;
			y = it->second;
			x = -x;
			mp.erase(it);
			sum += y;
			mp[-(x/2)]++;
			mp[-(x - x/2)]++;
			it = mp.begin();
			x = it->first;
			x = -x;
			if(sum + x < add) add = sum+x;
			j++;
			if(j==n) break;
			//printf("%d %d\n",x,y);
			//break;
		}
		
		printf("Case #%d: %d\n",k,add);
	}

	return 0;
}
