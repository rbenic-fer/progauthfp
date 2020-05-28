/*=============================================================================
#     FileName: r1_pb.cpp
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-04-12 10:31:08
#   LastChange: 2014-04-12 10:53:18
#      History:
=============================================================================*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const size_t MAX_C=10000;
size_t TEST_CASES;
double C,F,X;
double ans;
double TIME_N[MAX_C];
int N;
double time_p;
int main()
{
    cin>>TEST_CASES;
    for(size_t CASE=0;CASE<TEST_CASES;++CASE)
    {
        for(size_t i=0;i<MAX_C;++i) TIME_N[i]=-1;
        cin>>C>>F>>X;
        time_p=0;
        ans=X*0.5;
        for(size_t i=1;i<MAX_C;++i)
        {
            time_p+=C/(2+(i-1)*F);
            double this_time=time_p+X/(i*F+2);
            if(this_time>=ans) break;
            ans=this_time;
        }
        printf("Case #%ld: %.7lf\n",CASE+1,ans);
    }
    return 0;
}
