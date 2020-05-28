#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////
const int N = 60;
int T,r,c,m,num;
bool trans;
char s[N][N];
void swap(int &a,int &b){int c=a;a=b,b=c;}
void pt(){
	if(trans)	rep(j,c) {	rep(i,r) printf("%c", s[i][j]); printf("\n");	}
	else		rep(i,r) {	rep(j,c) printf("%c", s[i][j]); printf("\n");	}
}
bool work(){
	fill(s[0],s[0]+N*N,'.');
	num = r*c;	trans = false;	if(r>c) swap(r,c),trans = true;
	if(m+1==num) { fill(s[0],s[0]+N*N,'*'); s[0][0]='c'; return true;}
	if(r==1){	s[0][0]='c'; rep(i,num-m-1) s[0][i+1]='.'; rep(i,m) s[0][num-i-1]='*';	return true;}
	if(r==2){	
		if(m&1 || m+2==num) return false; rep(i,m/2) s[0][i]=s[1][i]='*'; s[0][c-1]='c';	return true; 
	}
	if(m==(r-2)*c || m==(c-2)*r){
		if(m==(r-2)*c){	rep(i,r-2) rep(j,c) s[i+2][j]='*'; s[0][0]='c';return true;	}
		else {	rep(i,c-2) rep(j,r) s[j][i]='*'; s[0][c-1]='c'; return true;	}
	}
	int num1=(r-3)*c,num2 = num-9;
	if(m<=num1){
		rep(i,m/c) rep(j,c) s[i][j]='*';
		int left = m%c;
		if(left<=c-2) rep(j,left) s[m/c][j]='*';
		else{ rep(j,c-2) s[m/c][j]='*'; s[m/c+1][0]='*';}
		s[r-1][c-1]='c'; return true;
	}else if(m<=num2){
		rep(i,r-3) rep(j,c) s[i+3][j]='*';
		int left = m - (r-3)*c;
		if(left%3<=1){
			rep(j,left/3) rep(i,3) s[i][j]='*';
			rep(i,left%3) s[2-i][left/3]='*';
			s[0][c-1]='c'; return true;
		}else{
			rep(j,left/3) rep(i,3) s[i][j]='*';
			s[2][left/3]=s[2][left/3+1]='*';
			s[0][c-1]='c'; return true;
		}
	}else{
		int left = num - m; left = 9-left;
	//	if(c==3 && m==2){	s[0][0]=s[2][2]='*', s[0][2]='c'; return true;}
		rep(i,r-3) rep(j,c) s[i+3][j]='*';
		rep(i,3) rep(j,c-3) s[i][j+3]='*';
		switch(left){
			case 2:case 4:case 6:case 7: return false; break;
			case 1: s[2][2]='*'; break;
			case 3: rep(i,3) s[2][i]='*';break;
			case 5: rep(i,3) s[2][i]=s[i][2]='*';break;
			case 8: rep(i,3) rep(j,3) s[i][j]='*'; break;
		}
		s[0][0]='c'; return true;
	}
	return false;
}
/*
int mp[N][N];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
int bk[8];
bool in(int x,int y){ return (x>=0 && x<r && y>=0 && y<c);}
bool dfs(int x,int y,int s){
	if(s==m) return true;
	if(y==c) return dfs(x+1)
	rep(i,8){
		int tx=x+dx[i],ty=y+dy[i];
		if(in(tx,ty)) {bk[i]=mp[tx][ty]; if(!mp[tx][ty]) mp[tx][ty]=1;}
		mp[x][y]=10;
		if(ok())
	}

}
bool work2(){
	//fill(s[0],s[0]+N*N,'.');
	memset(mp,0,sizeof(mp));
	if(dfs(0,0,0)) return true;
	else return false;
}*/
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("c.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>T;
	fer(t,1,T+1){
		cin>>r>>c>>m;
		if(work()) printf("Case #%d:\n",t),pt();
		else printf("Case #%d:\nImpossible\n",t);
	}
	return 0;
}