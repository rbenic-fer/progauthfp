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

#define SIZE 109

char str[109][109];
double WP[SIZE], OWP[SIZE], OOWP[SIZE];

int main(){
	int T, cs;
	int i, j, k, tot, win, curcnt, N;
	double curval;
	
	freopen("/home/user/Desktop/A-large.in", "r", stdin);
//	freopen("/home/user/Desktop/a-small.out", "w", stdout);
	freopen("/home/user/Desktop/a-large.out", "w", stdout);
	
	scanf("%d", &T);
	for(cs = 1; cs <=T; ++cs){
		
		scanf("%d", &N);
		for( i = 0; i<N; ++i){
			scanf("%s", str[i]);
		}
		
		for( i = 0; i<N; ++i){
			WP[i] = 0;
			
			tot = win = 0;
			for( j = 0; j<N; ++j){
				if( str[i][j] != '.') tot++;
				if( str[i][j] == '1') win++;
			}
			WP[i] = win*1.0/tot;
		}
		
		for( i = 0; i<N; ++i){
			OWP[i] = 0;
			
			curcnt = 0;
			curval = 0;			
			for( j = 0; j<N; ++j){
				if( j == i ) continue;
				if( str[i][j] == '.') continue;
				curcnt++;
				tot = win = 0;
				for( k = 0; k<N; ++k){
					if( k == i) continue;
					
					if( str[j][k]!= '.') tot++;
					if( str[j][k] == '1') win++;
					
					 
				}
				
				curval += win*1.0/tot;
			}
			curval /= curcnt;
			OWP[i] = curval;
		}
		
		for( i = 0; i<N; ++i){
			OOWP[i] = 0;
			
			curcnt = 0;
			for( j = 0; j<N; ++j){
				if(str[i][j] == '.') continue;
				
				curcnt++;
				OOWP[i] += OWP[j];
			}
			
			OOWP[i] /= curcnt;
		}
		
		
		printf("Case #%d:\n", cs);
		for( i = 0; i<N; ++i){
			curval = .25*WP[i] + .5*OWP[i] + .25*OOWP[i];
			
			printf("%.12lf\n", curval);
		}
	}
	
	return 0;
}
