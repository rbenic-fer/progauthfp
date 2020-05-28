#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;
    for (ll cs = 1; cs <= T; ++cs) {
        ll X, R, C;
        cin >> X >> R >> C;
        bool rich = false;
        
        if ((R*C)%X != 0) {
            rich = true;
        }

        if (X > R && X > C) {
            rich = true;
        }

        ll reach = (X+1)/2;
        if (reach > R || reach > C) {
            rich = true;
        }

        printf("Case #%lld: %s\n", cs, rich ? "RICHARD" : "GABRIEL");
    }
    return 0;
}
