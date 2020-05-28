#include<stdio.h>
#include<algorithm>

using namespace std;

int a[105],n;
long long m;
int solve(){
	int i,ans=0,add;
	long long x=m;
	for(i=0;i<n;i++){
		if(a[i]<x) x+=a[i];
		else{
			add=0;
			if((x-1)==0) return n;
			while((x-1)!=0 && x+(x-1)<=a[i]){x+=(x-1);ans++;}
			x+=(x-1)+a[i];
			ans++;
			if(ans>=n) return n;
		}
	}
	
	return ans;
}

int main(){
	int t,k=0,i,ans;
	long long x;
	freopen("A-large.in","r",stdin);
	freopen("output","w",stdout);
	scanf("%d",&t);
	
	while(t--){
		
		ans=0;
		
		scanf("%lld%d",&x,&n);
		m=x;
		//printf("%lld %d\n",x,n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		
		sort(a,a+n);
	//	for(i=0;i<n;i++) printf("%d ",a[i]);
	//	puts("");
		for(i=0;i<n;i++){
			if(a[i]<x) x+=a[i];
			else if(x+(x-1)>a[i]){ans++;x+=(x-1)+a[i];}
			else{ans+=(n-i);break;}
		}
		//printf("%d\n",ans);
		printf("Case #%d: %d\n",++k,min(n,min(ans,solve())));
	}
	return 0;
}
