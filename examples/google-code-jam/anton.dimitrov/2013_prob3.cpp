#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char* INPUT_FILE = "D:\\Anton\\gcj_files\\C-large-1.in";
char* OUTPUT_FILE = "D:\\Anton\\gcj_files\\prob3_out.txt";

int gt;

bool is_palin(long long num) {
	long long max_dec = 1;
	while (max_dec * 10 <= num) {
		max_dec *= 10;
	}

	while (max_dec >= 10) {
		long long left = num / max_dec;
		num = num % max_dec;
		long long right = num % 10;
		if (left != right) return false;
		num /= 10;
		max_dec /= 100;
	}

	return true;
}

long long make_palin(int num, bool use_center) {
	int res = num;
	if (use_center) {
		num /= 10;
	}

	while (num > 0) {
		res *= 10;
		res += num % 10;
		num /= 10;
	}

	return res;
}

// Pretty lame solution, but should work for the two easier cases.
int main() {

	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);

	scanf("%d", &gt);

	long long a, b;
	long long cnt = 0;

	for (int gi=1; gi <= gt; gi++) {
		cnt = 0;
		scanf("%lld %lld", &a, &b);
		for (long long i = 1; i <= 1e4; i++) {
			int tmp = make_palin(i, false);
			long long sqnum = tmp * tmp;
			if (sqnum >= a && sqnum <= b && is_palin(sqnum)) {
				cnt++;
				//printf("%lld - %lld\n", i, sqnum);
			}
			tmp = make_palin(i, true);
			sqnum = tmp * tmp;
			if (sqnum >= a && sqnum <= b && is_palin(sqnum)) {
				cnt++;
				//printf("%lld - %lld\n", i, sqnum);
			}
		}

		printf("Case #%d: %lld\n", gi, cnt);
	}

	return 0;
}
