#include<stdio.h>
#include<string.h>


int getPointer(char *s,int start){

	int i;
	for(i=start;i>=0;i--){
		if(s[i]=='-') return i;
	}

	return i;	
}

void flip(char *s,int start,int finish){

	int i;
	for(i=start;i<=finish;i++) s[i] = (s[i]=='-')?'+':'-';
}


int main(){

	int n,i,j,k,add,index,len;
	

	char s[105];
	
	scanf("%d",&n);
	
	for(k=1;k<=n;k++){
	
		scanf("%s",s);
		
		len = strlen(s);
		add=0;	
		
		while(1){
			index = getPointer(s,len-1);
			if(index==-1) break;
			
			flip(s,0,index);
			add++;
		}
		
		printf("Case #%d: %d\n",k,add);
		
	}	
	
	return 0;

}
