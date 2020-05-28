#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char str[10009],temp[10009];

int eval(char *str){
	int i,ct = 1;
	
	for(i = 1; str[i]; ++i){
		if(str[i] != str[i-1]) ct++;
	}
	
	return ct;
}
int main(){
	int n,k,i,j,x,p;
	int ans, len, tmp, res[10],ct;
	
	freopen("csm.in","r",stdin);
	freopen("csm.out","w",stdout);
	scanf("%d",&n);
	for(x=1; x<=n; ++x){
		scanf("%d%s",&p, str);

		ct = 0;
		len = strlen(str);
		ans = len;
		memset(res,0,sizeof(res));
		for(j=0; j<p;++j)res[j] = j;
		do{
			for(j=0; j<len; j+=p){
				for(k=0; k<p; ++k){
					temp[j+k] = str[j+res[k]];
				}
			}
			temp[len] = 0;
			tmp = eval(temp);
			if(tmp < ans) {
				ans = tmp;						
			}
			/*for(i=0; i<p ;++i){
				printf("%d ",res[i]);
			}puts("");
//			ct++;*/
		}
		while(next_permutation(res,res+p));


//		printf("%d\n",ct);
		printf("Case #%d: %d\n",x,ans);
	}
	
	scanf(" ");
	
	return 0;
}
