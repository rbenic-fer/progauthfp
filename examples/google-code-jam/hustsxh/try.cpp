#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

template <typename T>
T gcd(T a, T b) {
    return b? gcd(b, a % b): a;
}

using namespace std;

vector<string> server[4];
vector<string> strs;
int worst, counter;

void check(int n) {
    for (int i = 0; i < n; ++i) {
        if (server[i].size() == 0) {
            return ;
        }
    }
    int cnt = 0;
    for (int k = 0; k < n; ++k) {
        set<string> prix;
        for (int i = 0; i < server[k].size(); ++i) {
            for (int j = 0; j < server[k][i].size(); ++j) {
                prix.insert(string(server[k][i], 0, j + 1));
            }
        }
        cnt += prix.size();
    }
    if (cnt > worst) {
        worst = cnt;
        counter = 1;
    } else if (cnt == worst) {
        ++ counter;
    }
}

void DFS(int x, int m, int n) {
    if (x == m) {
        check(n);
        return ;
    }
    for (int i = 0; i < n; ++i) {
        server[i].push_back(strs[x]);
        DFS(x + 1, m, n);
        server[i].pop_back();
    }
}

void solve() {
    int m, n;
    cin >> m >> n;
    strs.clear();
    worst = 0;
    counter = 0;
    for (int i = 0; i < n; ++i) {
        server[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
        string str;
        cin >> str;
        strs.push_back(str);
    }
	//server[0].push_back(strs[0]);
    DFS(0, m, n);
    cout << worst + n << " " << counter << endl;
}

int main() {
    int testcase;
    freopen("d://D-small-attempt3.in", "r", stdin);
    freopen("d://d.txt", "w", stdout);
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
