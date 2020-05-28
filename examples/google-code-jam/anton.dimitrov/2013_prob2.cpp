#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char* INPUT_FILE = "D:\\Anton\\gcj_files\\B-small-attempt0.in";
char* OUTPUT_FILE = "D:\\Anton\\gcj_files\\prob2_out.txt";

int gt;
int n, m;
int matr[104][104];

bool check(int row, int col) {
	// check vertical
	bool isgood = true;
	for (int i = row-1; i >= 0 && isgood; i--) {
		if (matr[row][col] < matr[i][col]) isgood = false;
	}
	if (isgood) {
		for (int i = row+1; i < n && isgood; i++) {
			if (matr[row][col] < matr[i][col]) isgood = false;
		}
	}

	if (isgood) return true;

	isgood = true;
	for (int i = col-1; i >= 0 && isgood; i--) {
		if (matr[row][col] < matr[row][i]) isgood = false;
	}
	if (isgood) {
		for (int i = col+1; i < m && isgood; i++) {
			if (matr[row][col] < matr[row][i]) isgood = false;
		}
	}

	return isgood;
}

int main() {

	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);

	scanf("%d", &gt);

	for (int gi=1; gi <= gt; gi++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &matr[i][j]);
			}
		}

		bool isbad = false;
		for (int i = 0; i < n && !isbad; i++) {
			for (int j = 0; j < m && !isbad; j++) {
				if (!check(i, j)) {
					isbad = true;
					break;
				}
			}
		}

		if (isbad) {
			printf("Case #%d: NO\n", gi);
		} else {
			printf("Case #%d: YES\n", gi);
		}
	}

	return 0;
}
