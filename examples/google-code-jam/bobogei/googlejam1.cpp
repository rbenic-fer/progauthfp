#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
//
using namespace std;
//
int T,N;
vector<pair<int,int> > oo,bb;
//
int abs(int a)
{
	return a<0?-a:a;
}
//
int main()
{
	freopen("test/asb.in","r",stdin);
	freopen("test/asb.txt","w",stdout);
	scanf("%d",&T);
	for(int ii=0;ii<T;ii++)
	{
		oo.clear();
		bb.clear();
		scanf("%d",&N);
		int t;
		char c[2];
		for(int i=0;i<N;i++)
		{
			scanf("%s %d",c,&t);
			if(c[0]=='O')
			{
				oo.push_back(make_pair(t,i));
			}else
			{
				bb.push_back(make_pair(t,i));
			}
		}
		int no,nb,ido,idb;
		ido=oo.size();
		idb=bb.size();
		int wo,wb,to,tb,tt;
		wo=wb=1;
		tb=to=0;
		no=nb=0;
		tt=0;
		while(no<ido&&nb<idb)
		{
			if(oo[no].second<bb[nb].second)
			{
				to+=abs(oo[no].first-wo)+1;
				if(to<=tb)
				{
					to=tb+1;
				}
				wo=oo[no].first;
				no++;
			}else
			{
				tb+=abs(bb[nb].first-wb)+1;
				if(tb<=to)
				{
					tb=to+1;
				}
				wb=bb[nb].first;
				nb++;
			}
		}
		while(no<ido)
		{
			to+=abs(oo[no].first-wo)+1;
			if(to<=tb)
			{
				to=tb+1;
			}
			wo=oo[no].first;
			no++;
		}
		while(nb<idb)
		{
			tb+=abs(bb[nb].first-wb)+1;
			if(tb<=to)
			{
				tb=to+1;
			}
			wb=bb[nb].first;
			nb++;
		}
		printf("Case #%d: %d\n",ii+1,max(to,tb));
	}
}
