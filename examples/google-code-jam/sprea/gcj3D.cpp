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

char str[109], out[109];

bool isPerf(LL a){
	LL b = sqrt(a*1.0);
	
	if( b*b == a || (b+1)*(b+1) == a) return true;
	return false;
}
int main() {
	LL val;
	int cs, i, j, k, N, T;
	
//	freopen("/home/user/Desktop/B-large.in", "r", stdin);
	freopen("/home/user/Desktop/D-small-attempt0.in", "r", stdin);
	freopen("/home/user/Desktop/d-small.out", "w", stdout);
	scanf("%d", &T);
	for(cs = 1; cs <=T; ++cs){
		scanf("%s", str);
		
		strcpy(out, str);
		N = 0;
		for( i = 0; str[i]; ++i){
			if( str[i] == '?')
				N++;
		}
		
		for( j = 0; j<(1<<N); ++j){
			i = k = 0;
			
			val = 0;
			for( i = 0; str[i]; ++i){
				val <<= 1;
				if( str[i] == '?'){
					if( (j>>k)&1 ) {
						val++;
						out[i] = '1';
					}
					else out[i] = '0';
					k++;
					
				}
				else{
					if( str[i] == '1') val++;
				}
			}
			
			if(isPerf(val)){
				break;
			}
		}
		
		val = 0;
		for( i = 0; out[i]; ++i){
			val <<= 1;
			if( out[i] == '1') val++;
			if(out[i] == '?') assert(0);
		}
		
		assert(isPerf(val));
		printf("Case #%d: %s\n", cs, out);
	}
	return 0;
}
