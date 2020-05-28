#include <cstdlib>
#include <bitset>
#include <functional>
#include <utility>
#include <cstddef>
#include <initializer_list>
#include <tuple>

#include <memory>

#include <limits>

#include <cctype>
#include <cstring>
#include <string>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

#include <algorithm>

#include <ios>
#include <iostream>
#include <sstream>
#include <iomanip>


using namespace std;

int calc(int h1, int a1, int h2, int a2, int b, int d, int nb, int nd){
    int orih1 = h1;
    int turns = 0;

    if(nd == 0 && orih1 <= a2)
        return -1;
    
    if(orih1 <= a2 - d)
        return -1;
    
    while(h2>0){
        ++turns;
        
        if(h2 <= a1){
            break;
        }
        
        if(nd){
            if(h1 <= a2 - d){
                h1 = orih1 - a2;
                if(h1 <= a2 - d){
                    return -1;
                }
                continue;
            }
            a2 = max(0, a2-d);
            --nd;
            h1 -= a2;
        }else{
            if(h1 <= a2){
                h1 = orih1 - a2;
                if(h1 <= a2){
                    return -1;
                }
                continue;
            }
            if(nb){
                a1 += b;
                --nb;
            } else {
                h2 -= a1;
            }
            h1 -= a2;
        }
    }
    
    return turns;
}

void comp(int tc){
    int h1, h2, a1, a2, b, d;
    cin >> h1 >> a1 >> h2 >> a2 >> b >> d;
    
    int ans = -1;
    for(int nb=0; nb<=100; ++nb){
        for(int nd=0; nd<=100; ++nd){
            int res = calc(h1, a1, h2, a2, b, d, nb, nd);
            if(res != -1){
                if(ans == -1)
                    ans = res;
                else
                    ans = min(ans, res);
            }
        }
    }
    
    cout << "Case #" << tc << ": " << (ans==-1? "IMPOSSIBLE" : to_string(ans)) << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}
