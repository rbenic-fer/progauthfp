#include<iostream>
using namespace std;
int main()
{
   // freopen("dancing.in","r",stdin);
    //freopen("dancing.out","w",stdout);
    int num,n,s,t;
    cin>>num;
    for (int tt=1;tt<=num;++tt)
        {
             int ans=0;
             cin>>n>>s>>t;
             for (int i=0;i<n;++i)
                 {
                      int x;
                      cin>>x;
                      if (x>=t*3-2) ++ans;
                      else {if (t>1&&x>=t*3-4&&s>0) {--s;++ans;}}
                  }
             cout<<"Case #"<<tt<<": "<<ans<<endl;
         }
}
