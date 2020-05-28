#include <stdio.h>
#include <cstring>
#include <algorithm>
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    char s[23];
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        s[0] = '0';
        scanf("%s",s+1);
        int len = strlen(s);
        std::next_permutation(s,s+len);
        int i = 0;
        while (s[i]=='0'){
            i++;
        }
        printf("Case #%d: %s\n",t,s+i);
    }
    return 0;
}
