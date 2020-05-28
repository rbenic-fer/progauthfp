#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct mountain
{
    int h;
    int up;
    int low;
    mountain()
    {
        h=-1;
        low=0;
        up=1000000000;
    }
};
int main()
{
    //freopen("input","r",stdin);
    int tt;
    cin >> tt;
    for(int ii=1;ii<=tt;ii++)
    {
        int n;
        cin >> n;
        int r[n];
        vector<int> w[n];
        for(int k=0;k<n-1;k++)
        {
            cin >> r[k];
            r[k]--;
            w[r[k]].push_back(k);
        }
        mountain m[n];
        m[n-1].h = 1000000000;
        int ans = 1;
        for(int k=n-1;k>=0 && ans;k--)
        {
            //cout << "50" << endl;
            for(int j=0;j<w[k].size();j++)
            {
                for(int i = w[k][j]; i<k;i++)
                {
                    if(r[i] > k)
                    {
                        ans = 0;
                        break;
                    }
                }
                //cout << k << "draw " << w[k][j] << endl;
                if(m[w[k][j] ].h >= 0)
                {
                    ans = 0;
                    break;
                }
                m[w[k][j] ].h = m[k].h-1;
            }
        }
        printf("Case #%d: ",ii);
        if(ans) for(int k=0;k<n;k++) cout << m[k].h << ' ';
        else cout << "Impossible";
        cout << endl;
    }
    return 0;
}
