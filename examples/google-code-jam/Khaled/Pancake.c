#include<stdio.h>
#include<string.h>

#define MAX 1005

char s[MAX];


int getIndex(int len){

    int i;
    for(i=0;i<len;i++) if(s[i]=='-') return i;

    return i;
}


void flip(int index,int n,int len){

    //printf("index = %d,n=%d,len=%d\n",index,n,len);

    if(index+n>=len)
        index = len-n;

    for(int i=index;i<=index+n-1 && i<len;i++){
        if(s[i]=='-') s[i]='+';
        else s[i] = '-';
    }
}

int main(){

    int T,n,len,k=0;

    scanf("%d",&T);

    while(T--){

        scanf("%s%d",s,&n);
        len = strlen(s);
        int flag =0;
        int count = 0;
        while(1){



            int index = getIndex(len);

            //puts(s);

            if(index==len){
                printf("Case #%d: %d\n",++k,count);
                break;
            }

            if(len<n && index!=len){
                printf("Case #%d: IMPOSSIBLE\n",++k);
                break;
            }

            flip(index,n,len);

            if(index+n>=len){
                if(!flag) flag = !flag;
                else if(flag){

                    printf("Case #%d: IMPOSSIBLE\n",++k);
                    //puts(s);
                    break;
                }
            }

            count++;

        }
    }
    return 0;
}
