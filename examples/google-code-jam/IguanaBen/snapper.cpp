#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;
long int divv(long int n)
{ long int x=1;
  for(long int a=1;a<n;a++)
  {x=(x*2)+1;
  }
  return x;
}
int main(int argc, char *argv[])
{   long int t,n,k,dv,takicos;
    scanf("%d",&t);
    for(long int a=0;a<t;a++)
    {scanf("%d",&n);
     scanf("%d",&k);
     //cout<<n<<" "<<k<<endl;
     //getchar();
     dv=divv(n);
     if(n==1)
     {if(k>0&&k%2==1)
      {cout<<"Case #"<<a+1<<": ON";}
      else
      {cout<<"Case #"<<a+1<<": OFF";}
     }
     else
     {
     
     /*if(k>0)
     {if(k==(int(k/dv)*dv)+int(k/dv)-1)
      {cout<<"Case #"<<a+1<<": ON";}
      else
      {cout<<"Case #"<<a+1<<": OFF";}
     }
     else
     {cout<<"Case #"<<a+1<<": OFF";}
     }*/
     takicos=-1;
     for(int g=0;;g++)
     {if(takicos==k)
      {cout<<"Case #"<<a+1<<": ON";
      break;}
     if(takicos>k)
      {cout<<"Case #"<<a+1<<": OFF";
      break;}
      takicos+=dv+1;
     }
    }
    cout<<endl;
    }
    //system("PAUSE");
    //return EXIT_SUCCESS;
    return 0;
}
