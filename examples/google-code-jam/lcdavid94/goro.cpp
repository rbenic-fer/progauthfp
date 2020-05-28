#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[2000];
int main()
{
    int tt;
    cin>>tt;
    for (int t=1;t<=tt;++t)
        {
             int n;
             cin>>n;
             for (int i=1;i<=n;++i)
                 cin>>a[i];
             int ans=0;
             for (int i=1;i<=n;++i)
                 while (a[i]!=i)
                       {
                        swap(a[i],a[a[i]]);
                        ans+=2;
                       }
             cout<<"Case #"<<t<<": "<<ans<<".000000\n";
         }
    return 0;
}
