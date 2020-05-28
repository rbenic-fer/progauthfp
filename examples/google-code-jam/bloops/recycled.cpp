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

int pow10[10];

int countDigits(int n){
    int d = 0;
    while(n > 0) d++, n/=10;
    return d;
}

int A,B;

int iA = 0, Arr[10];

// has to be > n and <= B
int countRecycled(int n){ // assume n >= 1
    iA = 0;
    int x = n;
    int digits = countDigits(n);
    for (int q = 0; q < digits; q++){
        x = (x%10)*pow10[digits-1] + (x/10);
        if(x > n and x <= B){
            Arr[iA++] = x;
        }
    }
    return unique(Arr, Arr+iA) - Arr;
}

int main()
{
    ios::sync_with_stdio(false);
    pow10[0] = 1;
    for (int i = 1; i < 10; i++){
        pow10[i] = 10*pow10[i-1];
    }


    int T;
    cin >> T;

    int ans = 0;
    for (int q = 1; q <= T; q++){
        cin >> A >> B;
        ans = 0;
        for (int x = A; x <= B; x++){
            ans += countRecycled(x);
        }

        cout << "Case #"<<q<<": "<<ans<<'\n';
    }

    
    return 0;
}

