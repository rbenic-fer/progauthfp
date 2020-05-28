#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int tt;
    scanf("%d",&tt);
    int tot=tt;
    while (tt--)
          {
                int n,p[1000],po[2],ans=0,t=0;
                bool s[1000];
                po[0]=po[1]=1;
                scanf("%d%*c",&n);
                for (int i=1;i<=n;++i)
                    {
                         char c;
                         scanf("%c %d%*c",&c,&p[i]);
                         s[i]=(c=='O');
                     }
                for (int i=1;i<=n;++i)
                    {
                         if (s[i]==s[i-1]||t==0) {int r=s[i];t+=abs(po[r]-p[i])+1;ans+=abs(po[r]-p[i])+1;po[r]=p[i];}
                         else {int r=s[i];ans+=max(0,abs(po[r]-p[i])-t)+1;t=max(0,abs(po[r]-p[i])-t)+1;po[r]=p[i];}
                     }
                printf("Case #%d: %d\n",tot-tt,ans);
          }
    return 0;
}
