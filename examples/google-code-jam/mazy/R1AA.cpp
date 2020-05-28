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
#include <assert.h>     /* assert */


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
#define Sort(v) sort((v).begin(), (v).end())
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "A"

int count(int N)
{
    if (N <= 0) {
        return -1;
    }
    int n = N;
    bool r[10] = {false};
    while (true) {
        int x = n;
        while (x > 0) {
            r[x % 10] = true;
            x /= 10;
        }
        bool succ = true;
        rep(i, 10) {
            if (!r[i]) {
                succ = false;
                break;
            }
        }
        if (succ) {
            return n;
        }
        n += N;
    }
}

int main()
{
//	freopen(QX ".txt","r",stdin);
//	freopen(QX "-small-attempt0.in","r",stdin);freopen(QX "-small-attempt0.out","w",stdout);
//	freopen(QX "-small-attempt1.in","r",stdin);freopen(QX "-small-attempt1.out","w",stdout);
	freopen(QX "-large.in","r",stdin);freopen(QX "-large.out","w",stdout);
//	freopen(QX "-large-practice.in","r",stdin);freopen(QX "-large-practice.out","w",stdout);

    int T=0;
	scanf("%d",&T);

	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        int R,C;
        cin>>R>>C;
        bool done[256];
        cl(done,false);
        string S[25];
        rep(i,R) {
            cin>>S[i];
            assert(S[i].length() == C);
        }
        rep(i, R) {
            rep(j, C) {
                if (S[i][j] == '?' || done[S[i][j]]) continue;
                int up = i-1; // exclude
                while(up>=0 && S[up][j] == '?') up--;
                int left = j-1;
                while(left>=0) {
                    bool ok = true;
                    For(ii,up+1,i+1) {
                        if (S[ii][left] != '?') {
                            ok=false;
                            break;
                        }
                    }
                    if (!ok) break;
                    left--;
                }
                int right = j+1;
                while(right<C) {
                    bool ok = true;
                    For(ii,up+1,i+1) {
                        if (S[ii][right] != '?') {
                            ok=false;
                            break;
                        }
                    }
                    if (!ok) break;
                    right++;
                }
                int down=i+1;
                while(down<R) {
                    bool ok = true;
                    For(jj,left+1,right) {
                        if (S[down][jj] != '?') {
                            ok=false;
                            break;
                        }
                    }
                    if (!ok) break;
                    down++;
                }
                //cout<<S[i][j]<<","<<left<<","<<right<<","<<up<<","<<down<<endl;
                done[S[i][j]]=true;
                For(ii,up+1,down) {
                    For(jj,left+1,right) {
                        S[ii][jj] = S[i][j];
                    }
                }
            }
        }
        // output
        cout << "Case #"<<caseId<<":"<<endl;
        rep(i,R) {
            cout<<S[i]<<endl;
        }
        rep(i,R) {
            rep(j,C) {
                if (S[i][j] == '?') {
                    cout<<"Wrong!!"<<endl;
                }
            }
        }
	}
    return 0;
}
