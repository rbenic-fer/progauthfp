#include <cstdio>
#include <algorithm>

using namespace std;

int a[1001], b[1001];

int main() {
    freopen("D-large.in", "r", stdin);
    freopen("d.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n, cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            cnt += (a[i] != b[i] ? 1 : 0);
        }
        printf("Case #%d: %d.000000\n", t, cnt);
    }
}
