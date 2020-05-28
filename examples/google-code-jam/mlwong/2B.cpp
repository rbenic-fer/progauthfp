#include <cstdio>
#include <cstring>

using namespace std;

int sx[502][502], sy[502][502], s[502][502];
int a[502][502];

int min(int a, int b) { return ((a<b)?(a):(b));}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		memset(sx, 0, sizeof(sx));
		memset(sy, 0, sizeof(sy));
		memset(s, 0, sizeof(s));
		int r, c, d;
		scanf("%d %d %d", &r, &c, &d);
		
		for (int x=1; x<=r; x++)
			for (int y=1; y<=c; y++) {
				scanf("%1d", &a[x][y]);
				sx[x][y] = sx[x-1][y]-sx[x-1][y-1]+sx[x][y-1]+x*a[x][y];
				sy[x][y] = sy[x-1][y]-sy[x-1][y-1]+sy[x][y-1]+y*a[x][y];
				s[x][y] = s[x-1][y]-s[x-1][y-1]+s[x][y-1]+a[x][y];
			}
		/*
		for (int x=1; x<=r; x++) {
			for (int y=1; y<=c; y++) printf("%d ", sx[x][y]);
			printf("\n");
		}
		*/		
		bool b = 1;
		
		for (int k=min(r,c); k>=3; k--) {	
			for (int x=k; x<=r; x++) {
				for (int y=k; y<=c; y++) {
					int wx = sx[x][y]-sx[x][y-k]-sx[x-k][y]+sx[x-k][y-k];
					wx -= x*a[x][y] + x*a[x][y-k+1] + (x-k+1)*a[x-k+1][y] + (x-k+1)*(a[x-k+1][y-k+1]);
					int wy = sy[x][y]-sy[x][y-k]-sy[x-k][y]+sy[x-k][y-k];
					wy -= y*a[x][y] + (y-k+1)*a[x][y-k+1] + y*a[x-k+1][y] + (y-k+1)*(a[x-k+1][y-k+1]);
					
					int w = s[x][y]-s[x][y-k]-s[x-k][y]+s[x-k][y-k];
					w -= a[x][y]+a[x][y-k+1]+a[x-k+1][y]+a[x-k+1][y-k+1];
					
					//printf("x=%d, y=%d, wx=%d, wy=%d, w=%d\n", x, y, wx, wy, w);
										
					if (2*wx == w*(2*x-k+1) && 2*wy == w*(2*y-k+1)) {
						printf("Case #%d: %d\n", i, k);
						b = 0;
						break;
					}
				}
				if (b == 0) break;
			}
			if (b == 0) break;
		}
		
		if (b) printf("Case #%d: IMPOSSIBLE\n", i);		
	}
	return 0;
}
