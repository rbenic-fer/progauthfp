#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include <iostream>

using namespace std;

struct node{
	int st, end, w;
	node(){}
	node(int _st, int _end, int _w){ st = _st; end = _end; w = _w;}
};

vector<node> v;

bool cmp(const node &a, const node &b){
	return a.w < b.w;
}

int main() {
	int T, cs, X, S, R, t, N;
	int b, e, w, last, i;
	node cur;
	double tt, sz, ret, dst;
	
	freopen("/home/user/Desktop/A-large.in", "r", stdin);
	freopen("/home/user/Desktop/A-large.out", "w", stdout);
		
//	freopen("/home/user/Desktop/A-small-attempt0.in", "r", stdin);
//	freopen("/home/user/Desktop/A-small.out", "w", stdout);
	scanf("%d", &T);
	
	for( cs = 1; cs <= T; ++cs){
		scanf("%d%d%d%d%d", &X, &S, &R, &t, &N);
		
		v.clear();
		last = 0;
		for( i = 0; i<N; ++i){
			scanf("%d%d%d", &b, &e, &w);
			
			if( b > last){
				v.push_back(node(last, b, 0));
			}
			v.push_back(node(b, e, w));
			last = e;
		}
		if(last < X){
			v.push_back(node(last, X, 0));
		}
		
		sort(v.begin(), v.end(), cmp);
		
		ret = 0;
		tt = t;
		for( i = 0; i<v.size(); ++i){
			cur = v[i];
			sz = cur.end - cur.st;
			
			if( tt > 0){
				dst = tt * (cur.w+R);
				if( dst < sz){
					ret += tt;
					sz -= dst;
					tt = 0;
				}
				else{
					ret += sz/(cur.w + R);
					tt -= sz/(cur.w + R);
					sz = 0;					
				}
			}
			
			ret += sz/(cur.w+S);		
			
		}
		
		printf("Case #%d: %.12lf\n", cs, ret);
		
	}
	
	return 0;
}
