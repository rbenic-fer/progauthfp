 #include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);

  using namespace std;

  double a[1010],b[1010],N;
  int calc(int ai,int l,int r)
  {
    if(ai==N)
      return 0;
    int ans=0;
    if(a[ai]>b[l]&&a[ai]>b[r]){
      ans=1+calc(ai+1,l+1,r);
    }
    if(a[ai]<b[l]&&a[ai]<b[r]){
      ans=max(ans,calc(ai+1,l,r-1));
    }
    if(a[ai]>b[l]&&a[ai]<b[r]){
      ans=max(ans,max(1+calc(ai+1,l+1,r),calc(ai+1,l,r-1)));
    }
    return ans;
  }
  int main() { 
  	// freopen("input.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
  	int t,i,j,k,l,n,m,it,r=0;
    
    int s=0;
  	cin>>t;
    // cout<<t<<endl;
  	for(it=1;it<=t;it++){
      s=0;
      scanf("%d",&n);
      N=n;
      // cout<<n<<endl;
      for(i=0;i<n;i++){
        scanf("%lf",&a[i]);
      }
      for(i=0;i<n;i++){
        scanf("%lf",&b[i]);
      }
      sort(a,a+n);
      sort(b,b+n);
      // for(i=0;i<n;i++)
      //   cout<<a[i]<<' ';
      // cout<<endl;
      // for(i=0;i<n;i++)
      //   cout<<b[i]<<' ';
      // cout<<endl;
      /*
      l=0;
      r=n-1;
      s=calc(0,0,n-1);
      */
      //////////////////////////////////////////////////////////////
      l=0;
      r=n-1;
      for(i=0;i<n;i++){
        if(a[i]<b[l]&&a[i]<b[r]){
          r--;
        }
        else if(a[i]>b[l]&&a[i]>b[r]){
          l++;
          s++;
        }
        else
        {
          l++;
          s++; 
        }
      }



      //////////////////////////////////////////////////////////////

      l=0;
      r=0;
      for(i=0;i<n&&r<n;i++){
        while(r<n&&b[r]<a[i])
          r++;
        if(r==n)
          break;
        l++;
        r++;
      }

    
      printf("Case #%d: %d %d\n",it,s,n-l);    
  	}
    return 0;
  }