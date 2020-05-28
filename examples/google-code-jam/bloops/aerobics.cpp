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
#include <iomanip>

using namespace std;
typedef pair<double,double> dd;;

const int N = 1010;
double S[N];
dd pos[N];
double eps = 1e-10;

bool check(int n, double W, double L){
    for (int i = 0; i < n; i++){
        if(pos[i].first < 0 or pos[i].first > W or
           pos[i].second < 0 or pos[i].second > L)
            return false;
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            double dist =( pos[i].first - pos[j].first) * (pos[i].first - pos[j].first);
            dist += ( pos[i].second - pos[j].second) * (pos[i].second - pos[j].second);
            double r = (S[i] + S[j]) * (S[i] + S[j]);
            if(dist + eps < r)
                return false;
        }
    }
    return true;
}

int main()
{
    //ios::sync_with_stdio(false);
    setprecision (2);
    int T;
    cin >> T;
    int n;
    double W, L;
    for (int q = 1; q <= T; q++){
        cin >> n >> W >> L;
        for (int i = 0; i < n; i++){
            cin >> S[i];
        }
        sort(S,S+n);
        reverse(S,S+n);

        int idx = 0; // next square to place
        double bottom = -1, left = -1, maxbot = -1;
        bool firstrow = true, leftmost = true;
        while(idx < n){
            dd next;
            if(firstrow) next.second = 0;
            else next.second = bottom + S[idx] + eps;
            if(leftmost) next.first = 0;
            else next.first = left + S[idx] + eps;
            bool valid = next.first + eps < W and next.second + eps < L;
            if(!valid){
                // move to next row
                firstrow = false;
                leftmost = true;
                left = -1;
                bottom = maxbot;
                maxbot = -1;
            }
            else {
                leftmost = false;
                pos[idx] = next;
                maxbot = max(maxbot, next.second + S[idx] + eps);
                left = next.first + S[idx] + eps;
                idx++;
            }
        }

        cout << "Case #"<<q<<": ";
        if(!check(n,W,L))
            cout << "NOoo";
        for (int i = 0; i < n; i++){
            printf("%.2f %.2f ",pos[i].first, pos[i].second);
        }
        cout << '\n';
    }
    return 0;
}

