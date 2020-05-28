#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

//a b c d e f g h i j k l m n o p q r s t u v w x y z                      q
char A[]={'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};

int main()
{
  int t;
  scanf("%d ",&t);
  for(int i=1; i<=t; i++)
  {
    printf("Case #%d: ",i);
    string s;
    getline(cin,s);
    for(int j=0; j<s.length(); j++)
    {
      if(s[j]==' ') printf(" ");
      else
      {
	for(int k=0; k<26; k++) if(A[k]==s[j]) printf("%c",k+'a');
      }
    }
    printf("\n");
  }
return 0;
}