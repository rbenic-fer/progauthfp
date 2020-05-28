#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef long long ll;
const double pi=acos(-1.0);
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define sz(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define rep(i,b) for(int i=0;i<b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
const int oo=1000000;

int x[100];
int y[100];
double r[100];

double dis(int i,int j)
{
    double xx = (double)(x[i]-x[j]);
    double yy = (double)(y[i]-y[j]);
    return sqrt(sqr(xx)+sqr(yy));
}

int main()
{
    //const char flnm_in[] = "input.txt";
    //const char flnm_out[] = "out.txt";
    const char flnm_in[] = "D-small-attempt1.in";
    const char flnm_out[] = "D-small-1.out";
    //const char flnm_in[] = "D-large.in";
    //const char flnm_out[] = "D-large.out";
    ifstream i_file;
    i_file.open(flnm_in);
    ofstream o_file;
    o_file.open(flnm_out);
    if (!i_file.is_open())
        return 0;
    if (!o_file.is_open())
        return 0;
    int T=0;
    i_file>>T;
	for (int caseId=1;caseId<=T;caseId++)
	{
        int n;
        i_file>>n;
        rep(i,n){
            i_file>>x[i]>>y[i]>>r[i];
        }
        double mmm=10000000;
        if (n==1)
            mmm=r[0];
        else if (n==2)
            mmm=max(r[0],r[1]);
        else if (n==3){
            rep(i,n){
                For(j,i+1,n){
                    checkmin(mmm,max((dis(i,j)+r[i]+r[j])/2,r[3-i-j]));
                }
            }
        }

        cout << "Case #"<<caseId<<": "<<mmm<<"\n";
        o_file << "Case #"<<caseId<<": "<<mmm<<"\n";
	}
    i_file.close();
    o_file.close();
    return 0;
}