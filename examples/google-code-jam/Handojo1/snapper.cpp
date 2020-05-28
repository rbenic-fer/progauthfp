#include<iostream>
#include<cstring>

using namespace std;

int i,banyak,hasil,total;

int main()
{
    scanf("%d",&banyak);
    for (i=1;i<=banyak;i++)
    {
        scanf("%d %d",&total,&hasil);
        hasil %= (1<<total);

        if (hasil == (1<<total)-1) printf("Case #%d: ON\n",i);
        else printf("Case #%d: OFF\n",i);
    }
    return 0;
}
