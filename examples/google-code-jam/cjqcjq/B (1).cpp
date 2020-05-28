#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
typedef long long LL;
using namespace std;

const int N=101;

int A[N][N];
int H,W;
char D[N][N];
bool visit[N][N];
char cur;

char dfs(int x,int y,char val){
//	printf("x=%d,y=%d\n",x,y);
	int n,w,e,s;
	visit[x][y]=1;
	n=w=e=s=100000;
	if(x>0) n=A[x-1][y];
	if(x<H-1) s=A[x+1][y];
	if(y>0) w=A[x][y-1];
	if(y<W-1) e=A[x][y+1];
	int small=n;
	int dir=0;
	if(small>w){
		dir=1;
		small=w;
	}
	if(small>e){
		dir=2;
		small=e;
	}
	if(small>s){
		dir=3;
		small=s;
	}
	//printf("%d,%d\n",small,dir);
	char re;
	if(small>=A[x][y]){
		if(D[x][y]==0){
			cur++;
			D[x][y]=val;
		}
		re=D[x][y];
		return re;
	}
	if(dir==0) re=dfs(x-1,y,val);
	else if(dir==1) re=dfs(x,y-1,val);
	else if(dir==2) re=dfs(x,y+1,val);
	else re=dfs(x+1,y,val);
	D[x][y]=re;
	return re;
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int cas,ic;
	scanf("%d",&cas);
	for(ic=1;ic<=cas;ic++){
		int i,j;
		scanf("%d%d",&H,&W);
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				scanf("%d",&A[i][j]);
			}
		}
		cur='a';
		memset(visit,0,sizeof(visit));
		memset(D,0,sizeof(D));
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				if(!visit[i][j]){
					visit[i][j]=1;
					char t=dfs(i,j,cur);
				}
			}
		}
		printf("Case #%d:\n",ic);
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				printf("%c",D[i][j]);
				if(j<W-1) printf(" ");
			}
			printf("\n");
		}
	}
    return 0;
}
