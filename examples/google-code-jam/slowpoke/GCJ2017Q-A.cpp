#include <string>
#include <iostream>

using namespace std;

void comp(int tc){
    string s;
    int k, n, res = 0;
    cin >> s >> k;
    n = (int)s.length();
    
    for(int i=0; i<n; ++i){
        if(s[i] == '-'){
            if(i + k > n){
                res = -1;
                break;
            }
            for(int j=i; j<i+k; ++j){
                s[j] = s[j] == '+' ? '-' : '+';
            }
            ++res;
        }
    }
    
    cout << "Case #" << tc << ": ";
    if(res < 0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}
