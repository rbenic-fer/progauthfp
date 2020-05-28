#include <stdio.h>
#include <stdlib.h>

void readline()
{
	while(getchar()!='\n')
		;
}

int main()
{
	int T,tcase;
	char ch,map[]="yhesocvxduiglbkrztnwjpfmaq";

	scanf("%d",&T);
	readline();
	for(tcase=1;tcase<=T;tcase++)
	{
		printf("Case #%d: ",tcase);
		do
		{
			ch=getchar();
			if(ch>='a' && ch<='z')
				putchar(map[ch-'a']);
			else
				putchar(ch);
		}
		while(ch!='\n');
	}
	return 0;
}
