/* 
 * File:   jcg1A.cpp
 * Author: xhSong
 * Created on 2010年5月22日, 上午10:40
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

using namespace std;

char a[100][100];

void move_right(int n) {
    for(int i = 0; i < n; i ++) {
        int p = n - 1, q = n - 1;
        while(p >= 0) {
            while(p >= 0 && a[i][p] == '.') {
                p --;
            }
            if(p >= 0) {
                a[i][q --] = a[i][p--];
            }
        }
        for(int j = 0; j <= q; j ++) {
            a[i][j] = '.';
        }
    }
}

bool check(int n, int k, char c) {
    for(int i = 0; i < n - k + 1; i ++) {
        for(int j = 0; j < n; j ++) {
            int cnt = 0;
            while(cnt < k && a[i + cnt][j] == c) {
                cnt ++;
            }
            if(cnt == k) {
                return 1;
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n - k + 1; j ++) {
            int cnt = 0;
            while(cnt < k && a[i][j + cnt] == c) {
                cnt ++;
            }
            if(cnt == k) {
                return 1;
            }
        }
    }
    for(int i = 0; i < n - k + 1; i ++) {
        for(int j = 0; j < n - k + 1; j ++) {
            int cnt = 0;
            while(cnt < k && a[i + cnt][j + cnt] == c) {
                cnt ++;
            }
            if(cnt == k) {
                return 1;
            }
        }
    }
    for(int i = 0; i < n - k + 1; i ++) {
        for(int j = k - 1; j < n; j ++) {
            int cnt = 0;
            while(cnt < k && a[i + cnt][j - cnt] == c) {
                cnt ++;
            }
            if(cnt == k) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int T, test = 0, n, k;
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i ++) {
            scanf("%s", a[i]);
        }
        move_right(n);
        bool red, blue;
        red = check(n, k, 'R');
        blue = check(n, k, 'B');
        if(red && blue) {
            printf("Case #%d: Both\n", ++test);
        }
        else if(red && !blue) {
            printf("Case #%d: Red\n", ++test);
        }
        else if(!red && blue) {
            printf("Case #%d: Blue\n", ++test);
        }
        else {
            printf("Case #%d: Neither\n", ++test);
        }
    }
    return 0;
}

