#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
int T, N, W, L;
double r[MAXN];
double x[MAXN], y[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    srand(time(NULL));
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%d", &N, &W, &L);
        printf("Case #%d:", cas);
        for (int i = 1; i <= N; i++)
        {
            scanf("%lf", &r[i]);
            bool flag = 0;
            while (!flag)
            {
                flag = 1;
                x[i] = (double)rand()/RAND_MAX*W, y[i] = (double)rand()/RAND_MAX*L;
                for (int j = 1; j < i && flag; j++)
                {
                    double a = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    double b = (r[i]+r[j])*(r[i]+r[j]);
                    if (a+eps < b)
                        flag = 0;
                }
            }
            printf(" %.4lf %.4lf", x[i], y[i]);
        }
        printf("\n");
    }
    return 0;
}
