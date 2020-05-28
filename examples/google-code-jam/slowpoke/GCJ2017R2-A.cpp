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

void comp(int tc){
    int N, P;
    cin >> N >> P;
    unordered_map<int, int> m;
    for(int i=0; i<N; ++i){
        int v;
        cin >> v;
        ++m[v%P];
    }
    int ans = 0;
    if(P == 2){
        ans = m[0] + (m[1]+1)/2;
    } else if (P == 3){
        int m12 = min(m[1], m[2]);
        ans = m[0] + m12 + (m[1] - m12 + 2)/3 + (m[2] - m12 + 2)/3;
    } else if (P == 4){
        int m22 = m[2]/2;
        int m13 = min(m[1], m[3]);
        ans = m[0] + m22 + m13;
        m[2] -= m22 * 2;
        m[1] -= m13;
        m[3] -= m13;
        
        if(m[2]){
            --m[2];
            if(m[1]){
                m[1] -= min(2, m[1]);
            } else if(m[3]) {
                m[3] -= min(2, m[3]);
            }
            ++ans;
        }
        
        if(m[1]){
            ans += (m[1] + 3)/4;
        } else if(m[3]){
            ans += (m[3] + 3)/4;
        }
    }
    
    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}
