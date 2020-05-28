#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct pt{
	double x,y;
	double dist(const pt a){
		return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
	}
};

const double eps=1e-9;
const double PI=3.14159265358979323;

pt P[2];
pt M[100];
int m,n;

int main(){
	int cas,ic;
	scanf("%d",&cas);
	int i;
	for(ic=1;ic<=cas;ic++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%lf%lf",&P[i].x,&P[i].y);
		}
		for(i=0;i<m;i++){
			scanf("%lf%lf",&M[i].x,&M[i].y);
		}
		double r0,r1,d;
		d=P[0].dist(P[1]);
		printf("Case #%d:",ic);
		for(i=0;i<m;i++){
			r0=P[0].dist(M[i]);
			r1=P[1].dist(M[i]);
			double ans;
			if(fabs(r0-r1)-d>-eps){
				ans=PI*min(r0,r1)*min(r0,r1);
			}
			else if(r0+r1-d<eps){ 
				ans=0;
			}
			else{
				double a0=acos((r0*r0+d*d-r1*r1)/(2*r0*d));
				double a1=acos((r1*r1+d*d-r0*r0)/(2*r1*d));
				ans=a0*r0*r0+a1*r1*r1-r0*d*sin(a0);				
			}
			printf(" %.13lf",ans);
		}
		printf("\n");
	}
	return 0;
}
