#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <map>

using namespace std;

const int N = 10001;
int D[N];
int L[N];
int left[N];
int n, d;

int main() {
    int cas;
    scanf("%d", &cas);
    for (int ic = 1;ic <= cas;ic++) {
        scanf("%d", &n);
        for (int i = 0;i < n;i++) scanf("%d%d", &D[i], &L[i]);
        scanf("%d", &d);
        memset(left, 0, sizeof(left));
        left[0] = D[0];
        int current = 0;
        while (current < n) {
            for (int i = current+1;i < n;i++) {
                if (left[current] >= D[i]-D[current]) {
                    if (left[i] < min(D[i]-D[current], L[i])) {
                        left[i] = min(D[i]-D[current], L[i]);
                    }
                }
            }
            current++;
        }
        bool reach = 0;
        for (int i = 0;i < n;i++) {
            if (left[i] >= d-D[i]) {
                reach = 1;
                break;
            }
        }
        printf("Case #%d: %s\n", ic, reach?"YES":"NO");
    }
    return 0;
}
