#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 10000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int T, N, d[MAXN], l[MAXN], D;
int f[MAXN];
bool vis[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &d[i], &l[i]);
        scanf("%d", &D);
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        bool flag = 0;
        if (d[1] <= l[1])
        {
            f[1] = d[1];
            vis[1] = 1;
            if (d[1]+f[1] >= D)
                flag = 1;
        }
        else
            f[1] = 0;
        for (int i = 2; i <= N && !flag; i++)
        {
            for (int j = 1; j < i; j++)
                if (vis[j] && f[j] >= d[i]-d[j])
                {
                    int t = min(d[i]-d[j], l[i]);
                    f[i] = max(f[i], t);
                    vis[i] = 1;
                }
            if (vis[i] && d[i]+f[i] >= D)
                flag = 1;
        }
        printf("Case #%d: ", cas);
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
