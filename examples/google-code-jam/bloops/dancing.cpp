#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

// bestscore[sum][surprise] = best score possible with given sum and bool surprise
int DP[35][2];

int main()
{
    ios::sync_with_stdio(false);
    memset(DP,-1,sizeof(DP));

    int sum;
    bool surprising;
    int best;
    for (int p = 0; p <= 10; p++){
        for (int q = max(0,p-2); q <= min(10,p+2); q++){
            for (int r = max(0,max(p-2,q-2)); r <= min(10,min(p+2,q+2)); r++){
                assert(abs(p-q) <= 2 and abs(q-r) <= 2 and abs(p-r) <= 2);
                sum = p+q+r;
                surprising = abs(p-q) == 2 or abs(q-r) == 2 or abs(p-r) == 2;
                best = max(p,max(q,r));
                DP[sum][surprising] = max (DP[sum][surprising],
                                                  best);
            }
        }
    }

    int T;
    cin >> T;

    int n, surprises, p;
    int total;
    int ans = 0;
    for (int q = 1; q <= T; q++){
        cin >> n >> surprises >> p;
        ans = 0;
        for (int i = 0; i < n; i++){
            cin >> total;
            if(DP[total][0] >= p){
                ans++;
                continue;
            }
            if(DP[total][1] >= p and surprises > 0){
                ans++;
                surprises--;
            }
        }

        cout << "Case #"<<q<<": "<<ans<<'\n';
    }

    return 0;
}

