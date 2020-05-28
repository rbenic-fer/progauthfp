#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

#define SIZE 1000009

LL gcd(LL a, LL b){
	if( b == 0) return a;
	return gcd(b, a%b);
}

char p[SIZE];
int prime[100000];
int cnt; 

void pgen(){
	LL i, j;
	cnt = 0;
	
	for( i = 2; i<SIZE; ++i){		
		if(p[i] == 0){
			prime[cnt++] = i;
			for( j = i*i; j<SIZE; j += i){
				p[j] = 1;
			}
		}
	}	
}

int main() {
	int T, cs, i;
	LL ret, temp, curcnt, N;
	
	pgen();
	
	freopen("/home/user/Desktop/C-large.in", "r", stdin);
	freopen("/home/user/Desktop/C-large.out", "w", stdout);
				
//	freopen("/home/user/Desktop/C-small-attempt0.in", "r", stdin);
//	freopen("/home/user/Desktop/C-small.out", "w", stdout);
	scanf("%d", &T);
	for( cs = 1; cs <=T; ++cs){
		cin>>N;		
		ret = 1;
		for(i=0; i < cnt &&  prime[i]*prime[i]<=N; ++i){
			temp = N;
			curcnt = 0;
			while(temp>=prime[i]){
				curcnt++;
			
				temp /= prime[i];
			}
			ret += (curcnt-1);
		}
		
		if( N == 1) ret--;
		
		printf("Case #%d: ", cs);
		cout << ret << endl;
	}
	                           
	return 0;
}
