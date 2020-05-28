#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cctype>
#include <cassert>
#include <cmath>
#include <set>
#include <stack>
#include <utility>
#include <map>
#include <string>
#include <sstream>

using namespace std;

#define SIZE 109
#define eps 1e-10

//typedef pair<int,int> pi;
typedef pair<double, double> pd;

pd Larr[SIZE], Uarr[SIZE];
int L, U, W;
double segarea;

double getArea(vector<pd> poly, int flag = 0){
	double ret = 0;
	int i;
	
	poly.push_back(poly[0]);
	
	for( i = 0; i+1<(int)poly.size(); ++i){
		ret += (poly[i].first * poly[i+1].second) - (poly[i].second*poly[i+1].first);
//		if(flag)<<ret<< " ";
	}
//	if(flag)<<endl;
	
	if ( ret < 0) ret = -ret;
	
	return ret;
}

bool eq(double a, double b){
	return fabs(a-b) < eps;
}

bool ok(double mid, int lidx, int uidx){
	vector<pd> poly, temp;
	int i;
	double cury;
	
	for( i = lidx; i<L; ++i){
		if( Larr[i].first <= mid){
			poly.push_back(Larr[i]);
		}
		else{
			// i to i-1
			if( !eq(Larr[i].first-Larr[i-1].first, 0)){
				cury = (Larr[i].second - Larr[i-1].second)/(Larr[i].first-Larr[i-1].first)*(mid - Larr[i].first) + Larr[i].second;
				poly.push_back(pd(mid, cury));
			}
		}
	}
	
	for( i = uidx; i<U; ++i){
		if(Uarr[i].first <= mid){
			temp.push_back(Uarr[i]);
		}
		else{
			if( !eq(Uarr[i].first-Uarr[i-1].first, 0)){
				cury = (Uarr[i].second - Uarr[i-1].second)/(Uarr[i].first-Uarr[i-1].first)*(mid - Uarr[i].first) + Uarr[i].second;
				temp.push_back(pd(mid, cury));
			}
		}
	}
	
	for( i = (int)temp.size()-1; i>=0; --i){
		poly.push_back(temp[i]);
	}
	
//	<<mid<< " "<<poly.size()<< " "<<segarea<<endl;
	return getArea(poly)>=segarea;
}

double getSeg(int &lidx, int &uidx){
	
	double low = Larr[lidx].first, high = W, mid;
	int lp;
	
	for( lp = 0; lp<100; ++lp){
		mid = (low+high)/2;
		
		if(ok(mid, lidx, uidx)){
			high = mid;
		}
		else low = mid;
	}
	
	double cury;
	for( ; lidx<L; ++lidx){
		if( Larr[lidx+1].first>mid){
			if( !eq(Larr[lidx+1].first-Larr[lidx].first, 0)){
				cury = (Larr[lidx+1].second - Larr[lidx].second)/(Larr[lidx+1].first-Larr[lidx].first)*(mid - Larr[lidx+1].first) + Larr[lidx+1].second;
				Larr[lidx] = pd(mid, cury);
			}
			else ++lidx;
			break;
		}		
	}
	
	for( ; uidx<U; ++uidx){
		if( Uarr[uidx+1].first > mid){
			if( !eq(Uarr[uidx+1].first-Uarr[uidx].first, 0)){
				cury = (Uarr[uidx+1].second - Uarr[uidx].second)/(Uarr[uidx+1].first-Uarr[uidx].first)*(mid - Uarr[uidx+1].first) + Uarr[uidx+1].second;
				Uarr[uidx] = pd(mid, cury);
			}
			else ++uidx;
			break;
		}
	}
	
//	<<mid<< " "<<lidx<<" "<<uidx<<endl;
	assert(lidx<L && uidx<U);
	
	return mid;
}

int main() {
	int T, cs, G, i, li, ui;
	double totarea, curret;	
	
//	freopen("/home/user/Desktop/B-large.in", "r", stdin);
	freopen("/home/user/Desktop/A-large.in", "r", stdin);
	freopen("/home/user/Desktop/a-large.out", "w", stdout);
	scanf("%d", &T);
	
	for( cs = 1; cs<=T; ++cs){
		
		scanf("%d%d%d%d", &W, &L, &U, &G);
		
		vector<pd> poly;
		poly.clear();
		for( i = 0; i<L; ++i){
			scanf("%lf%lf", &Larr[i].first, &Larr[i].second);
			poly.push_back(Larr[i]);
		}
		
		for( i = 0; i<U; ++i){
			scanf("%lf%lf", &Uarr[i].first, &Uarr[i].second);
		}
		
		for( i = U-1; i>=0; --i){
			poly.push_back(Uarr[i]);
		}
		
		
		totarea = getArea(poly,1);
		segarea = totarea/G;
		
		printf("Case #%d:\n", cs);
		li = ui = 0;
//		printf("%d %d %lf %lf %d\n", L, U, segarea, totarea, poly.size());
//		for( i = 0; i<poly.size(); ++i){
//			printf("(%.2lf %.2lf) ", poly[i].first, poly[i].second);
//		}puts("");
		for( i = 1; i<G; ++i){
			curret = getSeg(li, ui);
			
			printf("%.10lf\n", curret);
		}
	}
	
	return 0;
}
