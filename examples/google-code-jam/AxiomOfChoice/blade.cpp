#include <cstdio>

using namespace std;

#define MAX 500

int T, r, c, d, k;
char diff[MAX][MAX];

int main()
{
	scanf( "%d", &T );
	for( int case_num = 1; case_num <= T; case_num++ )
	{
		scanf( "%d%d%d", &r, &c, &d );
		for( int i = 0; i < r; i++ )
		{
			scanf( "%s", diff[i] );
			for( int j = 0; j < c; j++ ) diff[i][j] -= '0';
		}
		// for small input
		for( k = r < c ? r : c; k >= 3; k-- )
		{
			bool ok = false;
			int i = 1, j = 1;
			for( int i = 0; i + k <= r; i++ ) for( int j = 0; j + k <= c; j++ )
			{
				int xavg = 0, yavg = 0;
				for( int x = 0; x < k; x++ ) for( int y = 0; y < k; y++ )
				if( ( x > 0 && x < k - 1 ) || ( y > 0 && y < k - 1 ) )
				{
					xavg += ( 2 * x - k + 1 ) * diff[i+x][j+y];
					yavg += ( 2 * y - k + 1 ) * diff[i+x][j+y];
				}
				if( xavg == 0 && yavg == 0 ) ok = true;
			}
			if( ok ) break;
		}
		if( k >= 3 ) printf( "Case #%d: %d\n", case_num, k );
		else printf( "Case #%d: IMPOSSIBLE\n", case_num );
	}
	return 0;
}
