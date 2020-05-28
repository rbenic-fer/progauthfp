#include<stdio.h>
#include<cmath>



#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

struct circle{
	int x, y, r;
	void scan(){ scanf("%d%d%d", &x, &y, &r);}
};

circle arr[10];

double S( double d){ return d*d;}
int main(){
	int N, T, X, i, j, k;
	double ret, dist;

	freopen("D-small-attempt0.in", "r", stdin); freopen("D1.out", "w", stdout);

	scanf("%d", &T);
	for(X=1; X <= T; ++X){
		scanf("%d", &N);

		for(i=0; i<N; ++i){
			arr[i].scan();
		}

		if( N == 1){
			ret = arr[0].r;
		}
		else if( N == 2){
			ret = max( arr[0].r, arr[1].r);
		}
		else {
			ret = 100000009;

			for( i=0; i<3; ++i){
				for( j=i+1; j<3; ++j){
					dist = sqrt(S(arr[i].x-arr[j].x) + S(arr[i].y - arr[j].y)) +
						arr[i].r + arr[j].r;
					dist /= 2;

					for( k =0; k<3; ++k){
						if(k != i && k != j){
							dist = max( dist, arr[k].r);
						}
					}

					ret = min( ret, dist);
				}
			}			
		}

		printf("Case #%d: %.8lf\n", X, ret);
	}

	return 0;
}