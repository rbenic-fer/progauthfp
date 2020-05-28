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
char str[109][109];
char indeg[5][5], dir[5][5];

int main() {
	int T, cs, R, C, i, tot, j, k, ret, jj, kk;
	bool ok;
	
	freopen("/home/user/Desktop/C-small-attempt0.in", "r", stdin);
	freopen("/home/user/Desktop/c-small.out", "w", stdout);
	
	scanf("%d", &T);
	for( cs = 1; cs <=T; ++cs){
		scanf("%d%d", &R, &C);
		
		for( i = 0; i<R; ++i){
			scanf("%s", str[i]);
		}
		
		tot = R*C;
		ret = 0;
		for( i = 0;i<(1<<tot); ++i){
			for( j = 0; j<tot; ++j){				
				dir[j/C][j%C] = ((i>>j)&1);				
			}
			
//			for( j = 0; j<R; ++j){
//				for(k = 0; k<C; ++k){
//					indeg[j][k] = outdeg[j][k] = 0;
//				}
//			}
			
			memset(indeg, 0, sizeof(indeg));
			for( j = 0; j<R; ++j){
				for( k = 0; k<C; ++k){
					
					jj = j; kk = k;
					if( str[j][k] == '|'){						
						if( dir[j][k] ){
							++jj;
						}
						else --jj;
						
						jj = (jj+R)%R;
					}
					else if( str[j][k] == '-'){
						if( dir[j][k]){
							++kk;
						}
						else --kk;
						
						kk = (kk+C)%C;
					}
					else if( str[j][k] == '\\'){
						if(dir[j][k]){
							jj++;
							kk++;
						}
						else {
							jj--;
							kk--;
						}
						jj=(jj+R)%R;
						kk=(kk+C)%C;
					}
					else if( str[j][k] == '/'){
						if(dir[j][k]){
							jj++;
							kk--;
						}
						else {
							jj--;
							kk++;
						}
						
						jj = (jj+R)%R;
						kk = (kk+C)%C;
					}
					else {
						assert(0);
					}
					
					indeg[jj][kk]++;
				}
			}
			
			
			ok = true;
			for( j = 0; j<R; ++j){
				for( k = 0; k<C; ++k){
					if(indeg[j][k] != 1){
						ok = false;
						goto hell;
					}
				}
			}
			hell:
			ret += ok;
			
		}
		
		printf("Case #%d: %d\n", cs, ret);
	}
	return 0;
}
