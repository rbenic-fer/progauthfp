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

char A[5001][16];
char str[16][1000];
int l,d,n;

bool ok(char d[]){
	int i,j;
	for(i=0;d[i];i++){
		for(j=0;str[i][j];j++){
			if(d[i]==str[i][j]) break;
		}
		if(str[i][j]==0) return 0;
	}
	return 1;
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	while(scanf("%d%d%d",&l,&d,&n)!=EOF){
		int i,j,k;
		for(i=0;i<d;i++) scanf("%s",A[i]);
		char tmp[10000];
		for(i=0;i<n;i++){
			scanf("%s",tmp);
			int tt=0;
			for(j=0;tmp[j];j++){
				if(tmp[j]=='('){
					j++;
					int jj=0;
					while(tmp[j]!=')'){
						str[tt][jj++]=tmp[j];
						j++;
					}
					str[tt][jj]=0;
					tt++;
				}
				else{
					str[tt][0]=tmp[j];
					str[tt][1]=0;
					tt++;
				}
			}
			int ans=0;
			for(j=0;j<d;j++){
				//printf("%s\n",A[j]);
				if(ok(A[j])) ans++;
			}
			printf("Case #%d: %d\n",i+1,ans);
		}
	}
    return 0;
}
