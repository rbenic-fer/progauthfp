#include <cstdio>

using namespace std;

const int MAXN = 1000000;
int arr[MAXN], n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	long long int ls = 0, rs = 0;
	int l = 0, r = n - 1, sol = 0;
	for(int i = 0; i < n; i++) {
		if(ls < rs) {
			if(ls)
				sol++;
			ls += arr[l++];
		}
		else {
			if(rs)
				sol++;
			rs += arr[r--];
		}
		if(ls == rs)
			ls = rs = 0;
	}
	if(ls && rs)
		sol++;
	printf("%d\n", sol);
	return 0;
}
