#include<stdio.h>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

#define SIZE 1009
#define inf 500000

struct node{
	int start,end;
	int index;
};

node a[SIZE], b[SIZE],total[SIZE];
multiset<int> sa, sb;

bool cmp(const node &a,const node &b){
	return a.start < b.start;
}

int main(){
	int n,x,i,j,na,nb,t,sh,sm,eh,em,temp,temp1,resa,resb,val;
	
	freopen("blarge.in","r",stdin);
	freopen("blarge.out","w",stdout);
	
	scanf("%d",&n);
	for(x=1; x<=n; ++x){
		scanf("%d%d%d",&t,&na,&nb);
		
		sa.clear();
		sb.clear();
		
		for(i=0; i<na; ++i){
			scanf("%d:%d %d:%d",&sh,&sm, &eh,&em);
			temp = sh*60 + sm;
			temp1 = eh*60 + em;
			a[i].start = temp;
			a[i].end = temp1;
			a[i].index = 0;
			sb.insert( temp1+ t );
			total[i] = a[i];
		}
		
		for(i=0; i<nb; ++i){
			scanf("%d:%d %d:%d",&sh,&sm,&eh,&em);
			temp = sh*60 + sm;
			temp1 = eh*60 + em;
			b[i].start = temp;
			b[i].end = temp1;
			b[i].index = 1;
			sa.insert( temp1 + t );
			total[na+i] = b[i];
		}
		
		sort(a, a+na, cmp);
		sort(b, b+nb, cmp);
		sort(total, total+na+nb, cmp);
		
		resa = resb = 0;
		for(i=0; i<na+nb; ++i){
			if(total[i].index == 0){
				if(sa.size())
					val = *(sa.begin());
				else val = inf;
				if(val <= total[i].start){
					sa.erase(sa.begin());
				}
				else resa++;
			}
			else{
				if(sb.size()){
					val = *( sb.begin() );					
				}
				else val = inf;
				
				if(val <= total[i].start){
					sb.erase( sb.begin() );
				}
				else resb++;
			}
		}
		
		printf("Case #%d: %d %d\n",x,resa,resb);
	}
	
	//scanf(" ");
	return 0;
}
