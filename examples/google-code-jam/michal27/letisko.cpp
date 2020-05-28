#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,pair<int,int> > Tri;

int main()
{
    int t1;
    scanf("%d ",&t1);
    for(int i1=0; i1<t1; i1++)
    {
            int x,s,r,n;
            int t2;
            scanf("%d %d %d %d %d",&x,&s,&r,&t2,&n);
            double t=(double)t2;
            vector<Tri> A;
            int cesta=x;
            for(int i=0; i<n; i++)
            {
                    int z,k,w;
                    scanf("%d %d %d",&z,&k,&w);
                    A.push_back(make_pair(w,make_pair(z,k)));
                    cesta-=(k-z);
                    }  
            double casc=0.0;
            double vz=cesta;
            double v=r;      
            double cas=vz/v;
            if((t-cas)>=0.00000000001) {casc+=cas; t-=cas;}
            else
            {casc+=t; vz-=t*v; t=0; v-=r; v+=s; casc+=vz/v;}
            sort(A.begin(),A.end());
            for(int i=0; i<A.size(); i++)
            {
                    double vz=A[i].second.second-A[i].second.first;
                    double v=A[i].first+r;      
                    double cas=vz/v;
                    if(cas<=t) {casc+=cas; t-=cas;}
                    else
                    {casc+=t; vz-=t*v; t=0; v-=r; v+=s; casc+=vz/v;}
                    }
            printf("Case #%d: %0.7f\n",i1+1,casc);
            }
    return 0;
}
