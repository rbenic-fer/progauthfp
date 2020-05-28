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
#include <list>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;

#define SIZE 2009

int U[SIZE], V[SIZE];
char flag[SIZE];
int ans;
list<int> poly[SIZE];
int cnt;
int M, N;


void recurse(list<int> L){
	list<int> L1, L2;
	list<int>::iterator lit, it;
	
	int i;
	for( i = 0; i<M; ++i){
		if(flag[i]) continue;
		
		int curcnt = 0;
		int last = 0;
		for( lit = L.begin(); lit != L.end(); ++lit){
			if( last == 0 && ( *lit == U[i] || *lit == V[i])){
				curcnt++;
				last = true;
				continue;
			}
			last = false;
		}
		
		if(curcnt == 2)
		for( lit = L.begin(); lit != L.end(); ++lit){
			if( *lit == U[i] || *lit == V[i]){
				if(*lit == V[i]){
					swap(U[i], V[i]);
					
				}
				
				for(it = L.begin(); it != lit; ++it){
					L1.push_back(*it);
				}
				L1.push_back(*it); L2.push_back(*it);
				for(  ;*it != V[i]; ++it ){
					L2.push_back(*it);
				}
				L2.push_back(*it);
				for( ; it != L.end(); ++it){
					L1.push_back(*it);
				}
				
				flag[i] = true;
				recurse(L1);
				recurse(L2);
				return;
			}
		}
	}
	
	ans = std::min(ans, (int)L.size());
	poly[cnt++] = L;
}

bool found;
int res[10];

bool verify(){
	int i, curcnt, j;
	list<int>::iterator it;
	char mark[9];
	
	
	for( i = 0; i<cnt; ++i){
		memset(mark, 0, sizeof(mark));
		for( it = poly[i].begin(); it != poly[i].end(); ++it){
			mark[ res[*it] ] = 1;
		}
		
		curcnt = 0;
		for( j = 0; j<4; ++j){
			curcnt += mark[j];
		}
		
		if( curcnt < ans) return false;
	}
	
	return true;
}

void bktk(int at){
	int i;
	
	if( at > N){
		if(verify()){
			found = true;
			for( i = 1; i<=N; ++i){
				if( i > 1) putchar(' ');
				printf("%d", res[i]+1);
			}
			puts("");
		}
		
		return;
	}
	
	for( i = 0; i<ans; ++i){		
		res[at] = i;
		bktk(at+1);
		if(found) return;
		res[at] = -1;
	}
}
int main(){
	int T, cs;
	int  i;
	
	
	freopen("/home/user/Desktop/C-small-attempt1.in", "r", stdin);
	freopen("/home/user/Desktop/c-small.out", "w", stdout);
//	freopen("/home/user/Desktop/c-large.out", "w", stdout);
	
	scanf("%d", &T);
	for(cs = 1; cs <=T; ++cs){
		scanf("%d%d", &N, &M);
		
		for( i = 0; i<M; ++i){
			scanf("%d", &U[i]);
		}
		for( i = 0; i<M; ++i){
			scanf("%d", &V[i]);
		}
		
		list<int> L;
		for( i = 1; i<=N; ++i) L.push_back(i);
		
		memset(flag, 0, sizeof(flag));
		ans = N;
		cnt = 0;
//		puts("Ok1");
		recurse(L);
		
		printf("Case #%d: %d\n", cs, ans);
//		cnt = 0;
		found = 0;
		bktk(1);
//		puts("ok");
		
	}
	
	return 0;
}
