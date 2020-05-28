#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int tt=1;tt<=t;++tt)
        {
             cout<<"Case #"<<tt<<": ";
             long long n;
             int pd,pg;
             cin>>n>>pd>>pg;
             if ((pg==100&&pd<100)||(pg==0&&pd>0)) cout<<"Broken";
             else
              {
               int k=1;
               if (pd%2==0) k*=2;
               if (pd%4==0) k*=2;
               if (pd%5==0) k*=5;
               if (pd%25==0) k*=5;
               k=100/k;
               if (n<k) cout<<"Broken";
               else cout<<"Possible";
              }
             cout<<endl;
         }
    return 0;
}
