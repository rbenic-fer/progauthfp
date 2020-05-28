
#include <stdio.h>
#include <string.h>

//char num[]="15159303447591735880024168312426282137993849705561417273129\0";
char num[110]="100040004\0";

char bits[500];

char sqrslt[110]="1\0";
char rem[110]="0\0";
char acc[110];

int count_decade[110];

int halve(char *s,int *zero) {
    int c=0;
    int z=0;
    while (*s) {
        c=c*10+ *s-48;
        z|=c;
        *s++ = 48+c/2;
        c &=1;
    }
    *zero=z;
    return c;
}

void dbl(char *s, int c) {
    int z=1;
    while ((z=(z && *s)) || c) {
        c+=2*(*s & 0xf);
        *s++ = 48 + c%10;
        c=c/10;
    }
    *s=0;
}

void addint(char *s, int c) {
    int z=1;
    while (c) {
        c+=(*s & 0xf);
        z=z && *s;
        *s++ = 48 + c % 10;
        c=c/10;
    }
    if (!z) *s=0;
}

int sub(char *s, char *m, int c) {
    int v;
    int z=1;
    while (*m || c) {
        v=-c;
        z=z && *s;
        if (*s) v+=*s - 48;
        if (*m) v-=*m++ -48;
        c=0;
        while (v<0) {v+=10;c++;}
        //printf("v%d c%d z%d\n",v,c,z);
        if ((v || c) && !z) return -1;
        *s++ = v+48;
    }
    if (!z) *s=0;
    return 1;
}

void reverse(char *s) {
    int i,j;
    char tmp;
    i=0;
    j=strlen(s)-1;
    while (i<j) {
        tmp=s[i];s[i]=s[j];s[j]=tmp;
        i++;j--;
    }
}

int zero(char *s) {
    while (*s=='0') s++;
    return !*s;
}


//int main(int argc, char **argv) {
char *mysqrt(char *s, int z_inc) {
    int z,b;
    char *bs=bits;
    strcpy(num,s);
    while (1) {
        b=halve(num,&z);
        if (z==0) break;
        b+=2*halve(num,&z);
        *bs++ =48+b;
    }
    *bs=0;
    //printf("bits=%s\n",bits);
    //printf("num=%s\n",num);
    *rem= *(--bs) - 1;
    rem[1]=0;
    sqrslt[0]='1';
    sqrslt[1]=0;
    while (--bs>=bits) {
        dbl(sqrslt,0);
        dbl(rem,0);
        dbl(rem,*bs-48);
        //printf("sq=%s\n",sqrslt);
        //printf("rem=%s\n",rem);
        strcpy(acc,rem);
        if (sub(acc,sqrslt,0)==1 && sub(acc,sqrslt,1)==1) {
            strcpy(rem,acc);
            addint(sqrslt,1);
            //printf("adj to sq=%s rem=%s\n",sqrslt,rem);
        }
    }
    if (z_inc==1 && !zero(rem)) addint(sqrslt,1);
    if (z_inc==2 /* && zero(rem) */) addint(sqrslt,1);
    reverse(sqrslt);
    //printf("%s\n",sqrslt);
    //*exact=zero(rem);
    return sqrslt;
}

int mainY() {
    char *s;
    //char a[]="992\0";
    //char b[]="543\0";
    //printf("s=%d\n",sub(a,b,0));
    //printf("%s\n",a);
    s=mysqrt("10000",1);
    printf("!!sq=%s\n",s);
    s=mysqrt("1000",1);
    printf("!!sq=%s\n",s);
    s=mysqrt("10",1);
    printf("!!sq=%s\n",s);
    return 0;
}


int dec_count(int d) {
    int c=0;
    int i;
    for (i=0;i<=d;i++) c+=count_decade[i];
    return c;
}

int gencmp1(char *s) {
    int c=0;
    if (strcmp("1",s)==-1) c++;
    if (strcmp("2",s)==-1) c++;
    if (strcmp("3",s)==-1) c++;
    return c;
}

int gencmp2(char *s) {
    int c=0;
    if (strcmp("11",s)==-1) c++;
    if (strcmp("22",s)==-1) c++;
    return c;
}

int gencmp3(char *s) {
    int c=0;
    if (strcmp("101",s)==-1) c++;
    if (strcmp("111",s)==-1) c++;
    if (strcmp("121",s)==-1) c++;
    if (strcmp("202",s)==-1) c++;
    if (strcmp("212",s)==-1) c++;
    return c;
}

int gencmpeven(char *s, int len) {
    static char b[110];
    int i;
    int c=0;
    int w,x,y,z;
    int m;
    for (i=0;i<len;i++) b[i]='0';
    b[len]=0;
    b[0]=b[len-1]='2';
    if (strcmp(b,s)==-1) c++;
    b[0]=b[len-1]='1';
    if (strcmp(b,s)==-1) c++;
    m=(len-2)/2;
    len--;
    for (w=1;w<=m;w++) {
        b[w]=b[len-w]='1';
        if (strcmp(b,s)==-1) c++;
        for (x=w+1;x<=m;x++) {
            b[x]=b[len-x]='1';
            if (strcmp(b,s)==-1) c++;
            for (y=x+1;y<=m;y++) {
                b[y]=b[len-y]='1';
                if (strcmp(b,s)==-1) c++;
                /*for (z=y+1;z<=m;z++) {
                    b[z]=b[len-z]='1';
                    if (strcmp(b,s)==-1) c++;
                
                    b[z]=b[len-z]='0';
                }*/
            
                b[y]=b[len-y]='0';
            }
        
            b[x]=b[len-x]='0';
        }
        b[w]=b[len-w]='0';
    }
    return c;
    
}

int mystrcmp(char *a, char *b) {
    int cmp=strcmp(a,b);
    printf("strcmp(%s %s)=%d\n",a,b,cmp);
    return cmp;
}

//#define strcmp mystrcmp

int gencmpodd(char *s, int len) {
    static char b[110];
    int i;
    int c=0;
    int w,x,y,z;
    int m,mid;
    mid=(len)/2;
    for (i=0;i<len;i++) b[i]='0';
    b[len]=0;
    b[0]=b[len-1]='2';
    if (strcmp(b,s)==-1) c++;
    b[mid]='1';
    if (strcmp(b,s)==-1) c++;
    b[mid]='0';
    b[0]=b[len-1]='1';
    if (strcmp(b,s)==-1) c++;
    b[mid]='1';
    if (strcmp(b,s)==-1) c++;
    b[mid]='2';
    if (strcmp(b,s)==-1) c++;
    b[mid]='0';
    m=(len-2)/2;
    len--;
    for (w=1;w<=m;w++) {
        b[w]=b[len-w]='1';
        b[mid]='0';
        if (strcmp(b,s)==-1) c++;
        b[mid]='1';
        if (strcmp(b,s)==-1) c++;
        b[mid]='2';
        if (strcmp(b,s)==-1) c++;
        for (x=w+1;x<=m;x++) {
            b[x]=b[len-x]='1';
            b[mid]='0';
            if (strcmp(b,s)==-1) c++;
            b[mid]='1';
            if (strcmp(b,s)==-1) c++;
            for (y=x+1;y<=m;y++) {
                b[y]=b[len-y]='1';
                b[mid]='0';
                if (strcmp(b,s)==-1) c++;
                b[mid]='1';
                if (strcmp(b,s)==-1) c++;
                /*for (z=y+1;z<=m;z++) {
                    b[z]=b[len-z]='1';
                    if (strcmp(b,s)==-1) c++;
                
                    b[z]=b[len-z]='0';
                }*/
            
                b[y]=b[len-y]='0';
            }
        
            b[x]=b[len-x]='0';
        }
        b[w]=b[len-w]='0';
    }
    return c;
    
}

//#undef strcmp


int gen_cmp(char *s) {
    int len;
    len=strlen(s);
    if (len==1) return gencmp1(s);
    else if (len==2) return gencmp2(s);
    else if (len==3) return gencmp3(s);
    else if (len & 1) return gencmpodd(s,len);
    else return gencmpeven(s,len);
}

void fair(void) {
    static char a[110];
    char *sq;
    int cnt1,cnt2;
    scanf("%s",a);
    sq=mysqrt(a,1);
    cnt1=dec_count(strlen(sq)-1);
    cnt1+=gen_cmp(sq);
    //printf("a=%s sq=%s cnt=%d\n",a,sq,cnt1);
    
    scanf("%s",a);
    sq=mysqrt(a,2);
    cnt2=dec_count(strlen(sq)-1);
    //printf("cnt2=%d\n",cnt2);
    cnt2+=gen_cmp(sq);
    //printf("b=%s sq=%s cnt=%d\n",a,sq,cnt2);
    
    printf("%d\n",cnt2-cnt1);
}

int comb(int i, int m) {
    int n=1,d=1,j;
    if (i>m) return 0;
    for (j=0;j<i;j++) {
        d*=(1+j);
        n*=(m-j);
    }
    return n/d;
}

void maketable(void) {
    int i,m,c;
    count_decade[1]=3;
    count_decade[2]=2;
    count_decade[3]=5;
    for (i=4;i<105;i++) {
        if (i & 1) {
            m=(i-3)/2;
            c=2+ /*comb(4,m)+ */ 2*(comb(3,m)+comb(2,m)+comb(1,m)+1)+m+1;
        } else {
            m=(i-2)/2;
            c=1+/*comb(4,m)+ */(comb(3,m)+comb(2,m)+comb(1,m)+1);
        }
        count_decade[i]=c;
        //if (i<10) printf("cd[%d]=%d\n",i,c);
    }
}

int main(int argc, char **argv) {
    int i,t;
    maketable();
    //return 0;
    scanf("%d",&t);
    for (i=1;i<=t;i++) {
        printf("Case #%d: ",i);
        fair();
    }
    return 0;
}