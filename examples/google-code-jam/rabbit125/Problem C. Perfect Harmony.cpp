#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std ;
#define MAXN 10010
int N, L, M;
int n[MAXN];


int main()
{
	int cases;
	int casenum = 1;
	freopen("test.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &cases);
	while(cases--)
	{
	    memset(n, 0, sizeof(n));
	    scanf("%d%d%d", &N, &L, &M);
	    for(int i = 0;i < N; i++){
	        scanf("%d", &n[i]);
	    }
	
	    bool isok = false;
	    int ans;
	    for(int i = L;i <= M; i++){
	        bool i_isok = true;
	        for(int j = 0;j < N; j++){
	            int b = (i > n[j]) ? (i) : (n[j]);
	            int s = (i < n[j]) ? (i) : (n[j]);
	
	            if((b % s) != 0){
	                i_isok = false;
	                break;
	            }
	        }
	        if(i_isok){
	            ans = i;
	            isok = true;
	            break;
	        }
	    }
	if(isok)
	        printf("Case #%d: %d\n", casenum++, ans);
	    else
	        printf("Case #%d: NO\n", casenum++);
	
	}
}
