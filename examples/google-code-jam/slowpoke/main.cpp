#include <iostream>
#include <string>

using namespace std;

int see(long long n, bool flag[]){
    int res = 0;
    
    do{
        int digit = (int)(n % 10);
        n /= 10;
        
        if(!flag[digit]){
            flag[digit] = true;
            ++res;
        }
    } while(n);
    
    return res;
}

long long comp(int n){
    if(n == 0)
        return -1;
    
    int res = 0;
    bool flag[10] = {};
    long long cur = n;
    while(true){
        res += see(cur, flag);
        if(res >= 10) {
            return cur;
        }
        cur += n;
    }
}

int main(){
    int T, n;
    cin >> T;
    for(int i=1; i<=T; ++i){
        cin >> n;
        long long res = comp(n);
        cout << "Case #" << i << ": " << (res == -1? "INSOMNIA" : to_string(res)) << endl;
    }
}