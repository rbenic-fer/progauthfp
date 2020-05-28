#include <cstdio>
using namespace std;

const int LEAF = 2;
const int AND = 1;
const int OR = 0;

const int max_m = 10000;

int types[max_m];
bool chang[max_m];
int values[max_m];
int M;

int value(int gat_id) {
	return (types[gat_id]==AND)
				?values[2*gat_id+1]&&values[2*gat_id+2]
				:values[2*gat_id+1]||values[2*gat_id+2];
}

int solve(int node, int value);

int checkOR(int node, int value) {
	if (value==1) {
		int res1 = solve(2*node+1, 1),
			res2 = solve(2*node+2, 1);
		if (res1 < 0 && res2 >= 0) return res2;
		if (res2 < 0 && res1 >= 0) return res1;
		return res1<res2?res1:res2;
	} else {
		int res1 = solve(2*node+1, 0),
			res2 = solve(2*node+2, 0);
		if (res1<0 || res2<0) return -1;
		return res1+res2;
	}
}

int checkAND(int node, int value) {
	if (value == 1) {
		int res1 = solve(2*node+1, 1), 
			res2 = solve(2*node+2, 1);			
		if (res1<0 || res2<0) return -1;
		return res1+res2;
	} else {		//value = 0
		int res1 = solve(2*node+1, 0),
			res2 = solve(2*node+2, 0);
		if (res1 < 0 && res2 >= 0) return res2;
		if (res2 < 0 && res1 >=0 ) return res1;
		return res1<res2?res1:res2;
	}			
}

template<typename T> T min(T a, T b) {return (a<b?a:b);}

int solve(int node, int value) {
	if (values[node] == value) return 0;	
	if (types[node] == LEAF) return -1;	//leaf - cannot change its value

	if (chang[node]) {
		if (types[node] == AND && value==1 && (values[2*node+1]==1 || values[2*node+2]==1)) return 1; 
		if (types[node] == OR && value==0 && (values[2*node+1]==0 || values[2*node+2]==0)) return 1;
		int resA = checkAND(node, value);
		int resO = checkOR(node, value);
		int res = 1000000;
		if (resO >=0) res = min(res, resO+(types[node]!=OR));
		if (resA >=0) res = min(res, resA+(types[node]!=AND));
		return res!=1000000?res:-1;
	} else {
		if (types[node]==AND) {
			return checkAND(node, value);
		} else {		//types[node] == OR
			return checkOR(node, value);
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for(int n=1; n<=N; n++) {
		int V;
		scanf("%d%d", &M, &V);
		for (int i=0; i<(M-1)/2; i++) {			
			scanf("%d%d", &types[i], &chang[i]);
		}
		for (int i=(M-1)/2; i<M; i++) {
			scanf("%d", &values[i]);
			types[i] = LEAF;
		}
		// calculate values
		for (int i=(M-1)/2-1; i>=0; i--) {
			values[i] = value(i);
		}
		int res = solve(0, V);		
		if (res != -1)
			printf("Case #%d: %d\n", n, res);
		else
			printf("Case #%d: IMPOSSIBLE\n", n);
	}
	return 0;
}