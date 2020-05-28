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
typedef long long int lli;


const int N = 10010;
lli P[N], L[N], R[N];

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int q = 1; q <= T; q++){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> P[i] >> L[i];
            R[i] = -1;
        }

        lli D;
        cin >> D;

        R[0] = P[0];
        for (int i = 0; i < n; i++){
            //cout << i << " " << P[i] << ' ' << R[i] << endl;
            for (int j = i+1; j < n; j++){
                if(P[j] <= P[i] + R[i])
                    R[j] = max(R[j], min(L[j], P[j]-P[i]));
            }
        }
        bool can = false;
        for (int i = 0; i < n; i++){
            if(R[i] >= 0 and P[i] + R[i] >= D)
                can = true;
        }
        cout << "Case #"<<q<<": ";
        cout << (can ? "YES" : "NO");
        cout << '\n';
    }
    return 0;
}

