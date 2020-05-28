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

typedef long long LL;
typedef pair<int,int> pi;

#define SIZE 209

int C, D;
pi arr[SIZE];

bool okay(double t){
	double l = -1e20, st, end;
	int i;
	
	for( i = 0; i<C; ++i){
		st = arr[i].first - t;
		st = std::max(st, l);
		end = st + D*1.0*(arr[i].second-1);
		
		if( fabs( arr[i].first - end) - 1e-12 > t) return false;
		l = end + D;
	}
	
	return true;
}
int main(){
	int T, cs;
	double low, high, mid;
	int lp, i;
	
	freopen("/home/user/Desktop/B-large.in", "r", stdin);
//	freopen("/home/user/Desktop/b-small.out", "w", stdout);
	freopen("/home/user/Desktop/b-large.out", "w", stdout);
	
	scanf("%d", &T);
	for(cs = 1; cs <=T; ++cs){
		
		scanf("%d%d", &C, &D);
		for( i = 0; i<C; ++i){
			scanf("%d%d", &arr[i].first, &arr[i].second);
		}
		
		low = 0; high = 1e15;
		
		for( lp = 0; lp < 400; ++lp){
			mid = (low + high)/2;
			
			if(okay(mid)){
				high = mid;
			}
			else low = mid;
		}
		
		printf("Case #%d: %.12lf\n", cs, low);
	}
	
	return 0;
}
