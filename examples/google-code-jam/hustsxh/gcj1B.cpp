/* 
 * File:   gcj1A.cpp
 * Author: xhSong
 * Created on 2010年5月22日, 上午9:08
 * Time Complexity :
 * Space Complexity : 
 * Describe : 
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>
#define inf 100000000
#define M 256
using namespace std;

int f[1001][M], a[1001];

int main(int argc, char** argv) {
    int T, d, in, m, test = 0, n;
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d%d%d", &d, &in, &m, &n);
        for(int i = 1; i<= n; i ++) {
            scanf("%d", a + i);
        }
        for(int i = 0; i < M; i ++) {
            f[1][i] = abs(i - a[1]);
        }
        for(int i = 2; i <= n; i ++) {
            for(int j = 0; j < M; j ++) {
                f[i][j] = inf;
                for(int k = 0; k < M; k ++) {
                    if(j == k) {
                        f[i][j] = min(f[i][j], f[i - 1][j] + d);
                    }
                    int tp = abs(j - k);
                    if(tp <= m) {
                        f[i][j] = min(f[i][j], f[i - 1][k] + abs(j - a[i]));
                    }
                    else if(m){
                        f[i][j] = min(f[i][j], f[i - 1][k] + abs(j - a[i]) + (tp / m + (tp % m != 0) - 1) * in);
                    }
                }
            }
        }
        int ans = inf;
        for(int i = 0; i < M; i ++) {
            ans = min(ans, f[n][i]);
        }
        printf("Case #%d: %d\n", ++test, ans);
    }
    return 0;
}

