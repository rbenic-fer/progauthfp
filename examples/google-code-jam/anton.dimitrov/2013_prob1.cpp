#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char* INPUT_FILE = "D:\\Anton\\gcj_files\\A-small-attempt0.in";
char* OUTPUT_FILE = "D:\\Anton\\gcj_files\\prob1_out.txt";
int gt;
char map[4][5];

char check_seq(char seq[4]) {
	int cntx = 0;
	int cnto = 0;
	int cntt = 0;
	for (int i = 0; i < 4; i++) {
		if (seq[i] == 'O') {
			cnto++;
			if (cntx > 0) return '.';
		}
		if (seq[i] == 'X') {
			cntx++;
			if (cnto) return '.';
		}
		if (seq[i] == 'T') {
			cntt++;
		}
	}
	if (cnto + cntt == 4) return 'O';
	if (cntx + cntt == 4) return 'X';
	return '.';
}

int main() {

	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);

	scanf("%d", &gt);

	char tmp_seq[4];

	for (int gi=1; gi <= gt; gi++) {
		for (int i = 0; i < 4; i++) {
			scanf(" %s ", map[i]);
		}

		printf("Case #%d: ", gi);
		bool done = false;

		for (int i = 0; i < 4; i++) {
			// row
			for (int j = 0; j < 4; j++) {
				tmp_seq[j] = map[i][j];
			}
			char res = check_seq(tmp_seq);
			if (res != '.') {
				printf("%c won\n", res);
				done = true;
				break;
			}

			// column
			for (int j = 0; j < 4; j++) {
				tmp_seq[j] = map[j][i];
			}

			res = check_seq(tmp_seq);
			if (res != '.') {
				printf("%c won\n", res);
				done = true;
				break;
			}

			// main diagonal
			for (int j = 0; j < 4; j++) {
				tmp_seq[j] = map[j][j];
			}

			res = check_seq(tmp_seq);
			if (res != '.') {
				printf("%c won\n", res);
				done = true;
				break;
			}

			// second diagonal
			for (int j = 0; j < 4; j++) {
				tmp_seq[j] = map[j][3-j];
			}

			res = check_seq(tmp_seq);
			if (res != '.') {
				printf("%c won\n", res);
				done = true;
				break;
			}
		}

		for (int i = 0; i < 4 && !done; i++) {
			for (int j = 0; j < 4 && !done; j++) {
				if (map[i][j] == '.') {
					printf("Game has not completed\n");
					done = true;
				}
			}
		}

		if (!done) {
			printf("Draw\n");
		}
	}

	return 0;
}
