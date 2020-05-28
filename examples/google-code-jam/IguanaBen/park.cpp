#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{   long int t,r,k,n,curr=0,tk,fg;
    long int *grupy;
    long int wynik;
    scanf("%d",&t);
    for(long int x=0;x<t;x++)
    {scanf("%d",&r);
     scanf("%d",&k);
     scanf("%d",&n);
     wynik=0;
     tk=k;
     grupy=new long int[n];
     curr=0;
     for(long int y=0;y<n;y++)
     {scanf("%d",&grupy[y]);}
     
     for(long int q=0;q<r;q++)
     {tk=k;
     fg=0;
      while(tk>0&&fg<n)
      {
       if(curr>n-1)
       {curr=0;}
       if(grupy[curr]<=tk)
       {tk-=grupy[curr];
        wynik+=grupy[curr];
        curr++;
       }
       else
       {//tk-=grupy[curr];
        tk=0;
       } 
       fg++;
      }
       //cout<<q<<" "<<wynik<<endl;
     }
     cout<<"Case #"<<x+1<<": "<<wynik<<endl;
    }
    return 0;
    //system("PAUSE");
    //return EXIT_SUCCESS;
}
