#include <iostream> 
#include <cstdlib> 
using namespace std; 
#define MAXN 1002 
  
struct NODE{ 
   int a,b; 
}node[MAXN]; 
  
int N,outp; 
  
int compare(const void *a, const void *b){ 
   NODE *arg1 = (NODE*) a; 
   NODE *arg2 = (NODE*) b; 
   return arg1->a - arg2->a; 
} 
  
int main() { 
   int cas,cnt=0,lenmax,i,j; 
   freopen("A-small-attempt0.in", "r", stdin); 
   FILE *out; 
   out = fopen("output.txt", "w"); 
   scanf("%d", &cas); 
   while(cas--){ 
      scanf("%d", &N); 
      lenmax = 0; 
      outp = 0; 
      for(i = 0; i < N; ++i){ 
         scanf("%d%d", &node[i].a, &node[i].b); 
      } 
      qsort(node,N,sizeof(NODE),compare); 
      for(i = 0; i < N; ++i){ 
         for(j = i+1; j < N; ++j){ 
            if(node[j].b < node[i].b) 
               ++outp; 
         } 
      } 
      fprintf(out, "Case #%d: %d\n", ++cnt, outp); 
   } 
   fclose(out); 
   return 0; 
} 
