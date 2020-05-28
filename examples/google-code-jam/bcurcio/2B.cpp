#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

typedef pair<int,int> pii;
int A[12345];


void solve(){
  int N = in();
  
  int i,j;
  
  int ans = 0;
  
  for(i=0;i<N;i++) A[i] = in();
  
  for(i=0;i<N;i++){
    int cnt1 = 0;
    int cnt2 = 0;
    for(j=0;j<N;j++)if(A[j]>A[i]){
      if(j<i) cnt1++;
      if(j>i) cnt2++;
    }
    
    ans += min(cnt1,cnt2);
    
  }
  
  cout << ans << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
