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
template<class T> inline void Swap(T &a,T &b){T c=a;a=b;b=c;}
const int oo=1000000;

#pragma warning(disable:4996)


int main()
{
    //const char flnm[] = "test";
    //const char flnm[] = "A-small-attempt0";
    const char flnm[] = "A-large";
    char flnm_in[255];
    char flnm_out[255];
    strcpy(flnm_in, flnm);
    strcat(flnm_in, ".in");
    strcpy(flnm_out, flnm);
    strcat(flnm_out, ".out");
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
        int n,k;
        i_file>>n>>k;
        bool on = false;
        int base = 1 << n;
        k++;
        if (k%base==0)
            on = true;
        char buf[100];
        if (on)
            strcpy(buf,"ON");
        else
            strcpy(buf,"OFF");
        //sprintf(buf,"%.8f",mmm);
        //cout << "Case #"<<caseId<<": "<<buf<<"\n";
        o_file << "Case #"<<caseId<<": "<<buf<<"\n";
	}
    i_file.close();
    o_file.flush();
    o_file.close();
    return 0;
}