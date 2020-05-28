/*
 * File:   gcjqr_A.cpp
 * Author: xhSong
 * Created on 2010年5月8日, 上午9:07
 * Time Complexity :
 * Space Complexity :
 * Describe :
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T, n, k;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++) {
        scanf("%d%d", &n, &k);
        if((((1 << n) - 1) & k) == (1 << n) - 1) {
            printf("Case #%d: ON\n", i);
        }
        else {
            printf("Case #%d: OFF\n", i);
        }
    }
    return 0;
}

