#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

#define MAX_T 100
#define LEN 16

long long BASE[9][LEN]=
{{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768},
{1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907},
{1,4,16,64,256,1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456,1073741824},
{1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125,6103515625,30517578125},
{1,6,36,216,1296,7776,46656,279936,1679616,10077696,60466176,362797056,2176782336,13060694016,78364164096,470184984576},
{1,7,49,343,2401,16807,117649,823543,5764801,40353607,282475249,1977326743,13841287201,96889010407,678223072849,4747561509943},
{1,8,64,512,4096,32768,262144,2097152,16777216,134217728,1073741824,8589934592,68719476736,549755813888,4398046511104,35184372088832},
{1,9,81,729,6561,59049,531441,4782969,43046721,387420489,3486784401,31381059609,282429536481,2541865828329,22876792454961,205891132094649},
{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000}};


long long FindDivisor(long long N,long long extra){
    for(long long i=2;i*i<N&&i<MAX_T;++i){
        long long add=1;
        for(int j=0;j<32;++j){
            add*=extra;
            add=extra%i;
        }
        if((N+add)%i==0) return i;
    }
    return 0;
}

long long CalcNumber(const string & num,int base){
    long long ret=0;
    int len=num.size();
    for(int i=0;i<len;++i){
        if(num[len-i-1]=='1'){
            ret+=BASE[base][i];
        }
    }
    return ret;
}

set<string> ans_set;

bool GenNumber(){
    string over(16,'0');
    string ans(16,'0');
    long long num;
    over[0]='1';
    //ans[0]='1';
    ans[LEN-1]='1';
    for(int i=0;i<LEN-1;++i){
        if(rand()%2==0){
            ans[i]='1';
        }else ans[i]='0';
    }
    if(ans_set.find(ans)==ans_set.end()){
        ans_set.insert(ans);
        vector<long long> divisor;
        for(int i=0;i<9;++i){
            long long extra=i+2;
            num=CalcNumber(ans,i);
            long long div=FindDivisor(num,extra);
            if(div==0) goto end;
            else divisor.push_back(div);
        }
        //cout<<ans<<" "<<num;
        cout<<over<<ans;
        for(int i=0;i<9;++i) cout<<" "<<divisor[i];
        cout<<endl;
        return true;
end:;
    }
    return false;
}

void InitBase(int max=LEN){
    for(int b=2;b<=10;++b){
        cout<<"{"<<1;
        long long out=1;
        for(int i=0;i<max-1;++i){
            out*=b;
            cout<<","<<out;
        }
        cout<<"},\n";
    }
}

int main(int argc, char const *argv[])
{
    srand( (unsigned)time( NULL ) );
    //cout<<rand()<<endl;
    //
    cout<<"Case #1:"<<endl;
    int N=0;
    while(N<500) N+=GenNumber()?1:0;

    /*test calc*/
    //string num;
    //while(cin>>num){
        //for(int i=0;i<9;++i){
            //cout<<CalcNumber(num,i)<<endl;
        //}
    //}

    return 0;
}
