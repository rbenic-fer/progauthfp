#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A, B;
int buffer;
int a, b;

struct node {
       int s, e;
       int train;
};

vector<node> V;

bool cmp(const node &a, const node &b) {
     return a.s < b.s;
}

int main() {
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    int cases = 1;
    for( scanf("%d", &t); t--; ) {
         scanf("%d", &buffer);         
         scanf("%d %d", &a, &b);
         int i;
         V.clear();
         for(i=0;i<a;i++) {
           char str[100];
           scanf("%s", str);
           str[2] = ' ';
           int h, m;
           sscanf(str, "%d %d", &h, &m);
           int start = h*60 + m;
           
           scanf("%s", str);
           str[2] = ' ';
           sscanf(str, "%d %d", &h, &m);
           int end = h*60 + m;
           end += buffer;
           
           node nd;
           nd.s = start;
           nd.e = end;
           nd.train = 1;
           
           V.push_back(nd);
         }
         
         for(i=0;i<b;i++) {
           char str[100];
           scanf("%s", str);
           str[2] = ' ';
           int h, m;
           sscanf(str, "%d %d", &h, &m);
           int start = h*60 + m;
           
           scanf("%s", str);
           str[2] = ' ';
           sscanf(str, "%d %d", &h, &m);
           int end = h*60 + m;
           end += buffer;
           
           node nd;
           nd.s = start;
           nd.e = end;
           nd.train = 2;
           
           V.push_back(nd);
         }
         
         sort(V.begin(), V.end(), cmp);
         
         A.clear(); B.clear();
         int res[10] = {0};
         for(i=0;i<V.size();i++) {
           if( V[i].train == 1 ) {
             if( A.size() && A[0] <= V[i].s ) {
               A.erase( A.begin() ); 
             }
             else {
               res[1]++;
             }
             B.push_back(V[i].e);
             sort(B.begin(), B.end() );
           }
           else {
             if( B.size() && B[0] <= V[i].s ) {
               B.erase( B.begin() );
             }
             else {
               res[2]++;
             }
             A.push_back( V[i].e );
             sort(A.begin(), A.end() ) ;
           }
         }
         printf("Case #%d: %d %d\n", cases++, res[1], res[2]);
    }
    return 0;
}
