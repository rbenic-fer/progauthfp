#include<stdio.h>
char s[101]="yhesocvxduiglbkrztnwjpfmaq";
main(){
	int T;
	char c;
	scanf("%d%*c",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		while(c=getchar()){
			if(c=='\n')break;
			if(c==' '){
				putchar(' ');
			} else { 
				putchar(s[c-'a']);
			}
		}
		putchar('\n');
	}
}
