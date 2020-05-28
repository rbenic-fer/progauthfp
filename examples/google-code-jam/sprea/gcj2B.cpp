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

#define SIZE 509

typedef long long LL;


LL sum[SIZE][SIZE], rsum[SIZE][SIZE], csum[SIZE][SIZE], arr[SIZE][SIZE];
char str[SIZE][SIZE];

int main() {
	int T, cs, ret, R, C, D, i, j, k, mx;
	LL cursum, rcursum, ccursum;
	
	freopen("/home/user/Desktop/B-large.in", "r", stdin);
	freopen("/home/user/Desktop/B-large.out", "w", stdout);
			
//	freopen("/home/user/Desktop/B-small-attempt0.in", "r", stdin);
//	freopen("/home/user/Desktop/B-small.out", "w", stdout);
	
	scanf("%d", &T);
	for( cs  = 1; cs<=T; ++cs){
		scanf("%d%d%d", &R, &C, &D);
		
		for( i = 1; i<=R; ++i){
			scanf("%s", str[i]+1);
			for( j = 1; j<=C; ++j)
				arr[i][j] = str[i][j] - '0' + D;			
		}
		
		memset( sum, 0, sizeof(sum));
		memset( rsum, 0, sizeof(rsum));
		memset( csum, 0, sizeof(csum));
		
		
		for( i = 1; i <= R; ++i){
			for( j = 1; j<=C; ++j){
				sum[i][j] = sum[i-1][j] + sum[i][j-1] + arr[i][j] - sum[i-1][j-1];
				rsum[i][j] = rsum[i-1][j] + rsum[i][j-1] + arr[i][j] * i - rsum[i-1][j-1];
				csum[i][j] = csum[i-1][j] + csum[i][j-1] + arr[i][j] * j - csum[i-1][j-1];
			}
		}
		
		mx = std::min(R, C);
		ret = -1;
		for( k = mx; k>=3; --k){
			for( i = 1; i+k-1<=R; ++i){
				for( j = 1; j+k-1<=C; ++j){
					cursum = sum[i+k-1][j+k-1] - sum[i-1][j+k-1] - sum[i+k-1][j-1] + sum[i-1][j-1];
					rcursum = rsum[i+k-1][j+k-1] - rsum[i-1][j+k-1] - rsum[i+k-1][j-1] + rsum[i-1][j-1];
					ccursum = csum[i+k-1][j+k-1] - csum[i-1][j+k-1] - csum[i+k-1][j-1] + csum[i-1][j-1];
					
					cursum -= arr[i][j] + arr[i+k-1][j+k-1] + arr[i+k-1][j] + arr[i][j+k-1];
					rcursum -= arr[i][j]*i + arr[i+k-1][j+k-1]*(i+k-1) + arr[i+k-1][j]*(i+k-1) + arr[i][j+k-1]*i;
					ccursum -= arr[i][j]*j + arr[i+k-1][j+k-1]*(j+k-1) + arr[i+k-1][j]*j + arr[i][j+k-1]*(j+k-1);
//					if( k == 5){
//						cout <<i<<" "<<j<<" "<< cursum << " "<< rcursum << " "<< ccursum<<endl;
//					}
					if(rcursum * 2 == (2*i + k-1)*cursum  && 
					   ccursum * 2 == (2*j + k-1)*cursum){
						ret = k;
						goto hell;
					}
					
				}
			}
		}
		
		hell:
		printf("Case #%d: ", cs);
		if( ret == -1){
			puts("IMPOSSIBLE");
		}
		else{
			printf("%d\n", ret);
		}
	}
	return 0;
}
