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
typedef map<string, int> simp;
#define sz(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define rep(i,b) for(int i=0;i<b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
template<class T> inline void Swap(T &a,T &b){T c=a;a=b;b=c;}
const int oo=1000000;

#pragma warning(disable:4996)


int k,n;
char V[60][60];

bool checkLine(char ch)
{
    rep(i,n){
        int c=0;
        rep(j,n){
            if (V[i][j] == ch){
                c++;
                if (c==k)
                    return true;
            } else{c=0;}
        }
    }
    return false;
}

bool checkRow(char ch)
{
    rep(i,n){
        int c=0;
        rep(j,n){
            if (V[j][i] == ch){
                c++;
                if (c==k)
                    return true;
            } else{c=0;}
        }
    }
    return false;
}

bool checkDia(char ch)
{
    rep(i,n){
        int c=0;
        rep(j,i+1){
            if (V[i-j][j] == ch){
                c++;
                if (c==k)
                    return true;
            } else{c=0;}
        }
    }

    rep(i,n){
        int c=0;
        rep(j,i+1){
            if (V[n-1-i+j][n-1-j] == ch){
                c++;
                if (c==k)
                    return true;
            } else{c=0;}
        }
    }

    return false;
}

bool checkDia2(char ch)
{
    rep(i,n){
        int c=0;
        rep(j,i+1){
            if (V[i-j][n-1-j] == ch){
                c++;
                if (c==k)
                    return true;
            } else{c=0;}
        }
    }

    rep(i,n){
        int c=0;
        rep(j,i+1){
            if (V[n-1-i+j][j] == ch){
                c++;
                if (c==k)
                    return true;
            } else{c=0;}
        }
    }

    return false;
}

int main()
{

    //const char flnm[] = "test";
    //const char flnm[] = "A-small-attempt1";
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
        // input
        i_file>>n>>k;
        rep(i,n){
            rep(j,n){
                i_file>>V[i][j];
            }
        }

        rep(i,n){
            int p=n-1;
            for(int j = n-1;j>=0;j--){
                if (V[i][j] !='.') {
                    Swap(V[i][j], V[i][p]);
                    p--;
                } else {
                }
            }
        }


        // output
        /*
        */
        char buf[100];
        bool rr=checkLine('R') || checkRow('R') || checkDia('R') || checkDia2('R');
        bool bb=checkLine('B') || checkRow('B') || checkDia('B') || checkDia2('B');
        if (rr&&bb)
            strcpy(buf,"Both");
        else if (rr&&!bb)
            strcpy(buf,"Red");
        else if (!rr&&bb)
            strcpy(buf,"Blue");
        else
            strcpy(buf,"Neither");
        //cout << "Case #"<<caseId<<": "<<buf<<"\n";
        o_file << "Case #"<<caseId<<": "<<buf<<"\n";
	}
    i_file.close();
    o_file.flush();
    o_file.close();
    return 0;
}