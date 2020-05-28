//Fruit of Light
//FoL CC
//pineapple strawberry
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
    int t1;
    scanf("%d",&t1);
    for(int i1=0; i1<t1; i1++)
    {
            long long n;
            int d,g;
            cin >> n;
            cin >> d;
            cin >> g;
            int pom=1;
            while(100%pom!=0 || d%(100/pom)!=0) pom++;
            if(n>=pom && (g!=100 || d==100) && (g!=0 || d==0)) printf("Case #%d: Possible\n",i1+1);
            else printf("Case #%d: Broken\n",i1+1);
            }
    return 0;
}
