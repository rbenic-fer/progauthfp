#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

int flag[20][26];

char dict[5009][30];
char str[1009];

int main(){
	int L, D, N;
	int i, j, cnt, x, ret;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	while(scanf("%d%d%d", &L, &D, &N) != EOF){
		for( i=0; i<D; ++i){
			scanf("%s", dict[i]);
		}

		for( x = 1; x<=N; ++x){
			scanf("%s", str);

			memset(flag, 0, sizeof(flag));

			for( i=cnt = 0; str[i]; ++i){
				if(str[i] == '('){
					for(j = i+1; str[j] != ')'; ++j){
						flag[cnt][str[j] - 'a'] = 1;
					}
					i = j;
				}
				else {
					flag[cnt][str[i] - 'a'] = 1;
				}
				cnt++;
			}

			ret = 0;
			for( i=0; i<D; ++i){				
				for(j =0; j<L; ++j){
					if(flag[ j ][ dict[i][j] - 'a' ] == 0)
						break;
				}
				if(j >= L) ret++;
			}

			printf("Case #%d: %d\n", x, ret);
		}
	}

	return 0;
}