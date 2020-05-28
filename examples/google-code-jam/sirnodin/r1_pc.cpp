/*=============================================================================
#     FileName: r1_pc.cpp
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-04-12 11:19:30
#   LastChange: 2014-04-12 14:37:58
#      History:
=============================================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;
const int MAX_RC=60;
size_t TEST_CASES;
int R,C,M;
char mboard[MAX_RC][MAX_RC];
int number;
int r_p[8]={-1,-1,-1,0,1,1,1,0};
int c_p[8]={-1,0,1,1,1,0,-1,-1};
struct Coor
{
    int r;
    int c;
    bool isValid()
    {
        return r>=0 && r<R && c>=0 && c<C;
    }
    list<Coor> validNeighbourList()
    {
        list<Coor> ret;
        Coor temp_r;
        for(int i=0;i<8;++i)
        {
            temp_r.r=r+r_p[i];
            temp_r.c=c+c_p[i];
            if(temp_r.isValid()) ret.push_back(temp_r);
        }
        return ret;
    }
};
vector<Coor> edge_coor_list;
bool dfs()
{
    int n=edge_coor_list.size();
    for(int i=0;i<n;++i)
    {
        Coor now_coor=edge_coor_list[i];
        if(mboard[now_coor.r][now_coor.c]=='.')
        {
            mboard[now_coor.r][now_coor.c]=0;
            int count=0;
            for(Coor coor:now_coor.validNeighbourList())
            {
                if(mboard[coor.r][coor.c]=='*')
                {
                    mboard[coor.r][coor.c]='.';
                    edge_coor_list.push_back(coor);
                    count++;
                    number++;
                }
            }
            if(number==M) return true;
            if(number<M) if(dfs()) return true;
            mboard[now_coor.r][now_coor.c]='.';
            for(int j=0;j<count;++j)
            {
                Coor & coor=edge_coor_list.back();
                mboard[coor.r][coor.c]='*';
                number--;
                edge_coor_list.pop_back();
            }
        }
    }
    return false;
}
bool solve()
{
    edge_coor_list.clear();
    number=0;
    Coor coor_s;
    if(number==M)
    {
        return true;
    }
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            coor_s.r=i;coor_s.c=j;
            edge_coor_list.push_back(coor_s);
            mboard[i][j]='.';
            number=1;
            if(number==M)
            {
                mboard[i][j]='c';
                return true;
            }
            if(dfs())
            {
                mboard[i][j]='c';
                return true;
            }
            edge_coor_list.pop_back();
            mboard[i][j]='*';
            number=0;
        }
    }
    return false;
}
int main()
{
    cin>>TEST_CASES;
    for(size_t CASE=0;CASE<TEST_CASES;++CASE)
    { 
        cin>>R>>C>>M;
        M=R*C-M;
        for(int i=0;i<R;++i)for(int j=0;j<C;++j) mboard[i][j]='*';
        printf("Case #%ld:\n",CASE+1);
        if(solve())
        {
            for(int i=0;i<R;++i)
            {
                for(int j=0;j<C;++j)
                {
                    if(mboard[i][j]!='*' && mboard[i][j]!='c')
                        cout<<'.';
                    else cout<<mboard[i][j];
                }
                cout<<endl;
            }
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
