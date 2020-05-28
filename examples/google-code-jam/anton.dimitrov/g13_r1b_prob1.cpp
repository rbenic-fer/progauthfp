#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char* INPUT_FILE = "D:\\Anton\\gcj_files\\A-large (1).in";
char* OUTPUT_FILE = "D:\\Anton\\gcj_files\\r1b_p1_out.txt";

int gt;
int a, n;
vector<long long> arr;

int main() {

	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);

	scanf("%d", &gt);

	for (int gi=1; gi <= gt; gi++) {
		scanf("%d %d", &a, &n);
		arr.clear();
		for (int i = 0; i < n; i++) {
			long long tmp;
			scanf("%lld", &tmp);
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		int ans = n;
		long long curr = a;
		int moves = 0;
		for (int i = 0; i < n; i++) {
			ans = min(ans, moves + n - i);

			if (curr > arr[i]) {
				curr += arr[i];
			}
			else {
				if (curr == 1) {
					moves = n;
					break;
				}
				while(curr <= arr[i]) {
					curr = 2 * curr - 1;
					moves++;
				}
				curr += arr[i];
			}
		}
		ans = min(ans, moves);
		printf("Case #%d: %d\n", gi, ans);
	}

	return 0;
}
