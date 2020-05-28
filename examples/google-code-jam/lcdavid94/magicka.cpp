#include<iostream>
#include<cstdio>
#include<string>
#include<cstring> 
using namespace std;
char cvt[30][30];
bool opp[30][30];
int main()
{
    int tt;
    cin>>tt;
    for (int t=1;t<=tt;++t)
        {
             memset(cvt,' ',sizeof(cvt));
             memset(opp,0,sizeof(opp));
             int x;
             scanf("%d%*c",&x);
             for (int i=1;i<=x;++i)
                 {
                      char a,b,c;
                      scanf("%c%c%c ",&a,&b,&c);
                      cvt[a-'A'][b-'A']=cvt[b-'A'][a-'A']=c;
                  }
             scanf("%d%*c",&x);
             for (int i=1;i<=x;++i)
                 {
                      char a,b;
                      scanf("%c%c ",&a,&b);
                      opp[a-'A'][b-'A']=opp[b-'A'][a-'A']=1;
                  }
             scanf("%d%*c",&x);
             string s="";
             for (int i=1;i<=x;++i)
                 {
                      char c;
                      scanf("%c",&c);
                      if (s=="") s+=c;
                      else
                        if (cvt[c-'A'][s[s.size()-1]-'A']!=' ') s[s.size()-1]=cvt[c-'A'][s[s.size()-1]-'A'];
                        else
                          {
                            s+=c;
                            for (int j=s.size()-2;j>=0;--j)
                                if (opp[c-'A'][s[j]-'A']) {s="";break;}
                          }
                  }
             printf("Case #%d: [",t);
             if (s!="")
                {
                  cout<<s[0];
                  for (int i=1;i<s.size();++i)
                      printf(", %c",s[i]);
                }
                  cout<<"]\n";
         }
    return 0;
}
