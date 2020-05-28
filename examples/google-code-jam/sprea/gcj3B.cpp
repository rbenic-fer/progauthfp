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

int arr[20];
int main() {
	int T, cs, i, curcnt, cnt, ret, N;
	
//	freopen("/home/user/Desktop/B-large.in", "r", stdin);
	freopen("/home/user/Desktop/B-small-attempt0(3).in", "r", stdin);
	freopen("/home/user/Desktop/b-small.out", "w", stdout);
	scanf("%d", &T);
	
	for( cs = 1; cs <=T; ++cs){
		scanf("%d", &N);
		for( i = 0; i<N; ++i){
			scanf("%d", &arr[i]);
		}
		
		sort( arr, arr+N);
		
		ret = 0;
		do{
			cnt = N;
			i = 0;
			while(i<N){
				curcnt = 1;
				++i;
				for( ; i<N; ++i){
					if( arr[i] == arr[i-1]+1){
						++curcnt;
					}
					else break;
				}
				
				cnt = std::min(cnt, curcnt);
			}
			
//			cout << cnt<<endl;
			ret = std::max(ret, cnt);
			
		}while(next_permutation(arr, arr+N));
		
		printf("Case #%d: %d\n", cs, ret);
	}
	return 0;
}
