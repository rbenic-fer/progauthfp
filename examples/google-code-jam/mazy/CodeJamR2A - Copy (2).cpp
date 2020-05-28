#include <iostream>
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
#define rep(i,b) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
const int oo=1000000;

int cc[100];


int main()
{
    //const char flnm_in[] = "input.txt";
    const char flnm_in[] = "A-small-attempt1.in";
    const char flnm_out[] = "A-small-1.out";
    //const char flnm_in[] = "A-large.in";
    //const char flnm_out[] = "A-large.out";
    char buf[1000];
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
        int n=0;
        i_file>>n;
        i_file.getline(buf, 1000);
        memset(cc,0,100);
        rep(i,n)
        {
            i_file.getline(buf, 1000);
		    for(int k=n-1;k>=0;k--)
            {
                if (buf[k]=='1')
                {
                    cc[i]=k+1;
                    break;
                }
            }
        }
        int count=0;
        rep(i,n)
        {
            For(j,i,n)
            {
                if (cc[j]<=i+1){
                    for(int k=j-1;k>=i;k--){
                        count++;
                        cc[k+1] = cc[k];
                    }
                    break;
                }
            }
        }
        cout << "Case #"<<caseId<<": "<<count<<"\n";
        o_file << "Case #"<<caseId<<": "<<count<<"\n";
	}

    i_file.close();
    o_file.close();
    return 0;
}