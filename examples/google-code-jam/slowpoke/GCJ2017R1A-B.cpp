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
    vector<int> src(N);
    for(int i=0; i<N; ++i){
        cin >> src[i];
    }
    vector<vector<pair<int,int>>> v(N);
    for(int i=0; i<N; ++i){
        int base = src[i];
        for(int j=0; j<P; ++j){
            int val;
            cin >> val;
            int low = (val * 100 + 110 * base - 1)/ (110 * base);
            int high = val * 100 / (90 * base);
            v[i].emplace_back(low, high);
        }
        sort(v[i].begin(), v[i].end());
    }
    
    vector<int> idx(N);
    int ans = 0;
    while(true){
        int lo = v[0][idx[0]].first;
        int hi = v[0][idx[0]].second;
        int mini = 0;
        for(int i=1; i<N; ++i){
            auto &p = v[i][idx[i]];
            lo = max(lo, p.first);
            if(p.second < hi){
                hi = p.second;
                mini = i;
            }
            
            if(lo>hi){
                break;
            }
        }
        
        if(lo>hi){
            idx[mini]++;
            if(idx[mini]>=P){
                break;
            }
        }else{
            ++ans;
            bool ok = true;
            for(auto &val : idx){
                ++val;
                if(val >= P){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                break;
            }
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
