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
#include <math.h>
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
#define Sort(v) sort((v).begin(), (v).end())
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "B"

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
        int N,P;
        cin>>N>>P;
        double R[50];
        rep(i,N) {
            cin>>R[i];
        }
        vector<int> Q[50];
        rep(i,N) {
            rep(j,P) {
                int Qij;
                cin>>Qij;
                Q[i].push_back(Qij);
            }
        }
        rep(i,N) {
            sort(Q[i].begin(), Q[i].end());
        }
        vector<pair<int,int> > Rg[50];
        bool bad = false;
        rep(i,N) {
            rep(j,P) {
                int q = Q[i][j];
                double base = (double) q / R[i];
                int r1 = (int) ceil(base / 1.1 - 1e-7);
                int r2 = (int) floor(base / 0.9 + 1e-7);
                if (r1>r2) continue;
                Rg[i].push_back(make_pair(r1,r2));
                //cout<<r1<<","<<r2<<endl;
            }
            if (Rg[i].size() == 0) {
                bad = true;
                break;
            }
        }
        int ans = 0;
        if (!bad) {
            int ind[50];
            cl(ind,0);
            while(true) {
                int rg1 = Rg[0][ind[0]].first, rg2 = Rg[0][ind[0]].second;
                int minn = rg1;
                rep(i,N) {
                    rg1 = max(Rg[i][ind[i]].first, rg1);
                    rg2 = min(Rg[i][ind[i]].second, rg2);
                }
                if (rg1 > rg2) {
                    bool done = false;
                    rep(i,N) {
                        if (Rg[i][ind[i]].second < rg1) {
                            ind[i]++;
                            if (ind[i] >= Rg[i].size()) {
                                done = true;
                                break;
                            }
                        }
                    }
                    if (done) break;
                } else {
                    bool done = false;
                    ans++;
                    rep(i,N) {
                        ind[i]++;
                        if (ind[i] >= Rg[i].size()) {
                            done = true;
                            break;
                        }
                    }
                    if (done) break;
                }
            }
        }

        // output
        cout << "Case #"<<caseId<<": "<<ans<<endl;
        //printf("Case #%d: %.8f\n",caseId,t);
	}
    return 0;
}
