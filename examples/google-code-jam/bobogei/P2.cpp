#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAX = 5;

int T;
char mp[MAX][MAX];

void aozora()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            mp[i][j]=0;
        }
    }
}

bool ok(int f)
{
    char bc;
    if(f<=2)
    {
        if(f==1)
        {
            bc='X';
        }else if(f==2)
        {
            bc='O';
        }
        bool ok;
        for(int i=0;i<4;i++)
        {
            ok=1;
            for(int j=0;j<4;j++)
            {
                if(mp[i][j]!=bc&&mp[i][j]!='T')
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                return 1;
            }
        }

        for(int i=0;i<4;i++)
        {
            ok=1;
            for(int j=0;j<4;j++)
            {
                if(mp[j][i]!=bc&&mp[j][i]!='T')
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                return 1;
            }
        }

        ok=1;
        for(int i=0;i<4;i++)
        {
            if(mp[i][i]!=bc&&mp[i][i]!='T')
            {
                ok=0;
                break;
            }
        }

        if(ok)
        {
            return 1;
        }

        ok=1;
        for(int i=0;i<4;i++)
        {
            if(mp[i][3-i]!=bc&&mp[i][3-i]!='T')
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            return 1;
        }
        return 0;
    }else
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(mp[i][j]=='.')
                {
                   // puts(mp[i]);
                    return 0;
                }
            }
        }
        return 1;
    }
}

int main()
{
    freopen("pa.in","r",stdin);
    freopen("pa.out","w",stdout);

    scanf("%d",&T);
    for(int ti=0;ti<T;ti++)
    {
        aozora();
        for(int i=0;i<4;i++)
        {
            scanf("%s",mp[i]);
        }
        printf("Case #%d: ",ti+1);
        if(ok(1))
        {
            puts("X won");
        }else if(ok(2))
        {
            puts("O won");
        }else if(ok(3))
        {
            puts("Draw");
        }else
        {
            puts("Game has not completed");
        }
    }

}
