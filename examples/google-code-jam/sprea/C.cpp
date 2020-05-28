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
using namespace std;

int arr[1009];

int main() {
	int T, cs, N, tot, sum, mn, i;
	freopen("/home/user/Desktop/codejam/C-large.in", "r", stdin);
	freopen("/home/user/Desktop/codejam/clarge.out", "w", stdout);
	scanf("%d", &T);
	for( cs = 1; cs <=T; ++cs){
		scanf("%d", &N);
		
		tot = 0;
		mn = 1000000000;
		sum = 0;
		for( i = 0; i<N; ++i){
			scanf("%d", &arr[i]);
			tot ^= arr[i];
			mn = std::min(mn, arr[i]);
			sum += arr[i];
		}
		
		printf("Case #%d: ", cs);
		if( tot != 0 ){
			puts("NO");
		}
		else {
			printf("%d\n", sum-mn);
		}
	}
	return 0;
}

