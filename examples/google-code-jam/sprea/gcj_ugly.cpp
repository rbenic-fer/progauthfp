#include<stdio.h>
#include<string.h>

int res[45],used[45],ct,len;
char str[100];

void evaluate(){
	long long int val, temp;
	int i,j,prev;
	
	val = 0;
	temp = str[0]-'0';
	prev = 1;
	
	for(i=0;i<len-1; ++i){
		if(res[i]==0){
			temp*=10;
			temp += str[i+1] - '0';
		}
		else if(res[i] == 1){
			if(prev==1)
				val += temp;
			else val -= temp;
			prev = 1;
			temp = str[i+1] - '0';			
		}
		else {
			if(prev==1)
				val += temp;
			else val -= temp;
			prev = 2;
			temp = str[i+1] - '0';
		}
	}
	
	if(prev==1)
		val += temp;
	else val -= temp;
	
	temp = val;
	if(temp%2==0 || temp%3==0 || temp%5==0 || temp%7==0) ct++;
}
void backtrack(int k){
	if(k==len-1){
		evaluate();
		return ;
	}
	int i;
	for(i=0; i<3; ++i){
		res[k] = i;
		backtrack(k+1);
	}
}

int main(){
	int n,x;
	
	freopen("bsmall.in","r",stdin);
	freopen("bsmall.out","w",stdout);
	
	scanf("%d",&n);
	for(x=1; x<=n; ++x){
		scanf("%s",str);
		
		len = strlen(str);
		ct = 0;
		backtrack(0);
		
		printf("Case #%d: %d\n",x,ct);
	}
	
//	scanf(" ");
	return 0;
}
