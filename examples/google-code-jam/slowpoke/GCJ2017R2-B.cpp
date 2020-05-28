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
    int N, C, M;
    cin >> N >> C >> M;
    unordered_map<int, int> m1, m2;
    
    for(int i=0; i<M; ++i){
        int p, b;
        cin >> p >> b;
        if(b == 1){
            ++m1[p];
        } else {
            ++m2[p];
        }
    }
    
    set<pair<int, int>, greater<pair<int,int>>> cs;
    unordered_map<int, int> mcs;
    
    for(auto &p : m1){
        auto it = m2.find(p.first);
        if(it != m2.end()){
            int val = min(it->second, p.second);
            cs.emplace(val, p.first);
            mcs[p.first] = val;
        }
    }
    
    int ans = 0, promo = 0;
    
    for(int i=1; i<=1000; ++i){
        auto it = mcs.find(i);
        if(it != mcs.end()){
            int amt = it->second;
            int oriAmt = amt;
            while(amt){
                auto largest = cs.begin();
                if(largest->second == i){
                    auto next = cs.begin();
                    ++next;
                    if(next == cs.end()){
                        break;
                    }
                    largest = next;
                }
                --amt;
                ans += 2;
                auto largestp = *largest;
                cs.erase(largest);
                mcs.erase(largestp.second);
                --largestp.first;
                if(largestp.first){
                    cs.insert(largestp);
                    mcs.emplace(largestp.second, largestp.first);
                }
                --m1[largestp.second];
                --m2[largestp.second];
            }
            m1[i] -= oriAmt - amt;
            m2[i] -= oriAmt - amt;
            mcs[i] = amt;
        }
    }
    
    int sum1 = 0, sum2 = 0;
    for(auto &p : m1){
        sum1 += p.second;
    }
    for(auto &p : m2){
        sum2 += p.second;
    }
    
    if(!mcs.empty()){
        auto pc = *mcs.begin();
        int min2 = min(m2[pc.first], sum1-m1[pc.first]);
        int min1 = min(m1[pc.first], sum2-m2[pc.first]);
        
        int rem1 = m1[pc.first] - min1;
        int rem2 = m2[pc.first] - min2;
        
        int clash = min(rem1, rem2);
        if(pc.first == 1){
            ans += 2*clash;
        }else{
            ans += clash;
            promo += clash;
        }
        
        sum1 -= clash;
        sum2 -= clash;
    }
    ans += max(sum1, sum2);
    
    cout << "Case #" << tc << ": " << ans << " " << promo << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}
