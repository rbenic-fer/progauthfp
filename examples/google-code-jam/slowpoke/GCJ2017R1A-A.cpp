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
    int R, C;
    cin >> R >> C;
    vector<string> v(R);
    for(int i=0; i<R; ++i){
        cin >> v[i];
    }
    
    string *last = nullptr;
    int emptyrow = -1;
    for(int i=0; i<R; ++i){
        vector<int> pos;
        for(int j=0; j<C; ++j){
            if(v[i][j] != '?'){
                pos.push_back(j);
            }
        }
        if(pos.empty()){
            if(last){
                v[i] = *last;
            }else{
                emptyrow = i;
            }
        }else{
            int j = 0;
            for(auto p : pos){
                while(j<p){
                    v[i][j] = v[i][p];
                    ++j;
                }
                ++j;
            }
            while(j<C){
                v[i][j] = v[i][pos.back()];
                ++j;
            }
            last = &v[i];
        }
        
        for(int k=0; k<=emptyrow; ++k){
            v[k] = v[emptyrow+1];
        }
    }
    
    cout << "Case #" << tc << ":" << endl;
    for(int i=0; i<R; ++i){
        cout << v[i] << endl;
    }
    
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}
