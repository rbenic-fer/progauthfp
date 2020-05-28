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
const double pi = cos(-1);
struct circle
{
    double x;
    double y;
    int r;
};
int inter(circle a,circle b)
{
    double dis = sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
    //cout << dis << ' ' << a.r + b.r << endl;
    if(dis >= a.r+b.r) return 0;
    return 1;
}
circle p[6000];
int cmp(int a,int b)
{
    return p[a].r > p[b].r;
}
int main()
{
    //freopen("input","r",stdin);
    int tt;
    cin >> tt;
    for(int ii=1;ii<=tt;ii++)
    {
        int n,w,l;
        cin >> n >> w >> l;
        for(int k=0;k<n;k++) cin >> p[k].r;
        int t[n];
        for(int k=0;k<n;k++) t[k] = k;
        sort(t,t+n,cmp);
        double x=0,y=0;
        int dx = 1,dy = 1;
        int start=0;
        for(int k=0;k<n;k++)
        {
            int e = t[k];
            p[e].x = x;p[e].y= y;
            for(int j=0;j<k;j++)
            {
                int ee = t[j];
                while(inter(p[e],p[ee]))
                {
                    //cout << "!!";
                    p[e].y += p[ee].r + p[e].r + 0.1;
                }
            }
            y = p[e].y;
            if(x + dx * (p[e].r + (k+1<n? p[t[k+1]].r:0) ) <  w &&
               x + dx * (p[e].r + (k+1<n? p[t[k+1]].r:0) ) >=0) x += dx * (p[e].r + (k+1<n? p[t[k+1]].r:0) ) ;
            else
            {
                dx = -dx;
                y += dx*p[e].r + (k+1 <n? p[t[k+1]].r:0);
            }

        }
        printf("Case #%d: ",ii);
        for(int k=0;k<n;k++)
            printf("%.1f %.1f ",p[k].x,p[k].y);
        cout << endl;
    }
    return 0;
}
