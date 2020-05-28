#include <algorithm>
#include <iostream>

using namespace std;

void comp(int tc){
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long lowC = 0, hiC = 1, nlowC = 0, nhiC = 0, lowV = n-1, hiV = n, count = 0;
    unsigned long long ans;
    
    while(true){
        if(count + hiC + lowC >= k){
            if(count + hiC >= k){
                ans = hiV;
            }else{
                ans = lowV;
            }
            break;
        }
        
        count += lowC + hiC;
        
        if(lowV & 1){
            if(lowV >= 3)
                nlowC += lowC * 2;
        } else {
            if(lowV >= 4){
                nlowC += lowC;
            }
            if(lowV >= 2){
                nhiC += lowC;
            }
        }
        
        if(hiV & 1){
            if(hiV >= 3)
                nhiC += hiC * 2;
        } else {
            if(hiV >= 4){
                nlowC += hiC;
            }
            if(hiV >= 2){
                nhiC += hiC;
            }
        }
        
        lowC = nlowC;
        hiC = nhiC;
        nlowC = nhiC = 0;
        
        lowV = (lowV-1)/2;
        hiV = hiV/2;
    }
    
    cout << "Case #" << tc << ": " << (ans/2) << " " << ((ans-1)/2) << endl;
    
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}
