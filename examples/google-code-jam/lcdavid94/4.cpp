#include<cstdio>
#include<set>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int T,ans,cnt,t[100],n,m;
string s[100];
set <string> f[100];
void out()
{
	for (int i=0;i<m;++i)
			f[i].clear();
	for (int i=0;i<n;++i)
		for (int j=0;j<s[i].length();++j)
			f[t[i]].insert(s[i].substr(0,j+1));
	int sum=0;
	for (int i=0;i<m;++i)
		sum+=f[i].size()+(int)(!f[i].empty());
	if (sum>ans) {ans=sum;cnt=1;}
	else if (sum==ans) ++cnt;
}
void dfs(int d)
{
	if (d==n) out();
	else
	for (int i=0;i<m;++i)
	{
		t[d]=i;
		dfs(d+1);
	}
}
int main()
{
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	cin>>T;
	for (int TT=1;TT<=T;++TT)
	{
		cin>>n>>m;
		for (int i=0;i<n;++i)
			cin>>s[i];
		for (int i=0;i<m;++i)
			f[i].clear();
		ans=cnt=0;
		dfs(0);
		cout<<"Case #"<<TT<<": "<<ans<<" "<<cnt<<endl;
	}
}
