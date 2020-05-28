#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000;
/*
int nums[MAXN + 1];
int messed[MAXN + 1];
int comb[MAXN+1][MAXN+1];
double values[MAXN+1];
int fact[MAXN+1];

void calc_fact() {
    fact[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        fact[i] = fact[i-1] * i;
    }
}

void calc_messed() {
    messed[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            nums[j] = j;
        }

        int cnt = 0;
        do {
            bool found = false;
            for (int j = 1; j <= i; j++) {
                if (nums[j] == j) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cnt++;
            }
        } while (next_permutation(nums + 1, nums + i + 1));
        messed[i] = cnt;
    }
}

void calc_comb() {
    comb[0][0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
    }
}

void calc_values() {
    values[0] = 0.0;
    values[1] = 0.0;
    values[2] = 2.0;

    for (int i = 3; i <= MAXN; i++) {
        double coef = 1.0;
        values[i] = 0.0;
        for (int iter = 1; iter <= 1000000; iter++) {
            for (int j = 0; j < i; j++) {
                double prob = (comb[i][i-j] * (double)messed[j]) / (double)fact[i];
                values[i] += prob * (iter + values[j]) * coef;
            }
            coef *= ((double)messed[i] / (double)fact[i]);
        }
    }
}
*/
int t;
int n;
int arr[MAXN+1];
int vis[MAXN+1];

int main() {
    //freopen("D-small-attempt2.in", "r", stdin);
    freopen("d2.out", "w", stdout);

    //calc_fact();
    //calc_messed();
    //calc_comb();
    //calc_values();

    //for (int i = 0; i <= MAXN; i++) {
    //    printf("%d -> %.7lf\n", i, values[i]);
    //}

    scanf("%d", &t);

    for (int gi = 0; gi < t; gi++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        double ans = 0.0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int j = arr[i];
                int cnt = 1;
                while (j != i) {
                    vis[j] = 1;
                    cnt++;
                    j = arr[j];
                }
                if (cnt > 1) {
                    ans += cnt;
                }
            }
        }
        printf("Case #%d: %.6lf\n", gi+1, ans);
    }
}
