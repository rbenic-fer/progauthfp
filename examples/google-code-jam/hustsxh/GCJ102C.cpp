/* 
 * File: GCJ102C.cpp
 * Author: XuehuiSong
 * Created on 2010年6月5日, 下午10:30
 * Method: 
 * Time Complexity:
 * Space Complexity: 
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#define M 200

using namespace std;

int a[2][200][200];

int check(int n) {
    for(int i = 0; i < 200; i ++) {
        for(int j = 0; j < 200; j ++) {
            if(a[n % 2][i][j] == 1) {
                return 1;
            }
        }
    }
    return 0;
}

void next(int n) {
    for(int i = 1; i < 200; i ++) {
        for(int j = 1; j < 200; j ++) {
            int tp = (n - 1) % 2;
            if(a[tp][i][j] == 1) {
                if(a[tp][i - 1][j] == 0 && a[tp][i][j - 1] == 0) {
                    a[n % 2][i][j] = 0;
                }
                else {
                    a[n % 2][i][j] = 1;
                }
            }
            else {
                if(a[tp][i - 1][j] && a[tp][i][j - 1]) {
                    a[n % 2][i][j] = 1;
                }
                else {
                    a[n % 2][i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int T, n, x1, y1, x2, y2;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &T);
    for(int test = 1; test <= T; test ++) {
        scanf("%d", &n);
        memset(a[0], 0, sizeof(a[0]));
        for(int t = 0; t < n; t ++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            for(int i = x1; i <= x2; i ++) {
                for(int j = y1; j <= y2; j ++) {
                    a[0][i][j] = 1;
                }
            }
        }
        int day = 0;
        while(check(day)) {
            day ++;
            next(day);
        }
        printf("Case #%d: %d\n", test, day);
    }
    return 0;
}

